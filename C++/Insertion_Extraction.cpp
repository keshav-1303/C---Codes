#include<iostream>
//"<<" is called insertion operator.It is used with cout.
//">>" is called extraction operator.It is used with cin.

int main(){
    int a,b;
    std::cout<<"Enter first number:";
    std::cin>>a;
    std::cout<<"Enter second number:";
    std::cin>>b;
    std::cout<<"Sum of "<<a<<" and "<<b<<" is "<<a+b;
    return 0;
}