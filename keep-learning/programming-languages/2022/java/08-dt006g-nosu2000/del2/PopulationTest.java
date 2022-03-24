/**
 * Assignment 8, part 2
 *
 * How to read from a file, format data and save to a file.
 * @author (Nordin Suleimani)
 * @version (1.0)
 */
package labb8.del2;

import java.util.Scanner;

public class PopulationTest {
    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);
        System.out.print("To which file should the result be saved? ");
        String outFileName = keyboard.nextLine();

        Population myPopulation = new Population("befolkning2050.txt");
        myPopulation.writeToFile(outFileName);
        myPopulation.print();
    }
}
