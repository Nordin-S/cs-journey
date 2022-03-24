package dt196d.nosu2000.uppg07;

import java.util.Random;
/**
 * With this class you can throw one 1-5 dices, sort the result in descending order. Check if current 5 dices
 * represent yatzy.
 */
public class Yatzy {
    private final int[] dices = new int[5];

    public Yatzy() {
        rollDices();
    }

    /**
     * Rolling all the dices, this method makes use of parameterized rollDices method by calling
     * the method with all parameters set to true.
     */
    public void rollDices(){
        rollDices(true, true, true, true, true);
    }

    /**
     * Rolls given dices chosen with a boolean argument.
     * @param rollDie1
     * @param rollDie2
     * @param rollDie3
     * @param rollDie4
     * @param rollDie5
     */
    public void rollDices(boolean rollDie1, boolean rollDie2, boolean rollDie3, boolean rollDie4, boolean rollDie5){
        Random r = new Random();
        if(rollDie1) dices[0] = r.nextInt(6) + 1;
        if(rollDie2) dices[1] = r.nextInt(6) + 1;
        if(rollDie3) dices[2] = r.nextInt(6) + 1;
        if(rollDie4) dices[3] = r.nextInt(6) + 1;
        if(rollDie5) dices[4] = r.nextInt(6) + 1;
    }

    /**
     * Checks if there is a yatzy for current dice values.
     * @return (Returns a boolean value representing yatzy state)
     */
    public boolean isYatzy(){
        for(int currentValue : dices){
            if(currentValue != dices[0])
                return false;
        }
        return true;
    }
    public void sort(){
        for (int index = 0; index < dices.length; index++){
           for(int compareIndex = index + 1; compareIndex < dices.length; compareIndex++){
               if(dices[index] < dices[compareIndex]){
                   int tempIndexValue = dices[index];
                   dices[index] = dices[compareIndex];
                   dices[compareIndex] = tempIndexValue;
               }
           }
        }
    }

    @Override
    public String toString() {
        return String.format("%d %d %d %d %d", dices[0], dices[1], dices[2], dices[3], dices[4]);
    }
}
