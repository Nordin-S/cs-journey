package upg03.nosu2000.dt196g;

/**
 * This class can create publishers with the information name and phone.
 * The model keeps track of how many instances that has been created.
 * This class will teach us how to create a class and object instances of a class,
 * How to create constructors, methods and overloaded methods and lastly
 * how to use static members in a class.
 * @author (Nordin Suleimani)
 * @version (1.0)
 */
public class Publisher {
    private String name, phone;
    private static int nrOfPublishers;

    /**
     * Creates an object instance of this class and tracks number of instances created.
     */
    public Publisher(){
        this.name = "";
        this.phone = "";
        Publisher.nrOfPublishers++;
    }

    /**
     * Creates an object instance of this class with the given arguments and tracks number of instances created.
     * @param name (the name of the publisher)
     * @param phone (the phone number of the publisher)
     */
    public Publisher(String name, String phone){
        this.name = name;
        this.phone = phone;
        Publisher.nrOfPublishers++;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    /**
     * Prints the name and the phone of this publisher to the console
     */
    public void print(){ System.out.println("Name: " + name + " Phone:" + phone); }

    /**
     * Overload of the toString method, instead returns a string containing name and phone of this publisher
     * @return (returns the name and phone number of this publisher)
     */
    @Override
    public String toString(){
        return name + ":" + phone;
    }

    /**
     * @return (an int representing current number of instances created with the class model)
     */
    public static int getNrOfPublishers() {
        return nrOfPublishers;
    }
}
