/**
 * Searching for a user given word within specified file given from CL or a default file.
 * Counting amount of words in file and skipping empty lines.
 * This exercise is to understand how creating new strings in the string pool inside the heap is less
 * efficient than using something like the Stringbuilder when trying to change a string many times.
 *
 * @author (Nordin Suleimani)
 * @version (1.0)
 */
package dt196d.nosu2000.uppg06;

import java.io.*;
import java.util.Scanner;

public class Uppgift2 {
    public static final String COULD_NOT_FIND_FILE = "(Could not find the given file)";
    public static final String WORDLIST_1 = "wordlist1.txt";
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Scanner file = null;
        // Get the search word
        System.out.print("Enter the word to search for> ");
        String searchWord = input.nextLine().toLowerCase();

        // get file to search in from CL argument or use wordlist1.txt
        if (args.length != 0) {
            file = tryGetFile(args[0]);
        }else{
            file = tryGetFile(WORDLIST_1);
        }

        StringBuilder wordInLine = new StringBuilder();

        int wordCount = 0;
        boolean isFound = false;

        // time before loop starts
        long startTime = System.currentTimeMillis(); // Nuvarande tid i antal millisekunder
        // time to traverse through the file
        while(file.hasNextLine()){
            // do only if line is not empty
            if(!wordInLine.append(file.nextLine()).isEmpty()){
                wordCount++;
                // isFound should be evaluated first, then we don't need to run indexOf
                if(!isFound || wordInLine.indexOf(searchWord) != -1)
                    isFound = true;
                // clear the string builder before appending a new word.
                wordInLine.setLength(0);
            }
        }
        // time when loop is done
        long endTime = System.currentTimeMillis();

        String fileNameUsed = args.length != 0 ? args[0] : WORDLIST_1;
        System.out.println("The file '" + fileNameUsed + "' contains " + wordCount + " words");
        if(isFound)
            System.out.println("The word " + searchWord + " exists in this file");
        System.out.println("The search took " + (endTime - startTime) + " ms");
    }

    public static Scanner tryGetFile(String fileName) {
        Scanner theFile = null;
        try {
            theFile = new Scanner(new File(fileName));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            System.out.println(COULD_NOT_FIND_FILE);
        }
        return theFile;
    }
}
