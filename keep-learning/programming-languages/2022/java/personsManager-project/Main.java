package se.miun.nosu2000;

import java.util.ArrayList;
import java.util.concurrent.CancellationException;

public class Main extends ProjectUtils{
    public static void main(String[] args) {
        ArrayList<Person> aListOfPersons = new ArrayList<>();
        try {
            while (true) {
                mainMenu(aListOfPersons.size());
                String choice = prompt(PROMPT_MENU_CHOICE, REGEX_MENU_CHOICE, BAD_INPUT_MSG_MENU_CHOICE).toLowerCase();
                switch (choice) {
                    case "1":
                        menuAddingPerson(aListOfPersons);
                        break;
                    case "2":
                        menuPrintList(aListOfPersons);
                        break;
                    case "3":
                        menuFindPerson(aListOfPersons);
                        break;
                    case "4":
                        menuDeletePerson(aListOfPersons);
                        break;
                    case "5":
                        menuSortByName(aListOfPersons);
                        break;
                    case "6":
                        menuSortBySign(aListOfPersons);
                        break;
                    case "7":
                        menuSortByLength(aListOfPersons);
                        break;
                    case "8":
                        menuShuffleList(aListOfPersons);
                        break;
                    case "9":
                        menuSaveToFile(aListOfPersons);
                        break;
                    case "10":
                        menuListFromFile(aListOfPersons);
                        break;
                    case "11":
                    default:
                        System.exit(0);
                        return;
                }
            }
        } catch (final CancellationException e) {
            System.exit(0);
        }
    }
}
