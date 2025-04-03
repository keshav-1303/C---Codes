import java.util.*;
import bank.*;
// import bank.Account;

// Nmae of classes start with CAPITAL LETTERs and name og functions start with SMALL LETTERs

// 3 types of constructors--
// Name of constructor and class are same & are of no return type.
// 1. Non Parameterised - No Arguments passed.
// 2. Parameterized - Arguments passed
// 3. Copy - Copies Another 

// In C++ destructor can be written but in JAVA, They are automatically done by GARBAGE COLLECTOR.

// Polymorphism
// 1. Function Overloading (Compile Time) - Mutiple functions with same name & different Argumnets can be used.
//      Errors are caused during Compile time.
// 2. Function Overwriting (Runtime) - Errors are caused during Compile time

// Inheritence - When one class takes properties and methods of another class.
//      Class from which properties are taken --> BASE CLASS
//      Class to which properties are given --> SUB CLASS
//      4 types of Inheritence --
//          1. Single Level
//          2. Multi-Level
//          2. Multiple (Possible only through INTERFACEs)
//          3. Hierarchial
//          4. HYbrid (Hierarchial + Multiple)

// Encapsulation - Used for DATA HIDING using access modifiers (public, private, protected, default)
//      Data Hiding is the process of protecting members of class from doing unintended changes and 
//      abstraction is hiding the implementation details  and showing only important parts to  user.


class Student{

    String name;
    int age;

    public void printInfo(){
        System.out.println("Name --> " + this.name);
        System.out.println("Age --> " + this.age);
    }

    Student(){  //1.
        System.out.println("\nNon Parameterised Constructor called !!!");
    }

    Student(String name, int age){  //2.
        System.out.println("\nParameterised Constructor called !!!");
        this.name = name;
        this.age = age;
    }

    Student(Student s){  //3.
        System.out.println("\nCopy Constructor called !!!");
        this.name = s.name;
        this.age = s.age;
    }
}

class Shape{
    String colour;
    public void area(){
        System.out.println("Prints Area");
    }
}

// Triangle extends(takes properties as well as methods of Shape). 
// Now if we dont define any property of Triangle, It will still have all properties of Shape class.
class Triangle extends Shape{
    public void area(int base, int height){
        System.out.println("Area = " + 1/2*base*height);
    }
}

class Equilateral_Triangle{
    public void area(int side){
        System.out.println("Area = " + 1.73/4*side*side);
    }
}

abstract class Animal{  // abstract means it can be used in other class but cant be used directly
    abstract void walk();   // if we want that every Animal should walk 
    Animal(){
        System.out.println("\nYou are creating a new Animal");
    }
}

class Horse extends Animal{
    public void walk(){
        System.out.println("Walks on 4 legs");
    }
    Horse(){
        System.out.println("Created a Horse");
    }
}

class Chicken extends Animal{
    public void walk(){
        System.out.println("Walks on 2 legs");
    }
}

public class OOP1s {

    public static void main(String args[]){

        // CONTRUCTORS-----------------------------------------------
        Student s1 = new Student();
        s1.name = "Keshav";
        s1.age = 20;
        s1.printInfo();

        Student s2 = new Student("Lohani", 20);
        s2.printInfo();

        Student s3 = new Student(s2);
        s3.printInfo();

        //-----------------------------------------------------------
        //INHERITANCE------------------------------------------------

        Triangle t1 = new Triangle();
        t1.colour = "Blue";

        // IMPORTING PACKAGE-----------------------------------------
        // bank.Account acc1 = new Account();
        // acc1.name = "Keshav";
        //-----------------------------------------------------------

        //ENCAPSULATION----------------------------------------------

        Horse horse  = new Horse();
        horse.walk();   // this is abstraction

        // Animal a1 = new Animal();   // it is wrong bec Animal is abstract class. it is runtime error.

    }
}
