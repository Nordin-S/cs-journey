/**
 * Assignment 8, part 2
 *
 * How to read from a file, format data and save to a file.
 * @author (Nordin Suleimani)
 * @version (1.0)
 */
package labb8.del2;

import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * This class can be instantiated or used statically. With this class you can read from a
 * population file that is formatted in a specific way. You can output the data in a new
 * format to a new file. The data can also be printed to the terminal.
 */
public class Population {
    private static final String AGE= "Age";
    private static final String QUANTITY= "Quantity";
    private static final String TITLE_FORMAT = "%3s %11s%n";
    private static final String DIVIDER = "===============";
    private static final String BODY_FORMAT = "%3d %11d%n";
    private static final String TOTAL_POPULATION = "Total: ";
    private static final String ERROR_READ_FILE = "Error reading file:\n";
    private static final String ERROR_WRITE_FILE = "Error writing file:\n";
    private static final String BAD_READ_FILE = "Error, read file douse not follow expected format:\n";

    private ArrayList<Integer> populationPerAge = null;
    private int totalPopulation = 0;
    private String inFileName = "befolkning2050.txt";

    public Population() {
        this.populationPerAge = readFile();
        this.totalPopulation = getTotalPopulation();
    }

    /**
     * @param inFileName The file to read from
     */
    public Population(String inFileName){
        this.populationPerAge = readFile(inFileName);
        this.totalPopulation = getTotalPopulation();
    }

    /**
     * @param inFileName File name to read from
     * @param outFileName File name to write to
     */
    public Population(String inFileName, String outFileName){
        this.populationPerAge = readFile(inFileName);
        this.totalPopulation = getTotalPopulation();
        writeToFile(outFileName);
    }

    /**
     * @return Returns an integer arraylist containing population per age corresponding the element index
     */
    public ArrayList<Integer> readFile(){
        return readFile(inFileName);
    }

    /**
     * @param inFileName File name to read from
     * @return Returns an integer arraylist containing population per age corresponding the element index
     */
    public static ArrayList<Integer> readFile(String inFileName) {
        ArrayList<Integer> populationPerAge = new ArrayList<>();
        Scanner fileInput = null;

        try {
            fileInput = new Scanner(new File(inFileName));
            while (fileInput.hasNextLine()) {
                fileInput.nextLine(); // skip one line
                int malesCount = Integer.parseInt(fileInput.nextLine().trim().split("\\s+")[1]);
                int femaleCount = Integer.parseInt(fileInput.nextLine().trim().split("\\s+")[1]);
                populationPerAge.add(malesCount + femaleCount);
            }
            fileInput.close();
        } catch (IOException e) {
            System.out.println(ERROR_READ_FILE + e.getMessage());
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println(BAD_READ_FILE + e.getMessage());
        }
       return populationPerAge;
    }

    /**
     * @return Returns total population as an integer
     */
    public int getTotalPopulation(){
        return getTotalPopulation(this.populationPerAge);
    }

    /**
     * @param populationPerAge Takes an integer arraylist and returns the sum of the element values
     * @return Returns total population as an integer
     */
    public static int getTotalPopulation(ArrayList<Integer> populationPerAge) {
        int totalPopulation = 0;
        for (int currentValue: populationPerAge){
            totalPopulation += currentValue;
        }
        return totalPopulation;
    }

    /**
     * Prints a formatted version of the population per age information as a list,
     * with a Title and at the end a total sum of population
     */
    public void print() {
        print(this.populationPerAge, this.totalPopulation);
    }

    /**
     * Prints a formatted version of the population per age information as a list,
     * with a Title and at the end a total sum of population
     */
    public static void print(ArrayList<Integer> populationPerAge, int totalPopulation) {
        System.out.printf(TITLE_FORMAT, AGE, QUANTITY);
        System.out.println(DIVIDER);
        int age = 0;
        for (int ageGroupValue : populationPerAge){
            System.out.printf(BODY_FORMAT, age, ageGroupValue);
            age++;
        }
        System.out.println(DIVIDER);
        System.out.println(TOTAL_POPULATION + totalPopulation);
    }

    /**
     * Writes a formatted version of the population per age information as a list to a file,
     * with a Title and at the end a total sum of population
     * @param outFileName File name to write to
     */
   public void writeToFile(String outFileName){
        writeToFile(this.populationPerAge, this.totalPopulation, outFileName);
   }

    /**
     * Writes a formatted version of the population per age information as a list to a file,
     * with a Title and at the end a total sum of population
     * @param populationPerAge Integer array list containing population per age data
     * @param totalPopulation Integer containing total population number
     * @param outFileName File name to write to
     */
    public static void writeToFile(ArrayList<Integer> populationPerAge, int totalPopulation, String outFileName) {
        try {
            PrintWriter outPutToFile = new PrintWriter(new BufferedWriter(new FileWriter(outFileName)));
            outPutToFile.printf(TITLE_FORMAT, AGE, QUANTITY);
            outPutToFile.println(DIVIDER);
            int age = 0;
            for (int ageGroupValue : populationPerAge){
                outPutToFile.printf(BODY_FORMAT, age, ageGroupValue);
                age++;
            }
            outPutToFile.println(DIVIDER);
            outPutToFile.println(TOTAL_POPULATION + totalPopulation);
            outPutToFile.close();
        } catch (IOException e) {
            System.out.println(ERROR_WRITE_FILE + e.getMessage());
        }
    }
}
