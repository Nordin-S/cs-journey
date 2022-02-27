package dt196d.nosu2000.uppg05;

/**
 * This subclass creates CD an object with the information title, artist, song length and publisher class containing
 * publisher name and publisher phone.
 *
 * @author (Nordin Suleimani)
 * @version (1.0)
 */
public class CD extends Media {
    private String artist;

    /**
     * Creates an object instance of this class.
     */
    public CD() {
        super();
        this.artist = "Unknown";
    }

    /**
     * Creates an object instance of this class with the given arguments.
     *
     * @param title
     * @param artist
     * @param length
     * @param publisher
     */
    public CD(String title, String artist, int length, Publisher publisher) {
        super(title, length, publisher);
        this.artist = artist;
    }

    public void setArtist(String artist) {
        this.artist = artist;
    }

    public String getArtist() {
        return artist;
    }

    public String getLengthAsString() {
        return String.format("%02d:%02d:%02d", length / 3600, (length % 3600) / 60, (length % 60));
    }

    /**
     * Prints title, artist, song length, and the publisher name to the console
     */
    public void print() {
        super.print();
        System.out.println(
                String.format(
                        """
                        Artist: %1$s
                        Song length: %2$s
                        """, artist, getLengthAsString())
        );
    }

    /**
     * Overload of the toString method, instead returns a string containing title, artist, song length, and
     * the publisher name
     *
     * @return (returns a string containing CD title, artist, song length, publisher name and publisher phone)
     */
    @Override
    public String toString() {
        return String.format(
                """
                Artist: %1$s
                Song length: %2$s
                """,
                artist, getLengthAsString()
        );
    }
}
