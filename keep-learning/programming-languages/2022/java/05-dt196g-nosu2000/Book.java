package dt196d.nosu2000.uppg05;

/**
 * This subclass creates book object with the information title, author, number pages and publisher class containing
 * publisher name and publisher phone.
 *
 * @author (Nordin Suleimani)
 * @version (1.0)
 */
public class Book extends Media {
    private String author;

    /**
     * Creates an object instance of this class.
     */
    public Book() {
        super();
        this.author = "Unknown";
    }

    /**
     * Creates an object instance of this class with the given arguments.
     *
     * @param title
     * @param author
     * @param length
     * @param publisher
     */
    public Book(String title, String author, int length, Publisher publisher) {
        super(title, length, publisher);
        this.author = author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public String getAuthor() {
        return author;
    }

    public String getLengthAsString() {
        return switch (length) {
            case 0 -> "0 pages";
            case 1 -> "1 page";
            default -> length + " pages";
        };
    }

    /**
     * Prints title, author, number of pages, and the publisher name to the console
     */
    public void print() {
        super.print();
        System.out.println(
                String.format(
                        """
                        Author: %1$s
                        %2$s
                        """, author, getLengthAsString())
        );
    }

    /**
     * Overload of the toString method, instead returns a string containing title, author, number of pages, and
     * the publisher name
     *
     * @return (returns a string containing book title, author, number of pages, publisher name and publisher phone)
     */
    @Override
    public String toString() {
        return String.format(
                """
                Author: %1$s
                %2$s
                """,
                author, getLengthAsString()
        );
    }
}
