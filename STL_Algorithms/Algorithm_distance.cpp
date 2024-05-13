#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
int main(){

    vector<int> vect {5, 10, 15, 20, 1, 20, 23, 42, 45, 91, 23, 90};
 
    // Return distance of first to maximum element
    cout << "Distance between first to max element: ";
    cout << distance( vect.begin(), max_element(vect.begin(), vect.end()) ) << endl;

    // Return distance of minimum to maximum element
    cout << "Distance between min to max element: ";
    cout << distance( min_element(vect.begin(), vect.end()) , max_element(vect.begin(), vect.end()) ) << endl;

    // distance(first_iterator,desired_position) – It returns the distance of desired position from the first iterator.This function is very useful while finding the index. 

    return 0;
}