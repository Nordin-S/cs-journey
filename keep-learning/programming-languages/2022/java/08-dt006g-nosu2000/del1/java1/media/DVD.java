package java1.media;

/**
 * This subclass creates DVD an object with the information title, age limit, DVD length and publisher class containing
 * publisher name and publisher phone.
 *
 * @author (Nordin Suleimani)
 * @version (1.0)
 */
public class DVD extends Media {
    private int ageLimit;

    /**
     * Creates an object instance of this class.
     */
    public DVD() {
        super();
        this.ageLimit = 0;
    }

    /**
     * Creates an object instance of this class with the given arguments.
     *
     * @param title
     * @param ageLimit
     * @param length
     * @param publisher
     */
    public DVD(String title, int ageLimit, int length, Publisher publisher) {
        super(title, length, publisher);
        this.ageLimit = Math.max(ageLimit, 0);
    }

    public void setAgeLimit(int ageLimit) {
        this.ageLimit = Math.max(ageLimit, 0);
    }

    public int getAgeLimit() {
        return ageLimit;
    }

    public String getLengthAsString() {
        return String.format("%02dh %02dm %02ds", length / 3600, (length % 3600) / 60, (length % 60));
    }

    /**
     * Prints title, age limit, DVD length, and the publisher name to the console
     */
    public void print() {
        super.print();
        System.out.println(
                String.format(
                        """
                        Age limit: %1$s
                        DVD length: %2$s
                        """, ageLimit, getLengthAsString())
        );
    }

    /**
     * Overload of the toString method, instead returns a string containing title, artist, song length, and
     * the publisher name
     *
     * @return (returns the title, age limit, DVD length, publisher name and publisher phone)
     */
    @Override
    public String toString() {
        return String.format(
                """
                Age limit: %1$s
                DVD length: %2$s
                """,
                ageLimit, getLengthAsString()
        );
    }
}
