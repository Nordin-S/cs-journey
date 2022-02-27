package dt196g.nosu2000.uppg04;

import java.util.Random;
import java.util.Scanner;

/**
 * Assignment 4, part 1 - Guess
 * Using while loops and if statements in a numbers guessing game.
 * User inputs a range for the computer to create a secret number within.
 * Then the user will guess what the secret number is.
 * @AUTHOR (NORDIN SULEIMANI)
 * @VERSION (1.0)
 */

public class Guess {
    public static void main(String[] args) {
        int min;
        int max;
        int guess;
        int guessCount = 0;
        System.out.println("Welcome to the Guess the Number game!");
        exitProgram:
        while (true) {
            System.out.println("Time to choose the number interval.(type: \"exit\" to end program)");
            Random r = new Random();
            //get a min value
            String tempInput;
            tempInput = getValidInput("Enter min value: ");
            if (tempInput.equals("exit")){
                break;
            }else {
                min = Integer.parseInt(tempInput);
            }
            // Get a max value larger than the min value
            while (true){
                tempInput = getValidInput("Enter max value: ");
                if (tempInput.equals("exit")){
                    break exitProgram;
                }else if(Integer.parseInt(tempInput) <= min){
                    System.out.println("Bad input, your max value input needs to be larger than the min value. Try again");
                    continue;
                }
                max = Integer.parseInt(tempInput);
                break;
            }
            // Create a guess from range
            int randToGuess;
            randToGuess = r.nextInt(max - min) + min;

            System.out.println("Guess what number I'm thinking of...");
            while (true){
                tempInput = getValidInput("Your guess> ");
                if(tempInput.equals("exit")) break exitProgram; else guess = Integer.parseInt(tempInput);
                guessCount++;
                if (guess == randToGuess) { // guess is correct, reset guess count and go for new game
                    System.out.println("Correct! It took you " + guessCount + " guesses.");
                    System.out.println("Lets go again.");
                    guessCount = 0;
                    break;
                }else if (guess < min || guess > max){ // guess is out of range, try again
                    System.out.println("Bad input, range needs to be between min: " + min + " max: " + max);
                    continue;
                }else if(guess > randToGuess) { // guess is too high, try again
                    System.out.println("To high");
                    continue;
                }else if (guess < randToGuess) { // guess is too low, try again
                    System.out.println("Too low");
                    continue;
                }
            }
        }
    }

    /**
     * Returns a string containing a number or the word exit.
     * @param prompt (String that is used in the console output informing user what to input)
     * @return (An Integer number as a string, or the word exit)
     */
    public static String getValidInput(String prompt) {
        Scanner input = new Scanner(System.in);
        String value;
        System.out.print(prompt);
        while(true) {
            if (input.hasNextInt()) {
                value = String.valueOf(input.nextInt());
                return value;
            }else{
                value = input.nextLine();
                if (value.equals("exit")) return value;
                System.out.println("Bad input, please try again.");
                System.out.print(prompt);
            }
        }
    }
}