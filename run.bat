
@del main.o
@del main.nes
@echo.
@echo Compiling ...
ca65 -o main.o -t nes main.s -I inc -l "main.lst"
@IF ERRORLEVEL 1 GOTO failure
@echo.
@echo Linking ...
ld65 -o main.nes -C main.cfg main.o
@IF ERRORLEVEL 1 GOTO failure
@GOTO endbuild
:failure
@echo.
@echo Build error!
@pause
:endbuild
