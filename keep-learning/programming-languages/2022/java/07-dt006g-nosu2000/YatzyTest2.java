package dt196d.nosu2000.uppg07;

public class YatzyTest2 {
    public static void main(String[] args) {
        final int THROWS = 10_000_000;
        int yatziesGotten = 0;
        Yatzy yatzyObj = new Yatzy();

        System.out.print("Rolling the dices " + THROWS + " times... ");
        // time before loop starts
        long startTime = System.currentTimeMillis();
        //roll dices given amount of times and count how many times yatzy is thrown
        for (int currentThrow = 0; currentThrow < THROWS; currentThrow++){
            yatzyObj.rollDices();
            if(yatzyObj.isYatzy())
                yatziesGotten++;
        }
        // time take for loop
        long loopTime = System.currentTimeMillis() - startTime;
        System.out.println(loopTime + " ms");
        double precentage = ((yatziesGotten/(double)THROWS)*100);
        System.out.printf("Number of yatzy: %d (%.4f%%)", yatziesGotten, precentage);
    }
}
