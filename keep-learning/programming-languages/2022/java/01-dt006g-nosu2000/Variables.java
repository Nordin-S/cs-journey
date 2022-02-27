/**
 * Assignment 1 - part 3
 *
 * declaring and initializing datatypes(Java initializes to null, 0, false if not manually initialized).
 */
import java.util.Random;

public class Variables{
    public static void main(String[] args){
        String lineOfText = "to increment by fraction of random number.";
        String stringFormat;
        int number = 1;
        final double DOUBLE_CONSTANT_VALUE = .1;
        boolean mySwitch = true;
        Random rand = new Random();
        final int UPPER_BOUND = 10;
        int loopLimit = 100;

        while(true){
            if(mySwitch){ // increase a number randomly and print out data types using format to string first..
                number += Math.round(rand.nextInt(UPPER_BOUND) * DOUBLE_CONSTANT_VALUE + 1);
                stringFormat = String.format("A randomly increasing number: %d, " +
                        "using a constant: %2f, %3s", number, DOUBLE_CONSTANT_VALUE, lineOfText);
                System.out.println(stringFormat);
            }else{ // if number is 100 or larger break while loop
                if(number >= loopLimit){
                    break;
                }
            }
            mySwitch = !mySwitch;
        }
    }
}
