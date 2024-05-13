#include <bits/stdc++.h>
using namespace std;

// Ordered Set - All same as SET in C++, but provides 2 extra functions:
//    1. order_of_key(X) - No of elements smaller than X in set in O(log N).
//    2. find_by_order(X) - Finding element present at Xth index in O(log N).

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OS;
// int -> data type of pbds
// less<int> -> comparator i.e stores in ascending order.
// rb_tree_tag -> implementation used (red-black tree here).
// OS (ordered set) -> name of data structure (can be anything).

int main(){

    OS A; // declaration

	// Inserting elements - 1st query
	A.insert(1);
	A.insert(10);
	A.insert(2);
	A.insert(7);
	A.insert(2);  // ordered set only contains unique values

	cout << "A contains : " << endl;
	cout << "A = ";
	for (auto i : A)
		cout << i << " ";
	cout << endl;
	cout << endl;

	// finding kth element - 4th query
	cout << "0th element: " << *A.find_by_order(0) << endl;
	cout << "1st element: " << *A.find_by_order(1) << endl;
	cout << "2nd element: " << *A.find_by_order(2) << endl;
	cout << "3rd element: " << *A.find_by_order(3) << endl;
	cout << endl;

	// finding number of elements smaller than X - 3rd query
	cout << "No. of elements smaller than 6: " << A.order_of_key(6) << endl; // 2
	cout << "No. of elements smaller than 11: " << A.order_of_key(11) << endl; // 4
	cout << "No. of elements smaller than 1: " << A.order_of_key(1) << endl; // 0
	cout << endl;

	// lower bound -> Lower Bound of X = first element >= X in the set
	cout << "Lower Bound of 6: " << *A.lower_bound(6) << endl;
	cout << "Lower Bound of 2: " << *A.lower_bound(2) << endl;
	cout << endl;

	// Upper bound -> Upper Bound of X = first element > X in the set
	cout << "Upper Bound of 6: " << *A.upper_bound(6) << endl;
	cout << "Upper Bound of 1: " << *A.upper_bound(1) << endl;
	cout << endl;

	// // Remove elements - 2nd query
	A.erase(1);
	A.erase(11); // element that is not present is not affected
	cout << "After deletion, A contains : " << endl;
	cout << "A = ";
	for (auto i : A)
		cout << i << " ";
	cout << endl;

    
}