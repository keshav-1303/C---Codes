#include <bits/stdc++.h>
using namespace std;

// SYNTAX ---------------------------------------
// [ capture clause ] (parameters) -> return-type  
// {   
//    definition of method   
// } 
// ----------------------------------------------

int main(){

    vector<int> v = {1, 2, 3, 4, 5};

    // Sum of vector-----------------------------

    auto sum = [](vector<int> &v) -> int {
        int sum{};
        for(auto i : v){
            sum += i;
        }
        return sum;
    };

    cout << sum(v) << endl;

    //-------------------------------------------

    bool is = all_of(v.begin(), v.end(), [](int x){
        if(x > 0)   return 1;
        else    return 0;
    });

    cout << (is ? "all > 0" : "not all > 0") << endl;
    
    //--------------------------------------------

}