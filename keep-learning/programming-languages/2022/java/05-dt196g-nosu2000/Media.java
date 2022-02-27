package dt196d.nosu2000.uppg05;

/**
 * This superclass can be used to extend subclasses such as CD, DVD, Book etc with title, length and a publisher class containing
 * publisher name and publisher phone.
 * The model keeps track of how many instances that has been created.
 * This class will teach us how to create a class and object instances of a class, superclass/subclasses/extending/inheritance
 * How to create constructors, methods and overloaded methods
 *
 * @author (Nordin Suleimani)
 * @version (1.0)
 */
public class Media {
    protected String title;
    protected int length;
    protected Publisher publisher;

    /**
     * Creates an object instance of this class.
     */
    public Media() {
        this.title = "";
        this.length = 0;
        this.publisher = null;
    }

    /**
     * Creates an object instance of this class with the given arguments.
     *
     * @param title
     * @param length
     * @param publisher
     */
    public Media(String title, int length, Publisher publisher) {
        this.title = title;
        this.length = Math.max(length, 0);
        this.publisher = publisher;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public void setLength(int length) {
        this.length = Math.max(length, 0);
    }

    public void setPublisher(Publisher publisher) {
        this.publisher = publisher;
    }

    public void setPublisher(String name, String vphone) {
        this.publisher = new Publisher(name, vphone);
    }

    public String getTitle() {
        return title;
    }

    public int getLength() {
        return length;
    }

    public Publisher getPublisher() {
        return publisher;
    }

    /**
     * Prints title and the publisher name to the console
     */
    public void print() {
        System.out.println("Title: " + title);
        System.out.println("Publisher: " + publisher.getName());
    }

    /**
     * Overload of the toString method, instead returns a string containing title, media length, and
     * the publisher name
     *
     * @return (returns the title, media length, publisher name and publisher phone)
     */
    @Override
    public String toString() {
        return String.format(
                """
                Title: %1$s
                Media length: %2$s
                Publisher: %3$s
                Publisher phone %4$s
                """,
                title, length, publisher.getName(), publisher.getPhone()
        );
    }
}
