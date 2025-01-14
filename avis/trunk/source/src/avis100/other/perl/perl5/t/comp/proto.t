#!./perl
#
# Contributed by Graham Barr <Graham.Barr@tiuk.ti.com>
#
# So far there are tests for the following prototypes.
# none, () ($) ($@) ($%) ($;$) (&) (&\@) (&@) (%) (\%) (\@)
#
# It is impossible to test every prototype that can be specified, but
# we should test as many as we can.
#

BEGIN {
    chdir 't' if -d 't';
    @INC = '../lib';
}

use strict;

print "1..76\n";

my $i = 1;

sub testing (&$) {
    my $p = prototype(shift);
    my $c = shift;
    my $what = defined $c ? '(' . $p . ')' : 'no prototype';   
    print '#' x 25,"\n";
    print '# Testing ',$what,"\n";
    print '#' x 25,"\n";
    print "not "
	if((defined($p) && defined($c) && $p ne $c)
	   || (defined($p) != defined($c)));
    printf "ok %d\n",$i++;
}

@_ = qw(a b c d);
my @array;
my %hash;

##
##
##

testing \&no_proto, undef;

sub no_proto {
    print "# \@_ = (",join(",",@_),")\n";
    scalar(@_)
}

print "not " unless 0 == no_proto();
printf "ok %d\n",$i++;

print "not " unless 1 == no_proto(5);
printf "ok %d\n",$i++;

print "not " unless 4 == &no_proto;
printf "ok %d\n",$i++;

print "not " unless 1 == no_proto +6;
printf "ok %d\n",$i++;

print "not " unless 4 == no_proto(@_);
printf "ok %d\n",$i++;

##
##
##


testing \&no_args, '';

sub no_args () {
    print "# \@_ = (",join(",",@_),")\n";
    scalar(@_)
}

print "not " unless 0 == no_args();
printf "ok %d\n",$i++;

print "not " unless 0 == no_args;
printf "ok %d\n",$i++;

print "not " unless 5 == no_args +5;
printf "ok %d\n",$i++;

print "not " unless 4 == &no_args;
printf "ok %d\n",$i++;

print "not " unless 2 == &no_args(1,2);
printf "ok %d\n",$i++;

eval "no_args(1)";
print "not " unless $@;
printf "ok %d\n",$i++;

##
##
##

testing \&one_args, '$';

sub one_args ($) {
    print "# \@_ = (",join(",",@_),")\n";
    scalar(@_)
}

print "not " unless 1 == one_args(1);
printf "ok %d\n",$i++;

print "not " unless 1 == one_args +5;
printf "ok %d\n",$i++;

print "not " unless 4 == &one_args;
printf "ok %d\n",$i++;

print "not " unless 2 == &one_args(1,2);
printf "ok %d\n",$i++;

eval "one_args(1,2)";
print "not " unless $@;
printf "ok %d\n",$i++;

eval "one_args()";
print "not " unless $@;
printf "ok %d\n",$i++;

sub one_a_args ($) {
    print "# \@_ = (",join(",",@_),")\n";
    print "not " unless @_ == 1 && $_[0] == 4;
    printf "ok %d\n",$i++;
}

one_a_args(@_);

##
##
##

testing \&over_one_args, '$@';

sub over_one_args ($@) {
    print "# \@_ = (",join(",",@_),")\n";
    scalar(@_)
}

print "not " unless 1 == over_one_args(1);
printf "ok %d\n",$i++;

print "not " unless 2 == over_one_args(1,2);
printf "ok %d\n",$i++;

print "not " unless 1 == over_one_args +5;
printf "ok %d\n",$i++;

print "not " unless 4 == &over_one_args;
printf "ok %d\n",$i++;

print "not " unless 2 == &over_one_args(1,2);
printf "ok %d\n",$i++;

print "not " unless 5 == &over_one_args(1,@_);
printf "ok %d\n",$i++;

eval "over_one_args()";
print "not " unless $@;
printf "ok %d\n",$i++;

sub over_one_a_args ($@) {
    print "# \@_ = (",join(",",@_),")\n";
    print "not " unless @_ >= 1 && $_[0] == 4;
    printf "ok %d\n",$i++;
}

over_one_a_args(@_);
over_one_a_args(@_,1);
over_one_a_args(@_,1,2);
over_one_a_args(@_,@_);

##
##
##

testing \&scalar_and_hash, '$%';

sub scalar_and_hash ($%) {
    print "# \@_ = (",join(",",@_),")\n";
    scalar(@_)
}

print "not " unless 1 == scalar_and_hash(1);
printf "ok %d\n",$i++;

print "not " unless 3 == scalar_and_hash(1,2,3);
printf "ok %d\n",$i++;

print "not " unless 1 == scalar_and_hash +5;
printf "ok %d\n",$i++;

