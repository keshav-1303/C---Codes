/* The bitwise OR of two numbers is just the sum of those two numbers if 
there is no carry involved, otherwise you just add their bitwise AND. 
Let’s say, we have a=5(101) and b=2(010), since there is no carry involved
in binary addition, their sum is just a|b. Now, 
if we change ‘a’ to 6 which is 110 in binary, their sum would change to a|b +
a&b since there is a carry involved. */

#include <bits/stdc++.h>
using namespace std;

int SUM(int n1, int n2){
    return n1|n2 + n1&n2;
}

void binary(int n){
	if(n == 0)	 return ;
	binary(n/2);
	cout << n % 2;
}
  
int main(){

    int num1, num2;

    cout << "Enter 1st number : ";    cin >> num1;
    cout << "Enter 2nd number : ";    cin >> num2;

    cout << SUM(num1, num2);
    
    return 0;
}