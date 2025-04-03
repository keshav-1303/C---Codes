// import java.util.Arrays;
// import java.util.ArrayList;
// import java.util.Collections;
import java.util.*;
import java.io.*;

public class Basics {
    
    public static int SUM(int a, int b){
        int sum = a + b;
        return sum;
    }
    public static void main(String[] args) {

        System.out.println("Hello");
        //*** type sout for printing whole output line ***

        //Primitive Types--->
        byte age = 30;
        long num = 12345678L;
        float pi = 3.14F;
        char ch = 'a';
        boolean flag = true;

        //Non-Primitive types-->
        String str = "keshav";
        System.out.println(str.length());

        //Strings in JAVA------------------------------------------>
        String name1 = "kashav";
        String name2 = "lohani";
        String res = name1 + " and " + name2;
        System.out.println(res); 
 
        for(int i=0 ; i<res.length() ; i++){
            System.out.print(res.charAt(i));
        }System.out.println("\n");

        String replaced = name1.replace('a', 'b');   // replaces every occurence of 'a' with 'b'.
        System.out.println(replaced);

        String str1 = name1.substring(2, 6);    // beginIndex is included, endIndex is not
        System.out.println(str1);

        //--------------------------------------------------------->
        //ARRAYs in JAVA ------------------------------------------>

        int[] marks = new int[5];   // if value not given , automatically 0 is assigned
        marks[0] = 45;
        marks[1] = 32;
        marks[2] = 12;
        marks[3] = 82;
        marks[4] = 98;

        Arrays.sort(marks);

        for(int i=0 ; i<5 ; i++){
            System.out.print(marks[i]);
            System.out.print(" ");
        }
        System.out.print("\n");

        int[][] arr = {{1, 2}, {3, 4}};

        //--------------------------------------------------------->
        //CASTING-------------------------------------------------->

        int p = 100;
        int q = p + (int)18.18;
        System.out.println("q = " + q);

        final float PI = 3.14F;     // Now value of PI CANNOT BE CHANGED.

        //MATH CLASS ---------------------------------------------->

        System.out.println("Maximum of 5 and 6 = " + (Math.max(5, 6)));
        System.out.println("Minimum of 5 and 6 = " + (Math.min(5, 6)));
        System.out.println("Random gives any Random b/w 0.0 to 1.0 : " + (Math.random()));
        // for any random b/w 0 and 100;
        System.out.println("Random integer b/w 0 to 100 : " + (int)(Math.random()*100));

        // INPUTs in JAVA ----------------------------------------->

        // Scanner input = new Scanner(System.in);
        // System.out.print("Enter a number : ");
        // int number = input.nextInt();
        // System.out.println("Entered number = " + number);

        // System.out.print("Enter s string : ");
        // String s = input.next();    //Dont take input after space
        // String s1 = input.nextLine();    //Takes input after space too
        // System.out.println("Entered string = " + s);

        //EXCEPTION HANDLING --------------------------------------->

        int []array = {1, 2, 3};
        try{        // If exception is caught, what to do will be written in catch
            System.out.println(array[5]);
        }
        catch(Exception exception){
            System.out.println("Exception caught");
        }
        System.out.println("Exception Handling Successful");

        //FUNCTIONs ------------------------------------------------>

        int a = 100, b = 234;
        System.out.println("Sum of " + a + " and " + b + " = " + SUM(a, b));

        // JAVA COLLECTIONS FRAMEWORK ------------------------------>

        ArrayList<Integer> list = new ArrayList<>();
        list.add(3);
        list.add(1);
        list.add(2);
        System.out.println(list.get(0));    //get elements
        list.add(1, 7);   //inserts 7 at index 1
        list.set(0, 5);    // set element at index o to 5; 
        System.out.println(list);
        list.remove(3);    // deletes element at index 3
        System.out.println(list);
        System.out.println("Size of list = " + list.size());
        Collections.sort(list);
        for(int i=0 ; i<list.size() ; i++){
            System.out.print(list.get(i) + " ");
        }
        System.out.print("\n");
    }
}
