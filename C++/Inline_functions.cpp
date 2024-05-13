#include <bits/stdc++.h>
using namespace std;

// No extra MEMORY USAGE
// No EXTRA FUNCTION CALLED
// Can be used when function body is of ONE / TWO LINES ONLY

inline int getMax(int a, int b){
    return (a > b) ? a : b;
}

int main(){
    
    int a = 4 , b = 10;

    int ans = getMax(a, b);
    cout << ans << endl;

    a++;
    b--;

    ans = getMax(a,b);
    cout << ans << endl;

    return 0;
}