package se.miun.nosu2000;

/**
 * @author (Nordin Suleimani)
 * @version (1.0)
 */
public class Person {
    private String firstName;
    private String lastName;
    private String signature;
    private int length;
    protected Address address;

    /**
     * Creates an object instance of this class.
     */
    public Person() {
        this.firstName = "";
        this.lastName = "";
        this.signature = "";
        this.length = 0;
        this.address = null;
    }


    /**
     * Creates an object instance of this class with the given arguments.
     * @param firstName
     * @param lastName
     * @param length
     * @param signature
     * @param address
     */
    public Person(String firstName, String lastName, int length, String signature, Address address) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.signature = signature;
        this.length = Math.max(length, 0);
        this.address = address;
    }

    public void setFirstName(String firstName)  {
        this.firstName = firstName;
    }
    public void setLastName(String lastName)  {
        this.lastName = lastName;
    }
    public void setSignature(String signature)  {
        this.signature = signature;
    }

    public void setLength(int length) {
        this.length = Math.max(length, 0);
    }

    public void setAddress(Address address) {
        this.address = address;
    }

    public void setAddress(String postAddress, String zipCode, String postTown) {
        this.address = new Address(postAddress, zipCode, postTown);
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }
    public String getSignature() {
        return signature;
    }
    public int getLength() {
        return length;
    }
    public double getLengthInMeter() {
        return length * 0.01;
    }
    public Address getAddress() {
        return address;
    }

   // used for sorting, after lastname and then firstname
    public String getLastNameFirstName() {
       return (lastName + firstName).toLowerCase();
    }
    public String getLastNameFirstNameLength() {
        return (lastName + firstName + length).toLowerCase();
    }
}