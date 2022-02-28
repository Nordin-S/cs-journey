@REM Filnamn: logistics.bat
@REM By: Nordin Suleimani
@REM Created: 2021-02-18
@REM Changed: 2021-03-04
@REM Course: Introduction to Operating System
@REM Description: A batch script that with both interactively and in batch mode gives the user the ability to sort,
@REM print and make a backup of a data file with 6 columns.

@ECHO off
@CHCP 1252 > nul

SETLOCAL ENABLEDELAYEDEXPANSION
CALL :setESC
GOTO :StartProgram

:StartProgram
    @REM Check if first argument missing or not
    IF [%~1]==[] (
        ECHO %ESC%[95mLasses Logistics och Logik v0.1.0
        ECHO Please run '%~n0 /?' for help.%ESC%[0m
    ) ELSE ( 
        GOTO :HandleArgs 
    )
exit /B 0

@REM If we have first argument see if it is for help or the required datafile path  argument is correct
:HandleArgs
    IF [%~1]==[/?] (
        @REM lets set using menu to false since we are doing batch
        SET "usingMainMenu=false"
        GOTO :ShowHelpMSG
    ) ELSE (
            IF not exist %~s1 (
                ECHO %ESC%[91mYou need to specify a logistics datafile, or the specified one douse not exist in the current directory.%ESC%[0m
            ) ELSE (
                IF exist %~s1\NUL (
                    ECHO %ESC%[91mBad input, expecting a logistics datafile, not a directory PATH.%ESC%[0m
                    GOTO :ExitProgram 
                ) ELSE (
                    SET "File=%~f1"          
                    GOTO :ArgOptions 
                )
            )
    )
exit /B 0

@REM If required datafile path argument is correct check other args... maybe use LOOP?
:ArgOptions
    IF [%~2]==[] GOTO :MainMenu

    @REM lets set using menu to false since we are doing batch
    SET "usingMainMenu=false" 

    IF [%~2]==[/?] GOTO :ShowHelpMSG
    IF [%~2]==[/backup] GOTO :BackupNow 
    IF [%~2]==[/print] CALL :PrintNow "/+1" && GOTO :ExitProgram
    IF [%~2]==[/sort] (
        IF [%~3]==[] ECHO %ESC%[91mYou need to specify a sorting option: ^< i ^| n ^| v ^| l ^| b ^| h ^>%ESC%[0m && GOTO :ExitProgram
        IF [%~3]==[i] CALL :PrintNow "/+1" && GOTO :ExitProgram
        IF [%~3]==[n] CALL :PrintNow "/+5" && GOTO :ExitProgram
        IF [%~3]==[v] CALL :PrintNow "/+18" && GOTO :ExitProgram
        IF [%~3]==[l] CALL :PrintNow "/+24" && GOTO :ExitProgram 
        IF [%~3]==[b] CALL :PrintNow "/+28" && GOTO :ExitProgram
        IF [%~3]==[h] ( 
            CALL :PrintNow "/+32" && GOTO :ExitProgram
        ) ELSE ECHO %ESC%[91mYou need to specify a sorting option: ^< i ^| n ^| v ^| l ^| b ^| h ^>%ESC%[0m && GOTO :ExitProgram
    ) ELSE ECHO %ESC%[91mINVALID option, not supported. %ESC%[0m && GOTO :ExitProgram
exit /B 0

@REM We start by printing the datafiles first row, then figure out how we are printing the rest of the file
:PrintNow
    ECHO.
    @REM print first line of file
    set /p var=< %File%
    echo %ESC%[7m%ESC%[4m%ESC%[1m%var%%ESC%[0m

    @REM print rest of file sported
    more +1 %File% | sort "%~1"
    ECHO -----------------------------------
    ECHO.
exit /B 0

:MainMenu
    @REM lets set using menu to true since we are doing interactive
    SET "usingMainMenu=true"
    cls
    ECHO.
    ECHO --------------%ESC%[95m%ESC%[1mLasses Logistik och Logik%ESC%[0m%ESC%[0m--------------
    ECHO.                                                       
    ECHO     1 - Print datafile.txt to console.                
    ECHO     2 - Backup datafile.txt to datafile.txt.backup.   
    ECHO     3 - Sort                                          
    ECHO     4 - help                                          
    ECHO     5 - Exit program.                                 
    ECHO.                                                         
    ECHO -----------------------------------------------------
    ECHO.
GOTO :RetrieveInput

:RetrieveInput
    SET /p UserInput=%ESC%[92mType your choice, then press ENTER: %ESC%[0m
    IF [%UserInput%]==[] (
        ECHO %ESC%[91mPlease choose a MENU item%ESC%[0m && GOTO :RetrieveInput
    ) ELSE (
        IF [%UserInput%]==[1] ( CALL :PrintNow "/+1" && GOTO :IsBatchOrInteractive )
        IF [%UserInput%]==[2] ( GOTO :BackupNow )
        IF [%UserInput%]==[3] ( GOTO :InputSortingOption )
        IF [%UserInput%]==[4] ( GOTO :ShowHelpMSG )
        IF [%UserInput%]==[5] ( 
            @REM lets set using menu to false since we exiting menu
            SET "usingMainMenu=false"
            GOTO :ExitProgram
        ) ELSE ( 
            ECHO %ESC%[91mINVALID input, try again%ESC%[0m && GOTO :RetrieveInput
        )
    )
exit /B 0

@REM interactive sorting input setup
:InputSortingOption
    SET "sortBy="
    ECHO %ESC%[93mSpecify a sorting option: ^< i ^| n ^| v ^| l ^| b ^| h ^>%ESC%[0m
    SET /p sortBy=%ESC%[92mType your choice, then press ENTER: %ESC%[0m

    IF [%sortBy%]==[] (
        ECHO %ESC%[91mPlease choose a sorting option%ESC%[0m && GOTO :InputSortingOption
    ) ELSE (
        IF [%sortBy%]==[i] ( CALL :PrintNow "/+1" && GOTO :IsBatchOrInteractive )
        IF [%sortBy%]==[n] ( CALL :PrintNow "/+5" && GOTO :IsBatchOrInteractive )
        IF [%sortBy%]==[v] ( CALL :PrintNow "/+18" && GOTO :IsBatchOrInteractive )
        IF [%sortBy%]==[l] ( CALL :PrintNow "/+24" && GOTO :IsBatchOrInteractive )
        IF [%sortBy%]==[b] ( CALL :PrintNow "/+28" && GOTO :IsBatchOrInteractive )
        IF [%sortBy%]==[h] ( 
            CALL :PrintNow "/+32" && GOTO :IsBatchOrInteractive
        ) ELSE ( 
            ECHO %ESC%[91mINVALID input, try again%ESC%[0m && GOTO :InputSortingOption
        )
    )
exit /B 0

@REM Help message, go back to menu when running interactive
:ShowHelpMSG
    ECHO.
    ECHO. Anv�nds f�r logistikhantering.
    ECHO.
    ECHO. Syntax: logistics [enhet:] s�kv�g [/backup ^| /print ^| /sort ^< i ^| n ^| v ^| l ^| b ^| h ^>]
    ECHO.
    ECHO. /backup   Genererar en s�kerhetskopia av datafilen i samma katalog.
    ECHO. /print    Skriver ut inneh�llet i datafilen.
    ECHO. /sort     Sorterar och skriver ut inneh�llet i datafilen.
    ECHO.               i  efter produktnummer     n efter namn
    ECHO.               v  efter vikt              l efter l�ngd
    ECHO.               b  efter bredd             h efter h�jd
    ECHO. /?        Skriver ut den h�r hj�lptexten.
    
    GOTO :IsBatchOrInteractive
exit /B 0

@REM Backup, go back to menu when running interactive
:BackupNow
    copy /y %File% %File%.backup
    ECHO %ESC%[93mLogistics file backed up.%ESC%[0m
    GOTO :IsBatchOrInteractive
exit /B 0

@REM handle interactive or not state
:IsBatchOrInteractive
    IF [%usingMainMenu%]==[true] ( 
        ECHO.
        PAUSE
        GOTO :MainMenu 
    ) ELSE ( 
        GOTO :ExitProgram 
    )
exit /B 0

@REM styling extras - copy paste from stackoverflow pretty much
:setESC
    FOR /F "tokens=1,2 delims=#" %%a in ('"prompt #$H#$E# & ECHO on & FOR %%b in (1) do rem"') do (
        SET ESC=%%b
        
    )
exit /B 0

ENDLOCAL

:ExitProgram
    ECHO.
exit /B 0