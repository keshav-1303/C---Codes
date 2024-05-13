#include<iostream>
using namespace std;

int c=45;

int main(){
    int a=34;
    int b=5;
    int c=a+b;
    cout<<"c = "<<a+b<<endl;
    cout<<"Global c is "<<::c;
    return 0;
}