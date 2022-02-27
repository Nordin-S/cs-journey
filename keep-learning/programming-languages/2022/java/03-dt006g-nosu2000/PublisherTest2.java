package upg03.nosu2000.dt196g;

import javax.swing.*;

public class PublisherTest2 {
    public static void main(String[] args) {
        Publisher bonniers2 = new Publisher();

        String name = JOptionPane.showInputDialog("Ange förlagsnamn.");
        String phone = JOptionPane.showInputDialog("Ange förlagets telefon nummer.");

        bonniers2.setName(name);
        bonniers2.setPhone(phone);

        JOptionPane.showMessageDialog(null, bonniers2);
    }
}
