package dt196d.nosu2000.uppg07;

public class YatzyTest {
    public static void main(String[] args) {
        Yatzy yatzyObj = new Yatzy();
        System.out.println("Rolling all dices...");
        System.out.println(yatzyObj);

        System.out.println("\nRolling dices 4 and 5...");
        yatzyObj.rollDices(false, false, false, true, true);
        System.out.println(yatzyObj);

        System.out.println("\nSorting the dices...");
        yatzyObj.sort();
        System.out.println(yatzyObj);

        System.out.print("\nChecking for Yatzy...");
        if(yatzyObj.isYatzy()){
            System.out.println("\nAwesome, " + yatzyObj + " is Yatzy!");
        }else{
            System.out.println("\nSorry, " + yatzyObj + " is not Yatzy!");
        }
    }
}
