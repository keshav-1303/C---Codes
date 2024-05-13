#include <forward_list>
#include <iostream>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
using namespace std;
#define inputArr(arr, n)   for( auto i = 0 ; i < n ;  i++ )     cin >> arr[i]; 
#define inputVector(v, n)  for(auto i=0; i<n; i++) {int temp;    cin >> temp;    v.pb(temp);} 
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 

int main(){
	
	forward_list<int> flist1;
	forward_list<int> flist2;
	forward_list<int> flist3;

	flist1.assign({ 1, 2, 3 });   // Assigning values using assign()

	flist2.assign(5, 10);   // Assigning repeating values using assign(), 5 elements with value 10

	flist3.assign(flist1.begin(), flist1.end());    //Assigning values of list 1 to list 3

	cout << "The elements of first forward list are : ";
	print(flist1);

	cout << "The elements of second forward list are : ";
	print(flist2);

	cout << "The elements of third forward list are : ";
	print(flist3);

 
    // push_front(), emplace_front() and pop_front()

	forward_list<int> flist = { 10, 20, 30, 40, 50 };

	flist.push_front(60);

	cout << "The forward list after push_front operation : ";
	print(flist);

	// Inserting value using emplace_front()
	flist.emplace_front(70);

	cout << "The forward list after emplace_front operation : ";
	print(flist);

	// Deleting first value using pop_front()
	// Pops 70
	flist.pop_front();

	cout << "The forward list after pop_front operation : ";
	print(flist);

	forward_list<int> filist = { 10, 20, 30, 25, 40, 40 };

	filist.remove(40);    // Removes all occurrences of 40

	cout << "The forward list after remove operation : ";
	print(filist);

	// Removing according to condition. Removes
	// elements greater than 20. Removes 25 and 30
	filist.remove_if([](int x) { return x > 20; });

	// Displaying the forward list
	cout << "The forward list after remove_if operation : ";
	print(filist);

	flist.clear();    // Forward List becomes empty

	cout<<"Forward list after using clear function: ";
	for (auto it = flist.begin(); it != flist.end(); ++it)
		cout << ' ' << *it;
	cout<<endl;

	forward_list<int> list1 = { 10, 20, 30 };

	forward_list<int> list2 = { 40, 50, 60 };

	// forward list after 1st position
	list2.splice_after(list2.begin(), list1);

	cout << "The forward list after splice_after operation : ";
	print(list2);

	return 0;
}



