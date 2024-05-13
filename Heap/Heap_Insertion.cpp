#include <bits/stdc++.h>
using namespace std;
#define maxsize 100

class heap{     // MAXHEAP

    public : 

    int arr[maxsize];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){

        size++;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }

            else{
                return ;
            }
        }
    }

    void print(){
        for(int i=1 ; i<=size ; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteMax(){

        if(size == 0){
            cout << "Nothing to Delete!!!" << endl;
            return ;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while(i < size){
            int leftindex = 2*i;    // left child's index
            int rightindex = 2*i + 1;   // right child's index

            if(arr[leftindex] > arr[i] && leftindex < size){
                swap(arr[i], arr[leftindex]);
                i = leftindex;
            }

            if(arr[rightindex] > arr[i] && rightindex < size){
                swap(arr[i], arr[rightindex]);
                i = rightindex;
            }

            else{
                return ;
            }
        }
    }
};

int main(){

    heap h;

    h.insert(30);
    h.insert(20);
    h.insert(50);
    h.insert(60);
    h.insert(40);

    h.print();

    h.deleteMax();
    h.print();
    
    return 0;
}

