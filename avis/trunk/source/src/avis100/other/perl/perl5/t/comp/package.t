#!./perl

print "1..7\n";

$blurfl = 123;
$foo = 3;

package xyz;

$bar = 4;

{
    package ABC;
    $blurfl = 5;
    $main'a = $'b;
}

$ABC'dyick = 6;

$xyz = 2;

$main = join(':', sort(keys %main::));
$xyz = join(':', sort(keys %xyz::));
$ABC = join(':', sort(keys %ABC::));

print $xyz eq 'ABC:bar:main:xyz' ? "ok 1\n" : "not ok 1 '$xyz'\n";
print $ABC eq 'blurfl:dyick' ? "ok 2\n" : "not ok 2 '$ABC'\n";
print $main'blurfl == 123 ? "ok 3\n" : "not ok 3\n";

package ABC;

print $blurfl == 5 ? "ok 4\n" : "not ok 4\n";
eval 'print $blurfl == 5 ? "ok 5\n" : "not ok 5\n";';
eval 'package main; print $blurfl == 123 ? "ok 6\n" : "not ok 6\n";';
print $blurfl == 5 ? "ok 7\n" : "not ok 7\n";