print "not " unless 4 == &scalar_and_hash;
printf "ok %d\n",$i++;

print "not " unless 2 == &scalar_and_hash(1,2);
printf "ok %d\n",$i++;

print "not " unless 5 == &scalar_and_hash(1,@_);
printf "ok %d\n",$i++;

eval "scalar_and_hash()";
print "not " unless $@;
printf "ok %d\n",$i++;

sub scalar_and_hash_a ($@) {
    print "# \@_ = (",join(",",@_),")\n";
    print "not " unless @_ >= 1 && $_[0] == 4;
    printf "ok %d\n",$i++;
}

scalar_and_hash_a(@_);
scalar_and_hash_a(@_,1);
scalar_and_hash_a(@_,1,2);
scalar_and_hash_a(@_,@_);

##
##
##

testing \&one_or_two, '$;$';

sub one_or_two ($;$) {
    print "# \@_ = (",join(",",@_),")\n";
    scalar(@_)
}

print "not " unless 1 == one_or_two(1);
printf "ok %d\n",$i++;

print "not " unless 2 == one_or_two(1,3);
printf "ok %d\n",$i++;

print "not " unless 1 == one_or_two +5;
printf "ok %d\n",$i++;

print "not " unless 4 == &one_or_two;
printf "ok %d\n",$i++;

print "not " unless 3 == &one_or_two(1,2,3);
printf "ok %d\n",$i++;

print "not " unless 5 == &one_or_two(1,@_);
printf "ok %d\n",$i++;

eval "one_or_two()";
print "not " unless $@;
printf "ok %d\n",$i++;

eval "one_or_two(1,2,3)";
print "not " unless $@;
printf "ok %d\n",$i++;

sub one_or_two_a ($;$) {
    print "# \@_ = (",join(",",@_),")\n";
    print "not " unless @_ >= 1 && $_[0] == 4;
    printf "ok %d\n",$i++;
}

one_or_two_a(@_);
one_or_two_a(@_,1);
one_or_two_a(@_,@_);

##
##
##

testing \&a_sub, '&';

sub a_sub (&) {
    print "# \@_ = (",join(",",@_),")\n";
    &{$_[0]};
}

sub tmp_sub_1 { printf "ok %d\n",$i++ }

a_sub { printf "ok %d\n",$i++ };
a_sub \&tmp_sub_1;

@array = ( \&tmp_sub_1 );
eval 'a_sub @array';
print "not " unless $@;
printf "ok %d\n",$i++;

##
##
##

testing \&sub_aref, '&\@';

sub sub_aref (&\@) {
    print "# \@_ = (",join(",",@_),")\n";
    my($sub,$array) = @_;
    print "not " unless @_ == 2 && @{$array} == 4;
    print map { &{$sub}($_) } @{$array}
}

@array = (qw(O K)," ", $i++);
sub_aref { lc shift } @array;
print "\n";

##
##
##

testing \&sub_array, '&@';

sub sub_array (&@) {
    print "# \@_ = (",join(",",@_),")\n";
    print "not " unless @_ == 5;
    my $sub = shift;
    print map { &{$sub}($_) } @_
}

@array = (qw(O K)," ", $i++);
sub_array { lc shift } @array;
print "\n";

##
##
##

testing \&a_hash, '%';

sub a_hash (%) {
    print "# \@_ = (",join(",",@_),")\n";
    scalar(@_);
}

print "not " unless 1 == a_hash 'a';
printf "ok %d\n",$i++;

print "not " unless 2 == a_hash 'a','b';
printf "ok %d\n",$i++;

##
##
##

testing \&a_hash_ref, '\%';

sub a_hash_ref (\%) {
    print "# \@_ = (",join(",",@_),")\n";
    print "not " unless ref($_[0]) && $_[0]->{'a'};
    printf "ok %d\n",$i++;
    $_[0]->{'b'} = 2;
}

%hash = ( a => 1);
a_hash_ref %hash;
print "not " unless $hash{'b'} == 2;
printf "ok %d\n",$i++;

##
##
##

testing \&an_array_ref, '\@';

sub an_array_ref (\@) {
    print "# \@_ = (",join(",",@_),")\n";
    print "not " unless ref($_[0]) && 1 == @{$_[0]};
    printf "ok %d\n",$i++;
    @{$_[0]} = (qw(ok)," ",$i++,"\n");
}

@array = ('a');
an_array_ref @array;
print "not " unless @array == 4;
print @array;

# correctly note too-short parameter lists that don't end with '$',
#  a possible regression.

sub foo1 ($\@);
eval q{ foo1 "s" };
print "not " unless $@ =~ /^Not enough/;
print "ok ", $i++, "\n";

sub foo2 ($\%);
eval q{ foo2 "s" };
print "not " unless $@ =~ /^Not enough/;
print "ok ", $i++, "\n";
