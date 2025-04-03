import java.util.*;

//Interface should not contain any non-abstract function
interface Animal{
    void walk();
} 

interface Herbivore{
    void eats();
}

class Horse implements Animal, Herbivore {

    public void walk(){
        System.out.println("Walks on 4 legs");
    }
    public void eats(){
        System.out.println("Horse eats only Vegetables");
    }
}

// Understanding STATIC KEYWORD
// Static is given MENORY only once, all other objects are given when new object is created
// Thus, it also helps in SAVING MEMORY.

class Student{
    String name;
    static String school;    // means school will be same for all Student members, it can't be altered

    public static void changeschool(){   // Used to change schol name of all students if declared earlier
        school = "New School";
    } 
}

public class OOPs2 {
    public static void main(String[] args) {

        Horse horse = new Horse();
        horse.walk();
        horse.eats();

        Student.school = "Holy Hearts";    // school is class's object, so no need to make new Student for this
        Student s1 = new Student();
        s1.name = "Keshav";
        System.out.println("\nName --> " + s1.name);
        System.out.println("School --> " + s1.school);

    }
}
