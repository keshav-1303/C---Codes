#include <iostream>
using namespace std;
// keep takin ginput from user and print their sum...

int main(){
    
    int sum=0,value=0;
    while(cin >> value){
        sum += value;
    }
    cout << "Sum is : " << sum << endl;
    return 0;
}