package se.miun.nosu2000;

import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;
import java.util.concurrent.CancellationException;
import java.util.concurrent.TimeUnit;

/**
 * @author (Nordin Suleimani)
 * @version (1.0)
 */
abstract public class ProjectUtils {

    protected static final String MENU_ITEM_ADD = "1. Add a new person";
    protected static final String MENU_ITEM_PRINT = "2. Print person list";
    protected static final String MENU_ITEM_SEARCH = "3. Search for person";
    protected static final String MENU_ITEM_REMOVE = "4. Remove a person";
    protected static final String MENU_ITEM_SORT_BY_NAME = "5. Sort list by persons name";
    protected static final String MENU_ITEM_SORT_BY_SIGN = "6. Sort list by persons sign";
    protected static final String MENU_ITEM_SORT_BY_LENGTH = "7. Sort list by persons length";
    protected static final String MENU_ITEM_SHUFFLE = "8. Randomize list order";
    protected static final String MENU_ITEM_SAVE_TO_FILE = "9. Save to file";
    protected static final String MENU_ITEM_READ_FROM_FILE = "10. Grab list of persons from file";
    protected static final String MENU_ITEM_EXIT = "11. Exit program";

    protected static final String FILE_SPLIT_DELIM = "|";

    protected static final String OUTPUT_SEPARATOR_LINE = "----------------------------------------------------------------------------------";
    protected static final String OUTPUT_ENTER_FOR_MENU = "============================== PRESS ENTER FOR MENU ==============================";
    protected static final String OUTPUT_ENTER_FOR_MORE = "=========================== PRESS ENTER TO PRINT MORE ============================";
    protected static final String OUTPUT_FILE_VALIDATION_BAD = "File content douse not pass required validation, nothing was added to the list!";
    protected static final String OUTPUT_BAD_FILE = "Could not find or open file ";
    protected static final String OUTPUT_LIST_IS_EMPTY = "Person list is empty, could not perform selected action";
    protected static final String OUTPUT_FILE_READ_SUCCESS = "File was successfully imported into list";
    protected static final String OUTPUT_FILE_READ_SUCCESS_WITH_DUPLICATES = "File was successfully imported into list, duplicates where ignored";
    protected static final String PERSON_WAS_NOT_FOUND = "Specified person was not found";
    protected static final String PERSON_WAS_DELETED = "Person was removed from list";

    protected static final String PROMPT_CHAR = "> ";
    protected static final String PROMPT_MENU_CHOICE = "Menu choice";
    protected static final String PROMPT_PERSONS_FIRSTNAME = "Persons firstname";
    protected static final String PROMPT_PERSONS_LASTNAME = "Persons lastname";
    protected static final String PROMPT_PERSONS_LENGTH = "Persons Length(in cm)";
    protected static final String PROMPT_PERSONS_POST_ADDRESS = "Persons post address";
    protected static final String PROMPT_PERSONS_POST_TOWN = "Persons post town";
    protected static final String PROMPT_PERSONS_ZIP_CODE = "Persons zip code";
    protected static final String PROMPT_FILENAME_TO_READ = "File name to read from";
    protected static final String PROMPT_TRY_AGAIN = "Would you like to try again (yes/y | no/n)";
    protected static final String PROMPT_EXITING_TO_MENU = "Exiting to Menu...";
    protected static final String PROMPT_GET_SIGNATURE = "Persons signature?(yyyxxxnn)";
    protected static final String PROMPT_OVERWRITE_LIST = "Overwrite or add to the list (yes/y -> overwrite | no/n -> add)";
    protected static final String PROMPT_ADD_PERSON_YES_NO = "Add another person (yes/y | no/n)";
    protected static final String PROMPT_FAIL_ADD_PERSON_YES_NO = "Failed to add: duplicate found, add another person (yes/y | no/n)";
    protected static final String PROMPT_SEARCH_PERSON = "Search for another person (yes/y | no/n)";
    protected static final String PROMPT_REMOVE_PERSON = "Remove another person (yes/y | no/n)";
    protected static final String PROMPT_SHUFFLED = "List was shuffled";
    protected static final String PROMPT_SORT_BY_NAME = "List was sorted by lastname then firstname";
    protected static final String PROMPT_SORT_BY_SIGN = "List was sorted by signature";
    protected static final String PROMPT_SORT_BY_LENGTH = "List was sorted by length in descending order";
    protected static final String PROMPT_EXIT_AT_ANY_TIME = "At any time type \"exit\" to get back or terminate program.";
    protected static final String PROMPT_CURRENT_LIST_SIZE = "The current number of persons in our list is: ";
    protected static final String PROMPT_SUCCESS_WRITE_FILE = "Successfully wrote to specified file";
    protected static final String PROMPT_FAIL_WRITE_FILE = "Failed to write to specified file";
    protected static final String PROMPT_FILENAME_TO_WRITE = "Specify a file name to write to";
    protected static final String PROMPT_OVERWRITE_FILE = "Overwrite or add to the file (yes/y -> overwrite | no/n -> add)";
    protected static final String PROMPT_MAXIMUM_ENTRIES = "This specified user was not added. Maximum name duplicate for this specified, \nfirstname and last name has been reached(a maximum of 100)";

