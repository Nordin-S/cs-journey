package se.miun.nosu2000;

/**
 * @author (Nordin Suleimani)
 * @version (1.0)
 */
public class Address {

    private String postAddress;
    private String zipCode;
    private String postTown;

    /**
     * Creates an address instance containing address information
     * @param postAddress String post address
     * @param zipCode String zip code
     * @param postTown String post town
     */
    public Address(String postAddress, String zipCode, String postTown) {
        this.postAddress = postAddress;
        this.zipCode = zipCode;
        this.postTown = postTown;
    }
    
    public String getPostAddress() {
        return postAddress;
    }

    public void setPostAddress(String postAddress) {
        this.postAddress = postAddress;
    }

    public String getZipCode() {
        return zipCode;
    }

    public void setZipCode(String zipCode) {
        this.zipCode = zipCode;
    }

    public String getPostTown() {
        return postTown;
    }

    public void setPostTown(String postTown) {
        this.postTown = postTown;
    }
}