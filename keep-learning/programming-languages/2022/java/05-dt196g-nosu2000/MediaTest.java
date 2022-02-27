package dt196d.nosu2000.uppg05;

import java.util.Scanner;

/**
 *
 */
public class MediaTest {
    public static void main(String[] args) {
        Publisher davidMedia = new Publisher("David Media AB", "0704126534");
        Publisher HarperCollins = new Publisher("HarperCollins UK", "0734523422");

        DVD firstDVD = new DVD("James Bond", 16, 5232, davidMedia);

        DVD secondDVD = new DVD();

        CD firstCD = new CD("Smyckad", "Niklas Hallman", 178, davidMedia);
        CD secondCD = new CD("Georgia", "Emily King", 230, davidMedia);

        Book firstBook = new Book("Algorithms to Live By", "Brian Christian & Tom Griffiths", -4, HarperCollins);
        Book secondBook = new Book("Fahrenheit 451", "Ray Bradbury", 1, HarperCollins);


        System.out.println("------------------------------DVD-----------------------------------");
        System.out.println("firstDVD print():");
        firstDVD.print();
        System.out.print("firstDVD toPrint():\n" + firstDVD);

        enterToContinue();
        System.out.println("--------------------------------------------------------------------");
        System.out.println("secondDVD getters():");
        secondDVD.setTitle("Dune");
        secondDVD.setAgeLimit(-3);
        secondDVD.setLength(2334);
        secondDVD.setPublisher("Warner Bros. Pictures", "0724252312");
        System.out.println("Title: " + secondDVD.getTitle());
        System.out.println("Age limit: " + secondDVD.getAgeLimit());
        System.out.println("DVD length: " + secondDVD.getLengthAsString());
        System.out.println("Publisher: " + secondDVD.getPublisher().getName());
        System.out.println("Publisher phone: " + secondDVD.getPublisher().getPhone());

        System.out.println();
        System.out.print("secondDVD print():\n");
        secondDVD.print();
        System.out.print("secondDVD toString():\n" + secondDVD);

        enterToContinue();
        System.out.println("-----------------------------CD-----------------------------------");
        System.out.println("firstCD print():");
        firstCD.print();
        System.out.print("firstCD toPrint():\n" + firstCD);

        enterToContinue();
        System.out.println("--------------------------------------------------------------------");
        System.out.println("secondCD getters():");
        secondCD.setTitle("Georgia");
        secondCD.setArtist("Emily king");
        secondCD.setLength(230);
        secondCD.setPublisher("Warner Bros. Pictures", "0724252312");
        secondCD.setPublisher(davidMedia);
        System.out.println("Title: " + secondCD.getTitle());
        System.out.println("Artist: " + secondCD.getArtist());
        System.out.println("CD length: " + secondCD.getLengthAsString());
        System.out.println("Publisher: " + secondCD.getPublisher().getName());
        System.out.println("Publisher phone: " + secondCD.getPublisher().getPhone());
        System.out.println();
        System.out.print("secondCD print():\n");
        secondCD.print();
        System.out.print("secondCD toString():\n" + secondCD);

        enterToContinue();
        System.out.println("----------------------------Book---------------------------------");
        System.out.println("firstBook print():");
        firstBook.print();
        System.out.print("firstBook toPrint():\n" + firstBook);

        enterToContinue();
        System.out.println("--------------------------------------------------------------------");
        System.out.println("secondBook getters():");
        secondBook.setTitle("Georgia");
        secondBook.setAuthor("Emily king");
        secondBook.setLength(1);
        secondBook.setPublisher("Warner Bros. Pictures", "0724252312");
        secondBook.setPublisher(davidMedia);
        System.out.println("Title: " + secondBook.getTitle());
        System.out.println("Artist: " + secondBook.getAuthor());
        System.out.println("CD length: " + secondBook.getLengthAsString());
        System.out.println("Publisher: " + secondBook.getPublisher().getName());
        System.out.println("Publisher phone: " + secondBook.getPublisher().getPhone());
        System.out.println();
        System.out.print("secondBook print():\n");
        secondBook.print();
        System.out.print("secondBook toString():\n" + secondBook);
    }

    public static void enterToContinue(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("================== Hit \"ENTER\" to continue... ==================");
        scanner.nextLine();
    }
}