    protected static final String REGEX_MENU_CHOICE = "^(?<p>1|2|3|4|5|6|7|8|9|10|11|exit)$";
    protected static final String REGEX_LENGTH = "[0-9]{3}";
    protected static final String REGEX_WORDS = "[a-zA-Z ]+";
    protected static final String REGEX_POST_ADDRESS = "[a-zA-Z0-9 ]+";
    protected static final String REGEX_DIGITS = "[0-9]+";
    protected static final String REGEX_YES_NO = "^(?:Yes|No|yes|no|Y|N|y|n)$";
    protected static final String REGEX_EXIT = "exit";
    protected static final String REGEX_YES_LONG = "yes";
    protected static final String REGEX_YES_SHORT = "y";
    protected static final String REGEX_FILENAME = "^[\\w,\\s-]+\\.[A-Za-z]{3}$";
    protected static final String REGEX_SIGNATURE = "^[a-zA-Z]{6}[0-9]{2}$";
    protected static final String REGEX_FILE_SPLIT_DELIM = "\\|";

    protected static final String BAD_INPUT_MSG_MENU_CHOICE = "Bad input, expecting a number(1-11) for menu selection.";
    protected static final String BAD_INPUT_MSG_FIRSTNAME = "Bad input, expecting a word or multiple words as persons firstname.";
    protected static final String BAD_INPUT_MSG_LASTNAME = "Bad input, expecting a word or multiple words as persons lastname.";
    protected static final String BAD_INPUT_MSG_LENGTH = "Bad input, expecting a number as persons length.";
    protected static final String BAD_INPUT_MSG_POST_ADDRESS = "Bad input, expecting a word or multiple words as persons post address.";
    protected static final String BAD_INPUT_MSG_POST_TOWN = "Bad input, expecting a word or multiple words as persons post town.";
    protected static final String BAD_INPUT_MSG_ZIP_CODE = "Bad input, expecting a set of numbers as persons zip code.";
    protected static final String BAD_INPUT_YES_NO = "Bad input, enter \"yes\" or \"no\" and hit enter";
    protected static final String BAD_INPUT_FILENAME = "Bad input, expecting a file name e.g. file.txt";
    protected static final String BAD_INPUT_MSG_SIGNATURE = "Bad input, expected 6 letters followed by two digits e.g. boxekx00";

    protected static final String PRINT_FORMAT_TITLE = "%-4s  %-10s %-30s %-10s %n";
    protected static final String PRINT_FORMAT_ITEMS = "%3s.  %-10s %-30s %-10.4s %n";
    protected static final String NR_COLUMN_TITLE = "Nr";
    protected static final String SIGN_COLUMN_TITLE = "Sign";
    protected static final String NAME_COLUMN_TITLE = "Name";
    protected static final String LENGTH_COLUMN_TITLE = "Length [m]";

