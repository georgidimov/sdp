@ECHO OFF
set file=simpleTest.txt

..\InfixEvaluation "2 + 3" %file%
ECHO  = 5

..\InfixEvaluation "2 + 3 * 7" %file%
ECHO  = 23

..\InfixEvaluation "2 * 3 * 7" %file%
ECHO  = 42

..\InfixEvaluation "( 2 + 3 ) * 7" %file%
ECHO  = 35

..\InfixEvaluation "5 / 2 / 2" %file%
ECHO  = 1.25

..\InfixEvaluation "( 5 + 3 ) / 2 * 4" %file%
ECHO  = 16

..\InfixEvaluation "( ( 3 + 7 ) * 8 ) + 20" %file%
ECHO  = 100

..\InfixEvaluation "3 + 5 * ( 6 - 9 ) - 8 * 2" %file%
ECHO  = -28

..\InfixEvaluation "0.01 + 2 * ( 12 - 3 ) + 1 * ( 3 * ( 5 - 2 * ( 1 - 1 ) ) )" %file%
ECHO  = 33.01

..\InfixEvaluation "( ( 2 * ( 3 - 5 ) + 10 ) / 4 * 8 )" %file%
ECHO  = 12

ECHO.
