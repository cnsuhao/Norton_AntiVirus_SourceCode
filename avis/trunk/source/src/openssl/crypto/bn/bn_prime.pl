#!/usr/local/bin/perl
# bn_prime.pl

$num=2048;
$num=$ARGV[0] if ($#ARGV >= 0);

push(@primes,2);
$p=1;
loop: while ($#primes < $num-1)
	{
	$p+=2;
	$s=int(sqrt($p));

	for ($i=0; $primes[$i]<=$s; $i++)
		{
		next loop if (($p%$primes[$i]) == 0);
		}
	push(@primes,$p);
	}

print <<"EOF";
/* Auto generated by bn_prime.pl */
/* Copyright (C) 1995-1997 Eric Young (eay\@mincom.oz.au).
 * All rights reserved.
 * Copyright remains Eric Young's, and as such any Copyright notices in
 * the code are not to be removed.
 * See the COPYRIGHT file in the SSLeay distribution for more details.
 */

EOF

for ($i=0; $i <= $#primes; $i++)
	{
	if ($primes[$i] > 256)
		{
		$eight=$i;
		last;
		}
	}

printf "#ifndef EIGHT_BIT\n";
printf "#define NUMPRIMES %d\n",$num;
printf "#else\n";
printf "#define NUMPRIMES %d\n",$eight;
printf "#endif\n";
print "static unsigned int primes[NUMPRIMES]=\n\t{\n\t";
$init=0;
for ($i=0; $i <= $#primes; $i++)
	{
	printf "\n#ifndef EIGHT_BIT\n\t" if ($primes[$i] > 256) && !($init++);
	printf("\n\t") if (($i%8) == 0) && ($i != 0);
	printf("%4d,",$primes[$i]);
	}
print "\n#endif\n\t};\n";