    /**
     * Prints out all menu choices
     * @param size value representing amount of persons in the current list
     */
    public static void mainMenu(int size) {
        System.out.println(PROMPT_EXIT_AT_ANY_TIME);
        System.out.println(PROMPT_CURRENT_LIST_SIZE + size);

        System.out.println(MENU_ITEM_ADD);
        System.out.println(MENU_ITEM_PRINT);
        System.out.println(MENU_ITEM_SEARCH);
        System.out.println(MENU_ITEM_REMOVE);
        System.out.println(MENU_ITEM_SORT_BY_NAME);
        System.out.println(MENU_ITEM_SORT_BY_SIGN);
        System.out.println(MENU_ITEM_SORT_BY_LENGTH);
        System.out.println(MENU_ITEM_SHUFFLE);
        System.out.println(MENU_ITEM_SAVE_TO_FILE);
        System.out.println(MENU_ITEM_READ_FROM_FILE);
        System.out.println(MENU_ITEM_EXIT);
    }

    /**
     * Used to add a person to list list
     * @param aListOfPersons the list that a person object will be added to
     */
    public static void menuAddingPerson(ArrayList<Person> aListOfPersons) {
        String addAgain;
        try {
            while (true) {
                // get person information, generate a signature for person
                String firstName = prompt(PROMPT_PERSONS_FIRSTNAME, REGEX_WORDS, BAD_INPUT_MSG_FIRSTNAME);
                String lastName = prompt(PROMPT_PERSONS_LASTNAME, REGEX_WORDS, BAD_INPUT_MSG_LASTNAME);
                int length = Integer.parseInt(prompt(PROMPT_PERSONS_LENGTH, REGEX_LENGTH, BAD_INPUT_MSG_LENGTH));
                String signature = Signature.make(firstName, lastName);

                String postAddress = prompt(PROMPT_PERSONS_POST_ADDRESS, REGEX_POST_ADDRESS, BAD_INPUT_MSG_POST_ADDRESS);
                String postTown = prompt(PROMPT_PERSONS_POST_TOWN, REGEX_WORDS, BAD_INPUT_MSG_POST_TOWN);
                String zipCode = prompt(PROMPT_PERSONS_ZIP_CODE, REGEX_DIGITS, BAD_INPUT_MSG_ZIP_CODE);

                // create adress object and person object
                Address tempAddress = new Address(postAddress, zipCode, postTown);
                Person tempPerson = new Person(firstName, lastName, length, signature, tempAddress);

                // check if a person with current firstname, lastname and length exist. If not add this person to list
                if(hasDuplicate(aListOfPersons, tempPerson.getLastNameFirstNameLength())) {
                    addAgain = prompt(PROMPT_FAIL_ADD_PERSON_YES_NO, REGEX_YES_NO, BAD_INPUT_YES_NO).toLowerCase();
                } else {
                    add(aListOfPersons, tempPerson);
                    addAgain = prompt(PROMPT_ADD_PERSON_YES_NO, REGEX_YES_NO, BAD_INPUT_YES_NO).toLowerCase();
                }

                // douse user want to add another person
                if (REGEX_YES_LONG.equals(addAgain) || REGEX_YES_SHORT.equals(addAgain)) continue;

                break;
            }
        } catch (final CancellationException e) {
            // will exit to main menu
        }
        actionPromptMsg(PROMPT_EXITING_TO_MENU, true);
    }

    /**
     * Finds a person from a given persons list according to a user input, if found print user to console
     * if not found print not found message
     * @param aListOfPersons A given persons list to find a person from
     */
    public static void menuFindPerson(ArrayList<Person> aListOfPersons) {
        // no need to do anything if list is empty
        if (aListOfPersons.isEmpty()) {
            actionPromptMsg(OUTPUT_LIST_IS_EMPTY, true);
            return;
        }
        try {
            while (true) {
                // get person signature from user to search for person in list
                String signature = prompt(PROMPT_GET_SIGNATURE, REGEX_SIGNATURE, BAD_INPUT_MSG_SIGNATURE).toLowerCase();
                Person foundPerson = getPersonBySignature(aListOfPersons, signature);

                // print person if found
                if (foundPerson != null)
                    printPerson(foundPerson);
                else
                    System.out.println(PERSON_WAS_NOT_FOUND);

                // douse user want to search for another person
                String findAnother = prompt(PROMPT_SEARCH_PERSON, REGEX_YES_NO, BAD_INPUT_YES_NO).toLowerCase();
                if (REGEX_YES_LONG.equals(findAnother) || REGEX_YES_SHORT.equals(findAnother)) continue;
                break;
            }
        } catch (CancellationException e) {
            // the loop was canceled
        }
        actionPromptMsg(PROMPT_EXITING_TO_MENU, true);
    }

