: SCC: @(#) 99 1/29/99 14:48:35 AVISDFRL 1.3 @(#)
: Syntax:
:     m depend  [..]
:     m compile [..]
:     m help    [..]
:     m library [..]
:     m exedll  [..]
:     m all     [..]
:     m clean   [..]
:
:     m [-a] debug/release

SET   THIS_PROJECT_NAME=AVISDFRL
SET   THIS_LIBRARY_NAME=AVISDFRL

call %UTILD%\iunimake.cmd %1 %2 %3 %4 %5 %6 %7 %8 %9

SET   THIS_PROJECT_NAME=
SET   THIS_LIBRARY_NAME=
