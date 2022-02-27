package upg03.nosu2000.dt196g;

import java.util.Scanner;

import static java.lang.Integer.min;
import static java.lang.Integer.parseInt;

public class CDTest{
    public static void main(String[] args){
        Publisher davidMedia = new Publisher("David Media AB", "0721033200");

        CD song1 = new CD("Smyckad", "Niklas Hallman", 178, davidMedia);
        CD song2 = new CD("Våga tro", "Hedvig & Selma", 202, davidMedia);
        CD song3 = inputNewCD();

        Publisher changePublisher = new Publisher("saknas", "saknas");
        song1.setPublisher(changePublisher);

        System.out.println("--------------------------------------------------------------------");
        System.out.println("Song1:");
        song1.print();

        System.out.println("--------------------------------------------------------------------");
        System.out.print("Song2:\n" + song2);

        System.out.println("--------------------------------------------------------------------");
        System.out.println("Song3:");
        System.out.println("Title: " + song3.getTitle());
        System.out.println("Artist: " + song3.getArtist());
        System.out.println("Song length: " + secToMinSec(song3.getLength()));
        System.out.println("Publisher name: " + song3.getPublisher().getName());
        System.out.println("Publisher phone: " + song3.getPublisher().getPhone());

    }

    /**
     * Takes in an integer value representing seconds and outputs in format minutes:seconds
     * @param sec (seconds as type integer)
     * @return (returns minutes and seconds with format 00:00 as type string)
     */
    static String secToMinSec(int sec){
        int sixtySec = 60;
        int minutes = sec / sixtySec;
        int secRest = sec % sixtySec;

        String minStr = Integer.toString(minutes);
        String secStr = Integer.toString(secRest);

        // add a zero before min and secs lesser than 10
        minStr = ((minutes < 10) ? "0" + Integer.toString(minutes) : minStr);
        secStr = ((secRest < 10) ? "0" + Integer.toString(secRest) : secStr);

        String outPut = String.format("%1$s:%2$s", minStr, secStr);
        return outPut;
    }

    /**
     * Refactoring CD OBJ creation when using user input
     * @return (returns a CD object created through user input)
     */
    static CD inputNewCD(){
        String strInputMsg = "Endast alfabet förväntas som inmatning.";
        String intInputMsg = "Endast siffror förväntas som inmatning.";
        String anyInputMsg = "Fel inmatning försök igen.";

        String strRegX = "[A-Za-z ]+";
        String anyRegX = ".*";
        String intRegX = "[0-9]+";

        CD newCD = new CD();
        System.out.println("Ange song titel.");
        String inTitle = getValidInput(anyRegX, anyInputMsg);
        newCD.setTitle(inTitle);

        System.out.println("Ange artist namn.");
        String inArtist = getValidInput(anyRegX, anyInputMsg);
        newCD.setArtist(inArtist);

        System.out.println("Ange song längd(sekunder).");
        String inLength = getValidInput(intRegX, intInputMsg);
        newCD.setLength(parseInt(inLength));


        System.out.println("Ange förlagsnamn.");
        String inPublisher = getValidInput(anyRegX, anyInputMsg);
        System.out.println("Ange telefonnummer till förlaget.");
        String inPhone = getValidInput(intRegX, intInputMsg);
        newCD.setPublisher(inPublisher, inPhone);
        return newCD;
    }


    /**
     * Using scanner to retrieve a line and valdiating it according to a regex, if validation fails output a
     * error message and try again.
     * @param matchRegex (a regex to match against)
     * @param badInputMessage (message to print to console upon bad input)
     * @return (returns valid input as string)
     */
    static String getValidInput(String matchRegex, String badInputMessage){
        Scanner scannerObj = new Scanner(System.in);
        String input;

        System.out.print("Svar: ");
        while(true){
            input = scannerObj.nextLine();
            if(!input.matches(matchRegex)){
                System.out.println(badInputMessage);
                System.out.print("Svar: ");
                continue;
            }
            break;
        }
        return input;
    }
}
