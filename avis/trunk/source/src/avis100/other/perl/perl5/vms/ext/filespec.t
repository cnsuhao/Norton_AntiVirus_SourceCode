#!./perl

BEGIN { unshift(@INC,'../lib') if -d '../lib'; }

use VMS::Filespec;

foreach (<DATA>) {
  chomp;
  s/\s*#.*//;
  next if /^\s*$/;
  push(@tests,$_);
}
print '1..',scalar(@tests)+3,"\n";

foreach $test (@tests) {
  ($arg,$func,$expect) = split(/\t+/,$test);
  $idx++;
  $rslt = eval "$func('$arg')";
  if ($@) { print "not ok $idx  : eval error: $@\n"; next; }
  else {
    if ($rslt ne $expect) {
      print "not ok $idx  : $func('$arg') expected |$expect|, got |$rslt|\n";
    }
    else { print "ok $idx\n"; }
  }
}

if (rmsexpand('[]') eq "\U$ENV{DEFAULT}") { print 'ok ',++$idx,"\n"; }
else {
  print 'not ok ', ++$idx, ": rmsexpand('[]') = |", rmsexpand('[]'),
        "|, \$ENV{DEFAULT} = |\U$ENV{DEFAULT}|\n";
  print "# Note: This failure may have occurred because your default device\n";
  print "# was set using a non-concealed logical name.  If this is the case,\n";
  print "# you will need to determine by inspection that the two resultant\n";
  print "# file specifications shwn above are in fact equivalent.\n";
}
if (rmsexpand('from.here') eq "\L$ENV{DEFAULT}from.here") {
   print 'ok ', ++$idx, "\n";
}
else {
  print 'not ok ', ++$idx, ": rmsexpand('from.here') = |",
        rmsexpand('from.here'),
        "|, \$ENV{DEFAULT}from.here = |\L$ENV{DEFAULT}from.here|\n";
  print "# Note: This failure may have occurred because your default device\n";
  print "# was set using a non-concealed logical name.  If this is the case,\n";
  print "# you will need to determine by inspection that the two resultant\n";
  print "# file specifications shwn above are in fact equivalent.\n";
}
if (rmsexpand('from.here','cant:[get.there];2') eq
    'cant:[get.there]from.here;2')                 { print 'ok ',++$idx,"\n"; }
else {
  print 'not ok ', ++$idx, ': expected |cant:[get.there]from.here;2|, got |',
        rmsexpand('from.here','cant:[get.there];2'),"|\n";
}

__DATA__

# Basic VMS to Unix filespecs
some:[where.over]the.rainbow	unixify	/some/where/over/the.rainbow
[.some.where.over]the.rainbow	unixify	some/where/over/the.rainbow
[-.some.where.over]the.rainbow	unixify	../some/where/over/the.rainbow
[.some.--.where.over]the.rainbow	unixify	some/../../where/over/the.rainbow
[.some...where.over]the.rainbow	unixify	some/.../where/over/the.rainbow
[...some.where.over]the.rainbow	unixify	.../some/where/over/the.rainbow
[.some.where.over...]the.rainbow	unixify	some/where/over/.../the.rainbow
[.some.where.over...]	unixify	some/where/over/.../
[.some.where.over.-]	unixify	some/where/over/../
[]	unixify		./
[-]	unixify		../
[--]	unixify		../../
[...]	unixify		.../

# and back again
/some/where/over/the.rainbow	vmsify	some:[where.over]the.rainbow
some/where/over/the.rainbow	vmsify	[.some.where.over]the.rainbow
../some/where/over/the.rainbow	vmsify	[-.some.where.over]the.rainbow
some/../../where/over/the.rainbow	vmsify	[-.where.over]the.rainbow
.../some/where/over/the.rainbow	vmsify	[...some.where.over]the.rainbow
some/.../where/over/the.rainbow	vmsify	[.some...where.over]the.rainbow
/some/.../where/over/the.rainbow	vmsify	some:[...where.over]the.rainbow
some/where/...	vmsify	[.some.where...]
/where/...	vmsify	where:[...]
.	vmsify	[]
..	vmsify	[-]
../..	vmsify	[--]
.../	vmsify	[...]

# Fileifying directory specs
down:[the.garden.path]	fileify	down:[the.garden]path.dir;1
[.down.the.garden.path]	fileify	[.down.the.garden]path.dir;1
/down/the/garden/path	fileify	/down/the/garden/path.dir;1
/down/the/garden/path/	fileify	/down/the/garden/path.dir;1
down/the/garden/path	fileify	down/the/garden/path.dir;1
down:[the.garden]path	fileify	down:[the.garden]path.dir;1
down:[the.garden]path.	fileify	# N.B. trailing . ==> null type
down:[the]garden.path	fileify	
/down/the/garden/path.	fileify	# N.B. trailing . ==> null type
/down/the/garden.path	fileify	

# and pathifying them
down:[the.garden]path.dir;1	pathify	down:[the.garden.path]
[.down.the.garden]path.dir	pathify	[.down.the.garden.path]
/down/the/garden/path.dir	pathify	/down/the/garden/path/
down/the/garden/path.dir	pathify	down/the/garden/path/
down:[the.garden]path	pathify	down:[the.garden.path]
down:[the.garden]path.	pathify	# N.B. trailing . ==> null type
down:[the]garden.path	pathify	
/down/the/garden/path.	pathify	# N.B. trailing . ==> null type
/down/the/garden.path	pathify	
down:[the.garden]path.dir;2	pathify	#N.B. ;2
path	pathify	path/
/down/the/garden/.	pathify	/down/the/garden/./
/down/the/garden/..	pathify	/down/the/garden/../
/down/the/garden/...	pathify	/down/the/garden/.../
path.notdir	pathify	

# Both VMS/Unix and file/path conversions
down:[the.garden]path.dir;1	unixpath	/down/the/garden/path/
/down/the/garden/path	vmspath	down:[the.garden.path]
down:[the.garden.path]	unixpath	/down/the/garden/path/
down:[the.garden.path...]	unixpath	/down/the/garden/path/.../
/down/the/garden/path.dir	vmspath	down:[the.garden.path]
[.down.the.garden]path.dir	unixpath	down/the/garden/path/
down/the/garden/path	vmspath	[.down.the.garden.path]
path	vmspath	[.path]

# Redundant characters in Unix paths
//some/where//over/../the.rainbow	vmsify	some:[where]the.rainbow
/some/where//over/./the.rainbow	vmsify	some:[where.over]the.rainbow
..//../	vmspath	[--]
./././	vmspath	[]
./../.	vmsify	[-]

