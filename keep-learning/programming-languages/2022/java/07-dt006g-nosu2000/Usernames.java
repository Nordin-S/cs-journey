package dt196d.nosu2000.uppg07;
import java.util.ArrayList;

/**
 * This class takes a set of fullnames and turns each one into a username by cutting down name and lastname if
 * larger than three characters, to lowercase and concatenates them without a space between, e.g "John Doe" too "johdoe"
 */
public class Usernames {
    /**
     * @param fullNames (A list of full names given in an array)
     * @return (Returns an arraylist with each full name as a abbreviated and concatenated username.
     */
    public static ArrayList<String> create(String[] fullNames) {
        final int CHAR_NUM = 3;
        final String DELIMITER = " ";
        ArrayList<String> result = new ArrayList<>();
        // list of fullnames to list of usernames
        for (String CurrentFullName : fullNames){
            String firstName = CurrentFullName.substring(0, CurrentFullName.indexOf(DELIMITER));
            String lastName = CurrentFullName.substring(CurrentFullName.indexOf(DELIMITER) + 1);
            if (firstName.length() > CHAR_NUM)
                firstName = firstName.substring(0, CHAR_NUM);

            if (lastName.length() > CHAR_NUM)
                lastName = lastName.substring(0, CHAR_NUM);

            result.add((firstName + lastName).toLowerCase());
        }
        return result;
    }

    /**
     * Prints a list of full names with the corresponding username on separate lines on the console.
     * @param names List of full names in the array datatype
     * @param userName An arraylist of usernames for each full names
     */
    public static void list(String[] names, ArrayList<String> userName) {
        for (int currentPerson = 0; currentPerson < names.length; currentPerson++) {
            System.out.println(names[currentPerson] + " (" + userName.get(currentPerson) + ")");
        }
    }
}