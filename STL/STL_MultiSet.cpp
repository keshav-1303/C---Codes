#include <iostream>
#include <iterator>
#include <set>
using namespace std;
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 

int main()
{
	// empty multiset container
	multiset<int, greater<int> > gquiz1;

	// inserting elements in random order
	gquiz1.insert(40);
	gquiz1.insert(30);
	gquiz1.insert(60);
	gquiz1.insert(20);
	gquiz1.insert(50);

	// 50 will be added again to the multiset unlike set
	gquiz1.insert(50);
	gquiz1.insert(10);

	// printing multiset gquiz1
	print(gquiz1);

	// assigning the elements from gquiz1 to gquiz2
	multiset<int> gquiz2(gquiz1.begin(), gquiz1.end());

	// print all elements of the multiset gquiz2
	cout << "\nThe multiset gquiz2 \n"
			"after assign from gquiz1 is : \n";
	for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << endl;

	// remove all elements up to element
	// with value 30 in gquiz2
	cout << "\ngquiz2 after removal \n"
			"of elements less than 30 : \n";
	gquiz2.erase(gquiz2.begin(), gquiz2.find(30));
	for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
		cout << *itr << " ";
	}

	// remove all elements with value 50 in gquiz2
	int num;
	num = gquiz2.erase(50);
	cout << "\ngquiz2.erase(50) : \n";
	cout << num << " removed \n";
	for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
		cout << *itr << " ";
	}

	cout << endl;

	// lower bound and upper bound for multiset gquiz1
	cout << "\ngquiz1.lower_bound(40) : \n"
		<< *gquiz1.lower_bound(40) << endl;
	cout << "gquiz1.upper_bound(40) : \n"
		<< *gquiz1.upper_bound(40) << endl;

	// lower bound and upper bound for multiset gquiz2
	cout << "gquiz2.lower_bound(40) : \n"
		<< *gquiz2.lower_bound(40) << endl;
	cout << "gquiz2.upper_bound(40) : \n"
		<< *gquiz2.upper_bound(40) << endl;

	multiset<int> a;
	a.insert(10);
	a.insert(10);
	a.insert(10);

	// it will give output 3
	cout << a.count(10) << endl;

	// removing single instance from multiset

	// it will remove only one value of
	// 10 from multiset
	a.erase(a.find(10));

	// it will give output 2
	cout << a.count(10) << endl;

	// removing all instance of element from multiset
	// it will remove all instance of value 10
	a.erase(10);

	// it will give output 0 because all
	// instance of value is removed from
	// multiset
	cout << a.count(10) << endl;

	return 0;
}