    /**
     * Removes a person from a given list when user gives the correct input to find person
     * @param aListOfPersons A persons list to remove a user from
     */
    public static void menuDeletePerson(ArrayList<Person> aListOfPersons) {
        // no need to do anything if list is empty
        if (aListOfPersons.isEmpty()) {
            actionPromptMsg(OUTPUT_LIST_IS_EMPTY, true);
            return;
        }
        try {
            while (true) {
                // get person signature to find and delete person
                String signature = prompt(PROMPT_GET_SIGNATURE, REGEX_SIGNATURE, BAD_INPUT_MSG_SIGNATURE).toLowerCase();
                if (deletePersonBySignature(aListOfPersons, signature))
                    System.out.println(PERSON_WAS_DELETED);
                else
                    System.out.println(PERSON_WAS_NOT_FOUND);

                // douse user want to delete another person
                String deleteAnother = prompt(PROMPT_REMOVE_PERSON, REGEX_YES_NO, BAD_INPUT_YES_NO).toLowerCase();
                if (REGEX_YES_LONG.equals(deleteAnother) || REGEX_YES_SHORT.equals(deleteAnother)) continue;
                break;
            }
        } catch (CancellationException e) {
            // the loop was canceled
        }
        actionPromptMsg(PROMPT_EXITING_TO_MENU, true);
    }

    /**
     * Gets persons from a file and adds or overwrites a given list
     * @param aListOfPersons a persons list to add person objects to
     */
    public static void menuListFromFile(ArrayList<Person> aListOfPersons) {
        ArrayList<Person> tempPersonsList;
        ArrayList<String> fileLines;
        String fileName;
        String isOverwrite;
        while (true) {
            boolean hasDuplicates = false;
            try {
                // ask user for filename and try accessing the file
                fileName = prompt(PROMPT_FILENAME_TO_READ, REGEX_FILENAME, BAD_INPUT_FILENAME);
                try {
                    fileLines = (ArrayList<String>) Files.readAllLines(Paths.get(fileName));
                } catch (IOException e) {
                    throw new IOException(OUTPUT_BAD_FILE + fileName);
                }
                // ask if user wants to overwrite given persons list
                isOverwrite = prompt(PROMPT_OVERWRITE_LIST, REGEX_YES_NO, BAD_INPUT_YES_NO).toLowerCase();
                if (isOverwrite.matches(REGEX_YES_LONG) || isOverwrite.matches(REGEX_YES_SHORT) && !aListOfPersons.isEmpty())
                    aListOfPersons = new ArrayList<>(); // empty list if not already empty

                for (String line : fileLines) {
                    // skip empty lines from file
                    if (line.isEmpty()) continue;

                    //split line by delimiter and save to appropriate variables
                    String[] personProperties = line.split(REGEX_FILE_SPLIT_DELIM);
                    String firstName = personProperties[0];
                    String lastName = personProperties[1];
                    int length = Integer.parseInt(personProperties[2]);
//            String signature = personProperties[3]; // we will generate a new signature
                    String signature = "";
                    String postAdress = personProperties[4];
                    String zipCode = personProperties[5];
                    String postTown = personProperties[6];

                    // check if all person informations for this line is valid
                    if (!firstName.matches(REGEX_WORDS) ||
                            !lastName.matches(REGEX_WORDS) ||
                            !Integer.toString(length).matches(REGEX_LENGTH) ||
                            // signature - lets skip this one, we will generate one
                            !postAdress.matches(REGEX_POST_ADDRESS) ||
                            !zipCode.matches(REGEX_DIGITS) ||
                            !postTown.matches(REGEX_WORDS)
                    ) throw new IOException(OUTPUT_FILE_VALIDATION_BAD);

                    //create address object and person object
                    Address address = new Address(postAdress, zipCode, postTown);
                    Person newPerson = new Person(firstName, lastName, length, signature, address);

                    // if current person is not already in list add to list
                    if(!hasDuplicate(aListOfPersons, newPerson.getLastNameFirstNameLength())) {
                        add(aListOfPersons, newPerson);
                    }else{
                        // if any duplicates where wound in file store to output msg to user that duplicates where ignored
                        hasDuplicates = true;
                    }
                }
                // if duplicates where found, output msg ignored duplicates from file
                if(!hasDuplicates) {
                    actionPromptMsg(OUTPUT_FILE_READ_SUCCESS, true);
                } else {
                    actionPromptMsg(OUTPUT_FILE_READ_SUCCESS_WITH_DUPLICATES, true);
                }
                //success, exiting to main menu
                return;
            } catch (IOException e) {
                System.out.println(e.getMessage());
                try { // something went wrong, ask if user wants to try again
                    String tryAgain = prompt(PROMPT_TRY_AGAIN, REGEX_YES_NO, BAD_INPUT_YES_NO).toLowerCase();
                    if (REGEX_YES_LONG.equals(tryAgain) || REGEX_YES_SHORT.equals(tryAgain)) continue;
                } catch (CancellationException msg) {
                    // we will exit to main menu
                }
            } catch (CancellationException e) {
                // we will exit to main menu
            }
            // exiting to main menu
            actionPromptMsg(PROMPT_EXITING_TO_MENU, true);
            return;
        }
    }

