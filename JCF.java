import java.util.*;
import java.io.*;

public class JCF {

    public static void main(String[] args) {

        int n = 5;

        // ArrayList------------------------------------------------------>

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

        //---------------------------------------------------------------->
        //VECTORs--------------------------------------------------------->

        Vector<Integer> v = new Vector<Integer>();
        for (int i=0 ; i<n; i++){
            v.add(i + 1);   // for adding elements at end of vector
        }
        // System.out.println(v);
        v.remove(2);    // removes elemnt at index 2
        v.set(2, 10);    // replaces elemnt at index 2 with value 10
        v.insertElementAt(10, 2);    // inserts elemnt at index 2 with value 10
        for (int i=0 ; i<v.size(); i++){
            System.out.print(v.get(i) + " ");   //v[i] is invalid
        }
        System.out.print("\n");

        Vector<Integer> vect = new Vector<Integer>(5, 2);
        System.out.println(vect);


    }   
}
