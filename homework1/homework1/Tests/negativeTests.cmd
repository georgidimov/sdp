@ECHO OFF
set file=simpleTest.txt

..\InfixEvaluation "( ( 3 + 7 ) * 8 + 20" %file%
ECHO  = ERROR
ECHO.

..\InfixEvaluation "( ( 3 + 7 ) * 8 ) + 20" file
ECHO  = ERROR
ECHO.

..\InfixEvaluation %file%
ECHO  = ERROR
ECHO.

..\InfixEvaluation "( ( 3 + 7 ) * 8 ) + 20 )" %file%
ECHO  = ERROR
ECHO.

..\InfixEvaluation "()" %file%
ECHO  = ERROR
ECHO.

..\InfixEvaluation ")(" %file%
ECHO  = ERROR
ECHO.

..\InfixEvaluation "( ( 3 + 7 ) ( * ) 8 + 20 )" %file%
ECHO  = ERROR
ECHO.

..\InfixEvaluation "( ( 3 + 7 ) * 8 ) + 20 ) (" %file%
ECHO  = ERROR
ECHO.

ECHO.