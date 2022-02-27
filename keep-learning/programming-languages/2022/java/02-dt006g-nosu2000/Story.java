package upg02.nosu2000.dt196g;

import java.util.Scanner;

public class Story {
    public static void main(String[] args){
        String antName, partner, siblingNum, location, carryIn1, carryIn2, specialDay, outPut;
        String strInputMsg = "Endast alfabet förväntas som inmatning.";
        String intInputMsg = "Endast siffror förväntas som inmatning.";
        String strRegX = "[A-Za-z]+";
        String intRegX = "[0-9]+";


        System.out.println("Hej och välkommen till saga generatorn.");
        System.out.println("Vänligen svara på följande frågor för att generera en saga.\n");

        System.out.println("Namnet på myran?");
        antName = getValidInput(strRegX, strInputMsg);

        System.out.println("Vem myran bor med?");
        partner = getValidInput(strRegX, strInputMsg);

        System.out.println("Hur många syskon som myran har?");
        siblingNum = getValidInput(intRegX, intInputMsg);

        System.out.println("Var någonstans i skogen myrstacken finns?");
        location = getValidInput(strRegX, strInputMsg);

        System.out.println("Vad myran och syskonen bär in till stacken?");
        carryIn1 = getValidInput(strRegX, strInputMsg);

        System.out.println("Vad myran och syskonen mer bär in till stacken?");
        carryIn2 = getValidInput(strRegX, strInputMsg);

        System.out.println("Vad det är för speciell dag som gör att myran är ledig?");
        specialDay = getValidInput(strRegX, strInputMsg);

        outPut = String.format("Den lilla myran %1$s\n\n" +
                        "Det var en gång en liten, liten myra som bodde med sin %2$s och sina \n" +
                        "%3$s syskon i en myrstack, vid en stor %4$s i skogen. Den lilla \n" +
                        "myran hette %1$s. För det mesta brukade %1$s och hans syskon arbeta \n" +
                        "med att bära in %5$s och %6$s till stacken, men idag var det %7$s, \n" +
                        "så därför var %1$s ledig.",
                        antName, partner, siblingNum, location, carryIn1, carryIn2, specialDay);

        System.out.println(outPut);
    }

    /**
     * Using scanner to retrieve a line and valdiating it according to a regex, if validation fails output a
     * error message and try again.
     * @param matchRegex
     * @param badInputMessage
     * @return
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