    /**
     * Save given person list to a file
     * @param aListOfPersons A persons list to write to file
     */
    public static void menuSaveToFile(ArrayList<Person> aListOfPersons) {
        // no need to do anything if list is empty
        if (aListOfPersons.isEmpty()) {
            actionPromptMsg(OUTPUT_LIST_IS_EMPTY, true);
            return;
        }
        String fileName;
        String isOverwrite;
        FileWriter fileWriter;
        while (true) {
            try {
                // ask user for filename and if they want to overwrite file or add to file
                fileName = prompt(PROMPT_FILENAME_TO_WRITE, REGEX_FILENAME, BAD_INPUT_FILENAME);
                isOverwrite = prompt(PROMPT_OVERWRITE_FILE, REGEX_YES_NO, BAD_INPUT_YES_NO).toLowerCase();
                if (isOverwrite.matches(REGEX_YES_LONG) || isOverwrite.matches(REGEX_YES_SHORT) && !aListOfPersons.isEmpty()) {
                    fileWriter = new FileWriter(fileName, false);
                } else {
                    fileWriter = new FileWriter(fileName, true);
                }
                // write person information to file
                for (Person person : aListOfPersons) {
                    fileWriter.write(person.getFirstName() + FILE_SPLIT_DELIM
                            + person.getLastName() + FILE_SPLIT_DELIM
                            + person.getLength() + FILE_SPLIT_DELIM
                            + person.getSignature() + FILE_SPLIT_DELIM
                            + person.address.getPostAddress() + FILE_SPLIT_DELIM
                            + person.address.getZipCode() + FILE_SPLIT_DELIM
                            + person.address.getPostTown() + "\n");
                }
                fileWriter.close();
                // success writing to file, exit to main menu
                actionPromptMsg(PROMPT_SUCCESS_WRITE_FILE, true);
                return;
            } catch (final IOException e) {
                // something went wrong, ask if user wants to try again
                actionPromptMsg(PROMPT_FAIL_WRITE_FILE, true);
                try { 
                    String tryAgain = prompt(PROMPT_TRY_AGAIN, REGEX_YES_NO, BAD_INPUT_YES_NO).toLowerCase();
                    if (REGEX_YES_LONG.equals(tryAgain) || REGEX_YES_SHORT.equals(tryAgain)) continue;
                } catch (final CancellationException msg) {
                    // we will exit to main menu
                }
            } catch (final CancellationException eCancel) {
                // user wants to exit to main menu
                actionPromptMsg(PROMPT_EXITING_TO_MENU, true);
                return;
            }
        }
    }

