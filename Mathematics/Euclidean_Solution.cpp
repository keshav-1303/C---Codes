#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
using namespace std;
#define inputArr(arr, n)   for( auto i = 0 ; i < n ;  i++ )     cin >> arr[i]; 
#define inputVector(v, n)  for(auto i=0; i<n; i++) {int temp;    cin >> temp;    v.pb(temp);} 
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 
#define printmap(m)    for(auto i : m){ cout << i.first << " : " << i.second << endl; }

// solution for ax + by = n-------------------------------------------------------------------------
int gcd_solution(int a, int b, int &x, int &y){	 
    // using gcd(a, b) = gcd(b, a % b);  and if any of a becomes zero return other.

	if(b == 0){
        x = 1;   // because ax + by = gcd(a, b)  and b is 0 here
        y = 0;   // therefore gcd will return a , ans equation becomes ax + 0 = a.
        return a;
    }

    int x1, y1;
    int g =  gcd_solution(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a/b)*y1;

    return g;
}

void solution(int a, int b, int n, int &x0, int &y0){

    int g = gcd_solution(a, b, x0, y0);
    if(n % g != 0){
        x0 = 0, y0 = 0;
        cout << "No Solution Exists" << endl;
        return;
    }

    // single valid answer
    x0 = x0 * n/g;
    y0 = y0 * n/g;

    if(x0 >= 0 && y0 >= 0){
        return ;
    }
 
    // other valid answers can be obtained through...
    // x = x0 + k*(b/g)
    // y = y0 - k*(a/g)
    for(int k = -3; k <= 3; k++){
        int x = x0 + k*(b/g);
        int y = y0 - k*(a/g);
        if(x >= 0 && y >= 0){
            x0 = x;    y0 = y;
            return ;
        }
    }
}
//----------------------------------------------------------------------------------------------

int main(){

    // ax + by = c;

    int a = 2, b = 4, c = 5;

    int x, y;

    solution(a, b, c, x, y);

    cout << "x = " << x << " and y = " << y << endl;
    
    return 0;
}

