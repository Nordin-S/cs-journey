package upg03.nosu2000.dt196g;

public class PublisherTest1 {
    public static void main(String[] args) {
        System.out.println(Publisher.getNrOfPublishers()); // should print 0

        Publisher bonniers = new Publisher("Bonniers", "0734446601");
        bonniers.print();
        System.out.println(bonniers); // testing toString @override

        Publisher liber = new Publisher();
        liber.setName("Liber");
        liber.setPhone("0721112233");
        System.out.println(liber);

        Publisher liber2 = new Publisher();
        liber2.setName(liber.getName());
        liber2.setPhone(liber.getPhone());
        System.out.println("liber2: " + liber2);
        System.out.println(Publisher.getNrOfPublishers()); // should print 3

    }
}
