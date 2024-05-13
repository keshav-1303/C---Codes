/* Tower of Hanoi is a mathematical puzzle where we have three rods (A, B, and C) and N disks. Initially, all the disks are stacked in decreasing value of diameter i.e., the smallest disk is placed on the top and they are on rod A. The objective of the puzzle is to move the entire stack to another rod (here considered C), obeying the following simple rules: 

    1. Only one disk can be moved at a time.
    2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another  stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
    3. No disk may be placed on top of a smaller disk             */

#include <bits/stdc++.h>
using namespace std;
  
void towerOfHanoi(int n, char source_rod, char aux_rod, char destination_rod){

    if(n == 1){    //base case i.e moving last disk from "source" to "destination"
        cout << "Move disk " << n << " from " << source_rod << " to " << destination_rod << endl;
        return ;
    }

    towerOfHanoi(n-1, source_rod, destination_rod, aux_rod);    //move n-1 disks from "source" to "aux"

    cout << "Move disk " << n << " from " << source_rod << " to " << destination_rod << endl;

    towerOfHanoi(n-1, aux_rod, source_rod, destination_rod);    //move n-1 disks from "aux" to "destination"
}
  
int main(){ 

    int n = 4;
  
    towerOfHanoi( n, 'A', 'B', 'C');

    // cout << "Number of MOVES are : " << pow(2, n) - 1 << endl;

    return 0;
}