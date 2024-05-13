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

struct stud{
    int roll;
    char name[30];
    int marks;
    struct stud *next;
};

int main(){

    struct stud s1, s2, s3;

    cout << "Enter details of student 1... ( Roll , Name , Marks )\n";
    cin >> s1.roll >> s1.name >> s1.marks ;

    cout << "Enter details of student 2... ( Roll , Name , Marks )\n";
    cin >> s2.roll >> s2.name >> s2.marks ;

    cout << "Enter details of student 3... ( Roll , Name , Marks )\n";
    cin >> s3.roll >> s3.name >> s3.marks ;

    s1.next = &s2;
    s2.next = &s3;
    s3.next = NULL;

    struct stud *p = &s1;

    cout << endl;

    while(p != NULL){
        cout << "Roll : " << p -> roll;
        cout << "\tName : " << p -> name;
        cout << "\tMarks : " << p -> marks;
        cout << endl;
        p = p -> next;
    }

    // struct Node* head = NULL;
	// struct Node* second = NULL;
	// struct Node* third = NULL;

	// // allocate 3 nodes in the heap
	// head = (struct Node*)malloc(sizeof(struct Node));
	// second = (struct Node*)malloc(sizeof(struct Node));
	// third = (struct Node*)malloc(sizeof(struct Node));

	// head->data = 1; // assign data in first node
	// head->next = second; // Link first node with second

	// second->data = 2; // assign data to second node
	// second->next = third;

	// third->data = 3; // assign data to third node
	// third->next = NULL;
    
    return 0;
}

