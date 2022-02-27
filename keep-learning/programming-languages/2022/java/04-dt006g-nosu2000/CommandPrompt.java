package dt196g.nosu2000.uppg04;

import java.util.Scanner;

/**
 * Assignment 4, part 2 - CommandPrompt
 * This application simulates a simple CommandPrompt, capable of outputting a help menu,
 * printing Hello World! in console, checking if a number is odd or even, repeat a given string as many times as
 * specified, using arithmetic operators to calculate with two operands and lastly quits the application.
 * @AUTHOR (NORDIN SULEIMANI)
 * @VERSION (1.0)
 */

public class CommandPrompt {
    public static final String PROMPT = "input>";
    public static final String SEPARATOR = "======================================================================";
    private static final Scanner input = new Scanner(System.in);

    public static void main(String[] args) {
        start();
    }

    /**
     * Takes in valid commands and calls specific methods
     */
    public static void start() {
        do {
            System.out.print(PROMPT);

            switch (input.nextLine()) {
                case "hello" -> hello();
                case "odd" -> odd();
                case "calc", "calculate" -> calculate();
                case "repeat" -> repeat();
                case "q", "quit" -> quit();
                case "h", "help" -> help();
                default -> {
                    System.out.println("Unknown command, below are the accepted commands.");
                    System.out.println(SEPARATOR);
                    help();
                }
            }
        } while (true);
    }

    /**
     * Simply prints a help info about possible commands.
     */
    private static void help() {
        //Display Help
        String tempStr = """
                Help Menu, possible commands to run with this program.
                Commands:
                hello                  Prints "Hello World!" in the console.
                odd                    Takes in a number and prints odd or even in the console depending on the number.
                calc|calculate         Takes in two numbers and a operator(+, -, /, *, % or **), then performs the calculation.
                repeat                 Takes in a string and a number and prints the string as many times as the number.
                q|quit                 Quits the application.
                h|help                 Prints this help menu.""";
        System.out.println(tempStr);
        System.out.println(SEPARATOR);
    }

    /**
     * prints Hello World! in console.
     */
    private static void hello() {
        System.out.println("Hello World!");
        System.out.println(SEPARATOR);
    }

    /**
     * Asks for a number and figurs out if the number is odd or even.
     */
    private static void odd() {
        while (true)
            try {
                System.out.print("Enter a number: ");
                int num = Integer.parseInt(input.nextLine());
                System.out.println(num % 2 == 1 ? "Your number is Odd" : "Your number is even");
                break;
            } catch (NumberFormatException e) {
                System.out.println("Bad input, expecting an integer. Try again.");
            }
        System.out.println(SEPARATOR);
    }

    /**
     * Asks for a string and number of times to repeat that string and douse just that.
     */
    private static void repeat() {
        System.out.println("Enter a string: ");
        String tempStr = input.nextLine();

        int tempInt;
        while (true)
            try {
                System.out.print("Number of times to print the string: ");
                tempInt = Integer.parseInt(input.nextLine());
                break;
            } catch (NumberFormatException e) {
                System.out.println("Bad input, expecting an integer. Try again.");
            }
        for (int i=1; i <= tempInt; i++){
            System.out.println(tempStr);
        }
        System.out.println(SEPARATOR);
    }

    /**
     * Takes in two operands and an operator and performs an arithmetic operation.
     */
    private static void calculate() {
        System.out.println("To perform this operation you have to enter 2 operands and one operator.");
        double firstOperand;
        while (true)
            try {
                System.out.print("Enter first operand: ");
                firstOperand = Double.parseDouble(input.nextLine());
                break;
            } catch (NumberFormatException e) {
                System.out.println("Bad input, try again. " + e);
            }

        String operator;
        while (true) {
            System.out.print("Enter the operator: ");
            operator = input.nextLine();
            if(operator.equals("-") || operator.equals("+") || operator.equals("/") || operator.equals("*") || operator.equals("%") || operator.equals("**")) {
                break;
            }
            System.out.println("Bad input, try again.");
        }

        double secondOperand;
        while (true)
            try {
                System.out.print("Enter second operand: ");
                secondOperand = Double.parseDouble(input.nextLine());
                //if operator is division or modulo and second operator is 0 retry input for second operator.
                if(secondOperand == 0){
                    if(operator.equals("/")) {
                        System.out.println("Try again, division by zero is undefined!");
                        continue;
                    }
                    if(operator.equals("%")) {
                        System.out.println("Try again, modulos by zero is undefined!");
                        continue;
                    }
                }
                break;
            } catch (NumberFormatException e) {
                System.out.println("Bad input, try again. " + e);
            }

        switch (operator) {
            case "-" -> System.out.println(firstOperand + " - " + secondOperand + " = " + (firstOperand - secondOperand));
            case "+" -> System.out.println(firstOperand + " + " + secondOperand + " = " + (firstOperand + secondOperand));
            case "/" -> System.out.println(firstOperand + " / " + secondOperand + " = " + (firstOperand / secondOperand));
            case "*" -> System.out.println(firstOperand + " * " + secondOperand + " = " + (firstOperand * secondOperand));
            case "%" -> System.out.println(firstOperand + " % " + secondOperand + " = " + (firstOperand % secondOperand));
            case "**" -> System.out.println(firstOperand + " ** " + secondOperand + " = " + Math.pow(firstOperand, secondOperand));
            default -> System.out.println("Bad input, something went wrong.");
        }
        System.out.println(SEPARATOR);
    }

    /**
     * Ends this application.
     */
    public static void quit() {
        System.exit(0);
    }

}