    /**
     * Sorts a given persons list by lastname followed then firstname
     * @param aListOfPersons A persons list to sort
     */
    public static void menuSortByName(ArrayList<Person> aListOfPersons) {
        // no need to do anything if list is empty
        if (aListOfPersons.isEmpty()) {
            actionPromptMsg(OUTPUT_LIST_IS_EMPTY, true);
            return;
        }
        //sort by lastname followed then firstname
        aListOfPersons.sort(Comparator.comparing(Person::getLastNameFirstName));
        actionPromptMsg(PROMPT_SORT_BY_NAME, true);
    }

    /**
     * Sorts a given persons list by signature
     * @param aListOfPersons A persons list to sort
     */
    public static void menuSortBySign(ArrayList<Person> aListOfPersons) {
        // no need to do anything if list is empty
        if (aListOfPersons.isEmpty()) {
            actionPromptMsg(OUTPUT_LIST_IS_EMPTY, true);
            return;
        }
        // sort by signature
        aListOfPersons.sort(Comparator.comparing(Person::getSignature));
        actionPromptMsg(PROMPT_SORT_BY_SIGN, true);
    }

    /**
     * Sorts a given persons list by length
     * @param aListOfPersons A persons list to sort
     */
    public static void menuSortByLength(ArrayList<Person> aListOfPersons) {
        // no need to do anything if list is empty
        if (aListOfPersons.isEmpty()) {
            actionPromptMsg(OUTPUT_LIST_IS_EMPTY, true);
            return;
        }
        // sort by length in descending order
        aListOfPersons.sort(Comparator.comparing(Person::getLength).reversed());
        actionPromptMsg(PROMPT_SORT_BY_LENGTH, true);
    }

    /**
     * Shuffles a given persons list by randomly
     * @param aListOfPersons A persons list to sort
     */
    public static void menuShuffleList(ArrayList<Person> aListOfPersons) {
        // no need to do anything if list is empty
        if (aListOfPersons.isEmpty()) {
            actionPromptMsg(OUTPUT_LIST_IS_EMPTY, true);
            return;
        }
        // suffle the list randomly
        Collections.shuffle(aListOfPersons);
        actionPromptMsg(PROMPT_SHUFFLED, true);
    }

    /**
     * Prints a list of persons to the console
     * @param aListOfPersons A persons list to sort
     */
    public static void menuPrintList(ArrayList<Person> aListOfPersons) {
        // no need to do anything if list is empty
        if (aListOfPersons.isEmpty()) {
            actionPromptMsg(OUTPUT_LIST_IS_EMPTY, true);
            return;
        }

        final int LINES_TO_PRINT_ON_ENTER = 20; // lines to print before waiting for user to hit continue
        int placement = 1; // track line number
        int linesPrinted = 0; // count to line limit before wating for user to continue
        printTitle();
        // print x lines at a time containing person information per line
        for (Person person : aListOfPersons) {
            printer(person, placement);
            placement++;
            linesPrinted++;
            if (linesPrinted == LINES_TO_PRINT_ON_ENTER) {
                linesPrinted = 0;
                if (placement - 1 < aListOfPersons.size()) {
                    actionPromptMsg(OUTPUT_ENTER_FOR_MORE, false);
                }
            }
        }
        // done printing entire persons list, wait for user to hit enter to go to main menu
        actionPromptMsg(OUTPUT_ENTER_FOR_MENU, false);
    }

    /**
     * Searchs a personlist for a person by given signature
     * @param aListOfPersons A list of persons to search in
     * @param signature A signature string to search for in each persons property
     * @return return the found person object
     */
    public static Person getPersonBySignature(ArrayList<Person> aListOfPersons, String signature) {
        signature = signature.toLowerCase();
        for (Person person : aListOfPersons) {
            if (person.getSignature().equals(signature)) {
                return person;
            }
        }
        return null;
    }

