# UnitTest.pl -- Unit Test (incremental or full)
use Getopt::Long;
use DataFlow;
use strict;

srand (time() ^ ($$ + ($$ << 15)));

my ($Cookie, $ProcessID, $Parameter, $unc);

GetOptions("Cookie=i" => \$Cookie,
	  "ProcessId=i" => \$ProcessID,
	  "Parameter=s" => \$Parameter,
	  "UNC=s" => \$unc);

print "Cookie: $Cookie, ProcessId: $ProcessID, Parameter: $Parameter, UNC: $unc\n";

sleep int(rand 20) + 1;

my $outqueue;

if ($Parameter eq "Full")
{
    $outqueue = "UnSerializeBuild";
    $Parameter = "ArchiveSample"
}
else
{
    $outqueue = "FullDefBuilder";
    $Parameter = "Full";
}

SpecifyStopping($Cookie, $ProcessID, $unc, $outqueue, "1 of 1");

my $DoNextChoice = int (rand 40);

if ($DoNextChoice != 9)
{
   DoNext ($Cookie, $ProcessID, $unc, $outqueue, $Parameter);
   WriteSignatureForDataFlow ($ProcessID, $unc);
}

1;
