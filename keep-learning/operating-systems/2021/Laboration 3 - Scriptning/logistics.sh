# Filnamn: logistics.sh
# Skrivet av: Nordin Suleimani
# Dator: Denna script har skapats på egen dator med windows 10 operativ system.
# Skapat datum: 2021-02-22
# Senast ändrat: 2021-03-04
# Kurs: Operativsystem introduktionskurs
# Handledare: Jimmy Åhlander
# Beskrivning: En batch script som med både interactivt- och batchläge ger användaren möjligheten att sortera, 
# printa samt göra en backup på en datafil med 6 kolumner.

#!/bin/bash
thisScriptName="${0##*/}"
usingMainMenu=false
dataFile=""

#If we have first argument see if it is for help or the required datafile path  argument is correct
function HandleArgs () {
    if [ "$1" == "--help" ]
    then
        ShowHelpMSG
    else
        if [ ! -f "$1" ]
        then
            echo -e "\e[91mBad input, expecting a logistics datafile\e[0m"
            ExitProgram 
        else
            dataFile="$1"
            ArgOptions "$1" "$2" "$3"
        fi
    fi
}

#If required datafile path argument is correct check other args LOOP?
function ArgOptions () {
    if [[ -z "$2" ]]; then ShowMenu; fi
    if [[ "$2" == "--help" ]]; then ShowHelpMSG; fi
    if [[ "$2" == "-b" ]]; then BackupNow; fi
    if [[ "$2" == "-p" ]]; then PrintNow; fi
    if [[ "$2" == "-s" ]]
    then
        case $3 in
        'i') PrintNow "-k1 -n";;
        'n') PrintNow "-k2 -V";;
        'v') PrintNow "-k3 -n";;
        'l') PrintNow "-k4 -n";;
        'b') PrintNow "-k5 -n";;
        'h') PrintNow "-k6 -n";;
        *) echo -e "\e[93mYou need to specify a sorting option: <i|n|v|l|b|h>\e[0m";
            ExitProgram;;
        esac        
    fi
    echo -e "\e[91mYou have specified unsupported arguments, try --help to see what is possible.\e[0m"
}

# show help message, go back to menu when running interactive
function ShowHelpMSG () {
    echo
    echo "  Usage logistics FILE [-b|-p|-s {i|n|v|l|b|h}]"
    echo "  Used for logistics management with FILE as underlying data."
    echo    
    echo "  -b         generate backup copy of data contents"
    echo "  -p         print data contents and exit"
    echo "  -s         sort by additional argument: id (i)"
    echo "                name(n), wight(v), length(l)"
    echo "                width(b), height(h), print data contents and exit"
    echo "  --help     display this help and exit"
    echo
    IsBatchOrInteractive 
}

# Simply echo the menu options
function ShowMenu () {
    usingMainMenu=true
    fileName=$(basename "$dataFile")
    clear
    echo
    echo -e "--------------\e[95m\e[1mLasses Logistik och Logik\e[0m--------------"
    echo "                                                     "
    echo "   1 - Print $filename to console.                   "
    echo "   2 - Backup $filename to $filename.backup.         "
    echo "   3 - Sort                                          "
    echo "   4 - help                                          "
    echo "   5 - Exit program.                                 "
    echo "                                                     "
    echo "-----------------------------------------------------"
    echo   
    MenuSelect
}

# select select menu item
function MenuSelect () {
    userInput=""
    while [ -z "$userInput" ];
    do
        echo -e "\e[92mType your choice, then press ENTER: \e[0m"
        read userInput
        case $userInput in
        '1') PrintNow;;
        '2') BackupNow;;
        '3') InputSortingOption;;
        '4') ShowHelpMSG;;
        '5') ExitProgram;;
        *) echo -e "\e[91mINVALID input, try again.\e[0m";
            userInput="";;
        esac
    done
}

# Called by menu sort, user needs to select sorting option
function InputSortingOption () {
    sortBy=""
    echo -e "\e[93mSpecify a sorting option: <i|n|v|l|b|h>\e[0m"
    while [ -z "$sortBy" ];
    do
        echo -e "\e[92mType your choice, then press ENTER: \e[0m"
        read sortBy
        case $sortBy in
        'i') PrintNow "-k1 -n";;
        'n') PrintNow "-k2 -V";;
        'v') PrintNow "-k3 -n";;
        'l') PrintNow "-k4 -n";;
        'b') PrintNow "-k5 -n";;
        'h') PrintNow "-k6 -n";;
        *) echo -e "\e[91mINVALID input, try again.\e[0m";
            sortBy="";;
        esac
    done
}

# Print first row then the rest of the rows depending on sorting option.
function PrintNow () {
    echo
    firstRow=$(head -1 $dataFile | sed 's/;/ /g')
    echo -e "\e[7m\e[1m$firstRow\e[0m"
    if [ -z "$1" ]
    then
        tail -n +2 $dataFile | sed 's/;/ /g'
    else 
        tail -n +2 $dataFile | sort -t';' $1 | sed 's/;/ /g'
    fi
    echo -e '\n----------------------------------'
    IsBatchOrInteractive
}

# copy the datafile to the script diractory with extension *.backup
function BackupNow () {
    fileName=$(basename "$dataFile")
    cp $dataFile ./$fileName.backup
    echo -e "\e[93m$fileName has been backed up as $fileName.backup\e[0m"
    IsBatchOrInteractive
}

# handle interactive or not state
function IsBatchOrInteractive () {
    if $usingMainMenu
    then
        echo
        Pause 'Press Enter key to continue...'
        ShowMenu
    else
        ExitProgram
    fi
}

function Pause() {
   read -p "$*"
}

function ExitProgram() {
   echo
   exit
}

#Check if first argument missing or not, if so echo program name and version.
#othewise start the program
if [ -z "$1" ]
then
    echo -e "\e[95mLasses Logistics och Logik v0.1.0"
    echo -e "Please run '$thisScriptName --help' for help.\e[0m"
    ExitProgram
else
    HandleArgs "$1" "$2" "$3"
fi