    /**
     * Looks if there is a person with same firstname, lastname and length in a persons list
     * @param aListOfPersons A persons list to search in
     * @param toCheckAgainst lastname, firstname and length as a string to search for
     * @return returns true if duplicate was found or false if not
     */
    public static boolean hasDuplicate(ArrayList<Person> aListOfPersons, String toCheckAgainst) {
            if (!aListOfPersons.isEmpty()) {
            for (Person tempPerson : aListOfPersons) {
                if (tempPerson.getLastNameFirstNameLength().equals(toCheckAgainst)) {
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * Adds a person object to a given persons list
     * @param aListOfPersons A persons list to add a person to
     * @param person A person that might be added
     * @return returns true if person was added to list or false if not
     */
    public static boolean add(ArrayList<Person> aListOfPersons, Person person) {
        // generate signature for user,
        // PS. leave as is even if we read from file since we want unique signature, file might have duplicate signature
        String tempSignature = Signature.make(person.getFirstName(), person.getLastName());

        // suffix to be added to the signature, to create unique signature for persons with same firstname and lastname
        int suffixIncrementNum = 0;
        while (true) {
            // we will only store 100 persons with same firstname and lastname
            if (suffixIncrementNum == 100) {
                System.out.println(PROMPT_MAXIMUM_ENTRIES);
                return false;
            }
            // prefix suffix with a 0 if below 10
            String tempSuffix = "";
            if (suffixIncrementNum < 10) {
                tempSuffix = "0" + suffixIncrementNum;
            }
            // if list is not empty and a person with current signature is found increment suffix value and start over
            if (!aListOfPersons.isEmpty() && getPersonBySignature(aListOfPersons, tempSignature + tempSuffix) != null) {
                suffixIncrementNum++;
                continue;
            }

            // an appropriate signature was found, add person to the list
            person.setSignature(tempSignature + tempSuffix);
            aListOfPersons.add(person);
            return true;
        }
    }

    /**
     * Removes a person form a given persons list by given signature
     * @param aListOfPersons A persons list to remove a person from
     * @param signature Search for a person that has this signature
     * @return returns true if person was removed
     */
    public static boolean deletePersonBySignature(ArrayList<Person> aListOfPersons, String signature) {
        return aListOfPersons.removeIf(person -> person.getSignature().equals(signature));
    }

    /**
     * Prints a formatted title
     */
    private static void printTitle() {
        System.out.format(PRINT_FORMAT_TITLE, NR_COLUMN_TITLE, SIGN_COLUMN_TITLE, NAME_COLUMN_TITLE, LENGTH_COLUMN_TITLE);
    }

    /**
     * Prints a given person, makes use of printer method
     * @param person A given person to print
     */
    public static void printPerson(Person person) {
        printTitle();
        printer(person, 1);
    }

    /**
     * Prints a given person in a columned format
     * @param person A given person that will be printed
     * @param placement A numbered order to prefix this output
     */
    private static void printer(Person person, int placement) {
        System.out.format(PRINT_FORMAT_ITEMS,
                placement,
                person.getSignature(),
                person.getFirstName() + " " + person.getLastName(),
                person.getLengthInMeter());
    }

    /**
     * Prompts user for a specific input validated against a regex. Outputs a "failed" msg when not validated
     * @param promptText A string to tell what the prompt expects as input
     * @param expectedInputRegex Regex to match input against
     * @param badInputMessage Output message when match fails regex validation
     * @return returns user input as string
     */
    public static String prompt(String promptText, String expectedInputRegex, String badInputMessage) {
        Scanner scan = new Scanner(System.in);
        System.out.print(promptText + PROMPT_CHAR);
        while (true) {
            String line = scan.nextLine();
            // anytime user inputs exit we cancel back to main menu
            if (line.toLowerCase().matches(REGEX_EXIT)) throw new CancellationException();
            // if not matching regex out put bad, and start over
            if (!line.matches(expectedInputRegex)) {
                System.out.println(badInputMessage);
                System.out.print(promptText + PROMPT_CHAR);
                continue;
            }
            // correct input was given
            return line;
        }
    }

    /**
     * Outputs a massage to user, and either delays for a period or waits for user input ENTER
     * @param msg Message to output
     * @param delay true to delay for a period or false to wait for user input ENTER
     */
    public static void actionPromptMsg(String msg, boolean delay) {
        System.out.println(OUTPUT_SEPARATOR_LINE);
        System.out.println(msg);
        System.out.println(OUTPUT_SEPARATOR_LINE);
        if (delay) {
            try {
                TimeUnit.SECONDS.sleep(1);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        } else {
            Scanner scanner = new Scanner(System.in);
            scanner.nextLine();
        }
    }
}