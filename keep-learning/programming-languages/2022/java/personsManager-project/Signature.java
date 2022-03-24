package se.miun.nosu2000;

/**
 * @author (Nordin Suleimani)
 * @version (1.0)
 */
public class Signature {
    private static final int SIG_CHAR_LIMIT = 3;
    private static final char CHAR = 'x';

    /**
     * Creates a signature from firstname and lastname by using n letters from each
     * if firstname or lastname is shorter than n chars x is added, e.g. tomjxx
     * @param firstName String firstname
     * @param lastName String lastname
     * @return returns a string in the form yyyzzz, n letters from firstname and n from lastname
     */
    public static String make(String firstName, String lastName) {

        // if firstname and lastname is longer than n chars substring to n chars. Trim for spaces
        if (firstName.length() > SIG_CHAR_LIMIT)
            firstName = firstName.substring(0, SIG_CHAR_LIMIT).trim();
        if (lastName.length() > SIG_CHAR_LIMIT)
            lastName = lastName.substring(0, SIG_CHAR_LIMIT).trim();

        // if firstname and lastname is now shorter than n chars add x's at end of each
        if (firstName.length() < SIG_CHAR_LIMIT) firstName = addCharAtEnd(firstName);
        if (lastName.length() < SIG_CHAR_LIMIT) lastName = addCharAtEnd(lastName);

        return (firstName + lastName).toLowerCase();
    }

    /**
     * Adds the letter x at the end of a string shorter than n chars
     * @param str String to add x's to
     * @return returns a string
     */
    private static String addCharAtEnd(String str) {
        StringBuilder strBuilder = new StringBuilder(str);

        // add as many x's as needed for string to be n chars long
        while (strBuilder.length() < SIG_CHAR_LIMIT) {
            strBuilder.append(CHAR);
        }
        str = strBuilder.toString();
        return str;
    }
}
