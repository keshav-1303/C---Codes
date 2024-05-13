#include <bits/stdc++.h>
#include <vector>
using namespace std;

print(vector<int> &v){
    for(int i=0; i<v.size(); i++)    cout << v[i] << " ";
    cout << endl;
}

// follows LIFO

int main(){

    cout << "\nDeclaration............................................................................\n";
    cout << endl;
	
	vector <int> b ;
    cout << "Vector b is : ";    print(b);

	vector <int> mark {56, 34, 23, 12, 89};
    cout << "Vector mark is : ";    print(mark);

	vector <int> marks = {56, 34, 23, 12, 89};
    cout << "Vector marks is : ";    print(marks);

    int arr[3] = {10, 20, 30};
    vector<int> v_(arr, arr + 3);
    cout << "Vector v is : ";    print(v_);

    vector<int> v = {1, 2, 3};
    vector<int> vect(v.begin(), v.end());
    cout << "Vector vect is : ";    print(vect);

    vector<int> v1(10, 5);
    cout << "Vector v1 is : ";    print(v1);

    vector<int> v2(10);
    fill(v2.begin(), v2.end()-2, 5);
    cout << "Vector v2 is : ";    print(v2);

    cout << endl;



    cout << "\nOperations............................................................................\n";
    cout << endl;
	
    vector<int> a;

	a.push_back(1);		//push_front() is not available in vector, it is in deque
	cout << "Capacity : " << a.capacity() << "  &  size : " << a.size() << endl;	
    //.capacity() is exclusive for vectors

	a.push_back(2);
	cout << "Capacity : " << a.capacity() << "  &  size : " << a.size() << endl;

	a.push_back(3);
	cout << "Capacity : " << a.capacity() << "  &  size : " << a.size() << endl;

	cout << "Front : " << a.front() << endl;
	cout << "Back : " << a.back() << endl;

	cout << "Before pop..." << endl;

	for(int i=0; i<a.size(); i++)	   cout << a[i] << " ";
	cout << endl;

	cout << "After pop..." << endl;

	a.pop_back();

	for(int i:a)	   cout << i << " ";
	cout << endl;
	
	cout << "Before clear SIZE is " << a.size() << endl; 
	a.clear();
	cout << "After clear SIZE is " << a.size() << endl;


    cout << endl;
    cout << "\nIterators............................................................................\n";
	cout << endl;

/*
rbegin() – Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element

rend() – Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)

cbegin() – Returns a constant iterator pointing to the first element in the vector.

cend() – Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.

crbegin() – Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element

crend() – Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)                                                              */

    vector<int> sample;
  
    for (int i = 1; i <= 5; i++)    sample.push_back(i);
  
    cout << "Output of begin and end: ";
    for (auto i = sample.begin(); i != sample.end(); i++)    cout << *i << " ";
  
    cout << "\nOutput of cbegin and cend: ";
    for (auto i = sample.cbegin(); i != sample.cend(); ++i)    cout << *i << " ";
  
    cout << "\nOutput of rbegin and rend: ";
    for (auto i = sample.rbegin(); i != sample.rend(); ++i)    cout << *i << " ";
  
    cout << "\nOutput of crbegin and crend : ";
    for (auto i = sample.crbegin(); i != sample.crend(); ++i)    cout << *i << " ";
    
    cout << endl;
    cout << endl;
    return 0;
}