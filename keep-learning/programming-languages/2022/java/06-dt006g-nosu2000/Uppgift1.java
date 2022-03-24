/**
 * Taking an input from keyboard and figuring out amount of characters, words(delimiter " ") and
 * sentences(delimiters ". ! ? \n). Using methods in String, char and StringTokenizer.
 *
 * @author (Nordin Suleimani)
 * @version (1.0)
 */
package dt196d.nosu2000.uppg06;

import java.util.Scanner;
import java.util.StringTokenizer;

public class Uppgift1 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        // get some text
        System.out.print("Enter some text> ");
        String text;
        text = input.nextLine();

        StringTokenizer textInTokens = new StringTokenizer(text);
        char[] charArray = text.toCharArray();
        String[] sentences = text.split("[.!?\n]+");

        System.out.println("Sentences: " + sentences.length);
        System.out.println("Characters: " + charArray.length);
        System.out.println("Words: " + textInTokens.countTokens());
    }
}
