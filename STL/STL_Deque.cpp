#include <bits/stdc++.h>
#include <deque>
using namespace std;

print(deque<int> &v){
    for(int i=0; i<v.size(); i++)    cout << v[i] << " ";
    cout << endl;
}

int main(){    // Insertion / Deletion from both ends

    cout << "\nDeclaration............................................................................\n";
    cout << endl;
	
	deque <int> b ;
    cout << "deque b is : ";    print(b);

	deque <int> mark {56, 34, 23, 12, 89};
    cout << "deque mark is : ";    print(mark);

	deque <int> marks = {56, 34, 23, 12, 89};
    cout << "deque marks is : ";    print(marks);

    int arr[3] = {10, 20, 30};
    deque<int> v_(arr, arr + 3);
    cout << "deque v is : ";    print(v_);

    deque<int> v = {1, 2, 3};
    deque<int> vect(v.begin(), v.end());
    cout << "deque vect is : ";    print(vect);

    deque<int> v1(10, 5);
    cout << "deque v1 is : ";    print(v1);

    deque<int> v2(10);
    fill(v2.begin(), v2.end()-2, 5);
    cout << "deque v2 is : ";    print(v2);

    cout << endl;



    cout << "\nOperations............................................................................\n";
    cout << endl;
	
    deque<int> a;

	a.push_back(1);		//push_front() is not available in deque, it is in deque

    a.push_front(2);
	cout << "size : " << a.size() << endl;

    a.push_front(2);
	cout << "size : " << a.size() << endl;

	a.push_back(2);
	cout << "size : " << a.size() << endl;

	a.push_back(3);
	cout << "size : " << a.size() << endl;

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
rbegin() – Returns a reverse iterator pointing to the last element in the deque (reverse beginning). It moves from last to first element

rend() – Returns a reverse iterator pointing to the theoretical element preceding the first element in the deque (considered as reverse end)

cbegin() – Returns a constant iterator pointing to the first element in the deque.

cend() – Returns a constant iterator pointing to the theoretical element that follows the last element in the deque.

crbegin() – Returns a constant reverse iterator pointing to the last element in the deque (reverse beginning). It moves from last to first element

crend() – Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the deque (considered as reverse end)                                                              */

    deque<int> sample;
  
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