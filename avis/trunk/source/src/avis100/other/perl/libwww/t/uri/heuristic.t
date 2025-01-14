print "1..14\n";

use URI::Heuristic qw(uf_urlstr uf_url);
$URI::Heuristic::DEBUG++;
open(STDERR, ">&STDOUT");  # redirect STDERR

print "not " unless uf_urlstr("http://www.sn.no/") eq "http://www.sn.no/";
print "ok 1\n";

print "not " unless uf_urlstr("/etc/passwd") eq "file:/etc/passwd";
print "ok 2\n";

print "not " unless uf_urlstr("./foo.txt") eq "file:./foo.txt";
print "ok 3\n";

print "not " unless uf_urlstr("ftp.aas.no/lwp.tar.gz") eq "ftp://ftp.aas.no/lwp.tar.gz";
print "ok 4\n";

print "not " unless uf_urlstr("C:\\CONFIG.SYS") eq "file:C:\\CONFIG.SYS";
print "ok 5\n";

if (gethostbyname("www.netscape.com")) {
    # DNS probably work, lets run test 6..8

    $URI::Heuristic::MY_COUNTRY = "no";
    print "not " unless uf_urlstr("perl/camel.gif") eq "http://www.perl.com/camel.gif";
    print "ok 6\n";

    $URI::Heuristic::MY_COUNTRY = "uk";
    print "not " unless uf_urlstr("perl/camel.gif") eq "http://www.perl.co.uk/camel.gif";
    print "ok 7\n";
   
    $ENV{URL_GUESS_PATTERN} = "www.ACME.org www.ACME.com";
    print "not " unless uf_urlstr("perl") eq "http://www.perl.org";
    print "ok 8\n";

} else {
    # don't make the inocent worry
    print "Skipping test 6-8 because DNS does not work\n";
    for (6..8) { print "ok $_\n"; }

}

$ENV{URL_GUESS_PATTERN} = "";
print "not " unless uf_urlstr("perl") eq "http://perl";
print "ok 9\n";

print "not " unless uf_urlstr("http:80") eq "http:80";
print "ok 10\n";

print "not " unless uf_urlstr("mailto:gisle\@aas.no") eq "mailto:gisle\@aas.no";
print "ok 11\n";

print "not " unless uf_urlstr("gisle\@aas.no") eq "mailto:gisle\@aas.no";
print "ok 12\n";

print "not " unless uf_urlstr("Gisle.Aas\@aas.perl.org") eq "mailto:Gisle.Aas\@aas.perl.org";
print "ok 13\n";

print "not " unless uf_url("gopher.sn.no")->scheme eq "gopher";
print "ok 14\n";
