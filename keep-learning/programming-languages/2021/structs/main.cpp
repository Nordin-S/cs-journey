/* 
# filnamn: L1_structar.cpp
# Skrivet av: Nordin Suleimani
# Skapat datum: 2021-04-14
# Senast ändrat: 2021-04-27
# Kurs: Objectbaserad Programmering
# Handledare: Jimmy Åhlander
*/
#include "./includes/MinaFuncs.hpp"

int main (){
    int menuChoice;
    std::vector<person> personsList = read_file("names.txt");

    DrawMenu();
    

    while(true){
        std::cout << "\033[1m\033[32mVad vill du göra?(Gör ett meny val): \033[0m";
        menuChoice = std::stoi(GetInput(false));
        if(menuChoice == 1){
            std::cout << "\033[1m\033[32mVem vill du söka för?: \033[0m";
            std::cout << find_in_names(personsList, GetInput(true)) << std::endl;
            EnterToContinue();
            DrawMenu();
            continue;
        }else if(menuChoice == 2){
            std::cout << "\033[1m\033[32mVilken kommun vill du söka i?: \033[0m";
            std::vector<person> personsFromCity = find_person_from_city(personsList, GetInput(true));
            if(personsFromCity.empty()){
                std::cout << "\033[1m\033[33mKunde inte hitta någon person i angivet kommun.\033[0m" << std::endl;         
            }else{            
                for(person p : personsFromCity){
                    std::cout << p;
                }
            }
            EnterToContinue();
            DrawMenu();
            continue;
        }else if(menuChoice == 3){
            DrawMSG("                       Hej då!");
        }else{
            BadInputMSG("Fel val, vänligen välj ett meny alternativ med 1/2/3 och tryck enter.");
            continue;
        }
        break;
    }

    return 0;
}