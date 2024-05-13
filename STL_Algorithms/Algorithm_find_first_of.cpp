#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){

    vector<int>v = {1, 3, 3, 3, 10, 1, 3, 3, 7, 7, 8};
  
    vector<int>v1 = {123};
  
    vector<int>::iterator i;
      
    // Using std::find_first_of
    i = find_first_of(v.begin(), v.end(), v1.begin(), v1.end());
  
    // Displaying the first common element found
    cout << "First common element is : " << *i << endl;
  
    // Finding the second common element
    i = find_first_of(i + 1, v.end(), v1.begin(), v1.end());
  
    // Displaying the second common element found
    cout << "Second common element is : " << *i << endl;
      
    return 0;
}