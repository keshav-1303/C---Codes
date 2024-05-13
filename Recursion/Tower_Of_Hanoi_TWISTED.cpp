/* 

It is a twisted Tower of Hanoi problem. In which, all rules are the same with an addition of a rule:

You can not move any disk directly from the first rod to last rod i.e., If you want to move a disk from the first rod to the last rod then you have to move the first rod to the middle rod first and then to the last one.    

*/

#include <bits/stdc++.h>
using namespace std;
  
void solve(int n, char src_rod, char aux_rod, char dest_rod){

    if(n == 1){

        cout << "Move disk " << n << " from rod " << src_rod << " to " << aux_rod << endl;

        cout << "Move disk " << n << " from rod " << aux_rod << " to " << dest_rod << endl;

        return ;
    }

    solve(n - 1, src_rod , aux_rod , dest_rod);
    cout << "Move disk " << n << " from rod " << src_rod << " to " << aux_rod << endl;

    solve(n - 1, dest_rod, aux_rod, src_rod);
    cout << "Move disk " << n << " from rod " << aux_rod << " to " << dest_rod << endl;

    solve(n - 1, src_rod, aux_rod, dest_rod);
}
  
int main(){ 

    int n = 2;
  
    solve( n, 'A', 'B', 'C');

    // cout << "Number of MOVES are : " << pow(2, n) - 1 << endl;

    return 0;
}