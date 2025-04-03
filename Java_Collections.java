import java.util.*;

class temp{
	int data;
	temp(int data){
		this.data = data;
	}
}

public class Java_Collections {
    public static void main(String[] args) {

		// AbstractList can be used to create ArrayList, LinkedList, Vector.-----------------------------------
		AbstractList<String> list = new LinkedList<String>();

		// Using add() method to add elements in the list
		list.add("Hello");
		list.add("for");
		list.add("Hello");
		list.add("10");
		list.add("20");

		// Output the list
		System.out.println("AbstractList: " + list);

		// Remove the head using remove()
		list.remove(3);	 // 10 removed.

		list.set(2, "Keshav");

		// Print the final list
		System.out.println("Final AbstractList: " + list);

		// getting the index of last occurrence using lastIndexOf() method
		int lastindex = list.lastIndexOf("A");

		// printing the Index
		System.out.println("Last index of A : " + lastindex);

		// ArrayList------------------------------------------------------------------------------------------

		ArrayList<Integer> a1 = new ArrayList();
		// int, char cannot be type of ArrayList, we made class therefore.

		a1.add(10);
		a1.add(1, 23);

		// a1.remove(1);
		// a1.remove(new temp(10));

		Collections.sort(a1);	

		System.out.println("\nArrayList --> ");
		for(int i=0 ; i<a1.size() ; i++){
			System.out.println(a1.get(i) + " ");
		}

		// SortedMap------------------------------------------------------------------------------------------

		SortedMap<Integer, String> sortedMap = new TreeMap<>();
		// TreeMap() class is used for implementation.

		// Adding elements to the sorted map
		sortedMap.put(3, "Hello");
        sortedMap.put(2, "Hello");
        sortedMap.put(1, "Hello");
        sortedMap.put(4, "For");

		// Getting values from the sorted map
		String valueA = sortedMap.get(3);
		System.out.println("\nValue of A in SortedMap() : " + valueA);

		System.out.println(sortedMap);

		// Removing elements from the sorted map
		sortedMap.remove(3);

		System.out.println(sortedMap);

		// Iterating ---
		for (Integer key : sortedMap.keySet()) {
			// Now you can use 'key' to access the keys in the sorted map
			System.out.println("Key: " + key + ", Value: " + sortedMap.get(key));
		}	
    }    
}
