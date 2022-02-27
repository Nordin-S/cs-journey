package upg03.nosu2000.dt196g;

/**
 * This class creates cd with the information title, artist, song length publisher class containing
 * publisher name and publisher phone.
 * The model keeps track of how many instances that has been created.
 * This class will teach us how to create a class and object instances of a class,
 * How to create constructors, methods and overloaded methods
 * @author (Nordin Suleimani)
 * @version (1.0)
 */
public class CD {
    private String title, artist;
    private int length;
    private Publisher publisher;

    /**
     * Creates an object instance of this class.
     */
    public CD() {
        this.title = "";
        this.artist = "";
        this.length = 0;
        this.publisher = null;
    }

    /**
     * Creates an object instance of this class with the given arguments.
     * @param title
     * @param artist
     * @param length
     * @param publisher
     */
    public CD(String title, String artist, int length, Publisher publisher) {
        this.title = title;
        this.artist = artist;
        this.length = length;
        this.publisher = publisher;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public void setArtist(String artist) {
        this.artist = artist;
    }

    public void setLength(int length) {
        this.length = length;
    }

    public void setPublisher(Publisher publisher) {
        this.publisher = publisher;
    }
    public void setPublisher(String name, String phone) {
        this.publisher = new Publisher(name, phone);
    }

    public String getTitle() {
        return title;
    }

    public String getArtist() {
        return artist;
    }

    public int getLength() {
        return length;
    }

    public Publisher getPublisher() {
        return publisher;
    }

    /**
     * Prints title, artist, song length, and the publisher name to the console
     */
    public void print(){
        System.out.println("Title: " + title);
        System.out.println("Arist: " + artist);
        System.out.println("Song length: " + length);
        System.out.println("Publisher name: " + publisher.getName());
    }

    /**
     * Overload of the toString method, instead returns a string containing title, artist, song lenght, and
     * the publisher name
     * @return (returns the title, artist, song length, publisher name and publisher phone )
     */
    @Override
    public String toString(){
        String outPut = String.format(
            """
                Title: %1$s
                Artist: %2$s
                Song length: %3$s
                Publisher name: %4$s
                Publisher phone %5$s
            """,
            title, artist, length, publisher.getName(), publisher.getPhone()
        );
        return outPut;
    }
}
