#include <iostream>
#include <map>
using namespace std;

int main(){

    map<string, int> m;

    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;

    map<string, int>::iterator it = m.begin();

    while (it != m.end()){
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
        ++it;
    }

    cout << "Size of map: " << m.size() << endl;

    map<int, int> m1;
 
    // insert elements in random order
    // it stores in ascending order.
    // all keys are unique.
    // Time ccomplexity of insertion ans deletion is O(log N).

    m1.insert(pair<int, int>(1, 40));
    m1.insert(pair<int, int>(2, 30));
    m1.insert(pair<int, int>(3, 60));
    m1.insert(pair<int, int>(4, 20));
    m1.insert(pair<int, int>(6, 50));
    m1.insert(pair<int, int>(5, 50));
     
    m1[7] = 10;     // another way of inserting a value in a map
 
    map<int, int>::iterator itr;
    cout << "\nThe map m1 is : \n";
    for (itr = m1.begin(); itr != m1.end(); ++itr) {
        cout << "  " << itr->first << "  :  " << itr->second << endl;
    }
    cout << endl;
 
    // assigning the elements from m1 to m2
    map<int, int> m2 (m1.begin(), m1.end());
 
    // print all elements of the map m2
    cout << "\nThe map m2 after assign from m1 is : \n";
    for (itr = m2.begin(); itr != m2.end(); ++itr) {
        cout << "  " << itr->first << "  :  " << itr->second
             << '\n';
    }
    cout << endl;
 
    // remove all elements up to element with key=3 in m2
    cout << "\nm2 after removal of" << " elements less than key=3 : \n";
    m2.erase(m2.begin(), m2.find(3));
    for (itr = m2.begin(); itr != m2.end(); ++itr) {
        cout << "  " << itr->first << "  :  " << itr->second << endl;
    }
 
    // remove all elements with key = 4
    int num;
    num = m2.erase(4);
    cout << "\nm2.erase(4) : ";
    cout << num << " removed \n";
    for (itr = m2.begin(); itr != m2.end(); ++itr) {
        cout << "  " << itr->first << "  :  " << itr->second
             << '\n';
    }
 
    cout << endl;
 
    // lower bound and upper bound for map m1 key = 5
    cout << "m1.lower_bound(5) : " << "\tKEY = ";
    cout << m1.lower_bound(5)->first << "  ";
    cout << "\tELEMENT = " << m1.lower_bound(5)->second << endl;
    cout << "m1.upper_bound(5) : " << "\tKEY = ";
    cout << m1.upper_bound(5)->first << "  ";
    cout << "\tELEMENT = " << m1.upper_bound(5)->second << endl;

    return 0;
}
