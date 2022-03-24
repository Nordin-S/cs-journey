package dt196d.nosu2000.uppg07;

public class UsernamesTest {
    public static void main(String[] args) {
        String[] employees = {"Bradley Thorpe", "No St", "Arnie Cha", "Sha Maguire", "Mikolaj Crowther", "Thalia Calvert", "Charly Leal", "Iain Ruiz", "Gage Mcphee", "Keanu Valenzuela"};
        Usernames.list(employees, Usernames.create(employees));
    }
}
