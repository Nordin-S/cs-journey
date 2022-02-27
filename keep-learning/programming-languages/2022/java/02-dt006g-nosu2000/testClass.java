package upg02.nosu2000.dt196g;
import javax.swing.*;

/**
 *  Users Course class to create to course instances, setting ones attribute with constructor and
 *  the other ones with setters using JOptionPane.
 */
public class testClass{
    public static void main(String[] args){
        Course myCourse = new Course("DT196G", "Java I", "7.5", "Beskrivning...");
        myCourse.setCourseDesc("Java är ett objektorienterat och plattformsoberoende språk som kan användas för att skapa \n" +
                "integrerade eller fristående applikationer för datorsystem, webb och handhållna enheter. \n" +
                "Kursen lär ut grundläggande, allmängiltiga begrepp inom programmering, såsom variabler,\n" +
                "metoder och styrsatser. Dessutom introduceras även grundläggande begrepp i \n" +
                "objektorienterad programmering.\n");

        // using system.out to print the override of object.toString and a method to do the same.
//        System.out.println(myCourse);
        myCourse.print();


        Course myCourse2 = new Course();
        String courseName = JOptionPane.showInputDialog("Ange kursnamn!");
        String courseId = JOptionPane.showInputDialog("Ange Kursid!");
        String coursePoints = JOptionPane.showInputDialog("Ange kurspoäng!");
        String courseDesc = JOptionPane.showInputDialog("Ange kursbeskrivning!");

        myCourse2.setCourseId(courseName);
        myCourse2.setCourseName(courseId);
        myCourse2.setCoursePoints(coursePoints);
        myCourse2.setCourseDesc(courseDesc);

        JOptionPane.showMessageDialog(null, myCourse2);

    }
}