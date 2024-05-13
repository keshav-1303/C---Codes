#include <bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k);

int main() {
    
        int n, k;
        cout << "Enter n : ";    cin >> n;
        cout << "Enter k : ";    cin >> k;
        
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    
}

void rev(queue<int> &q, int k){
    
    if(k == 0)    return ;
    
    if(q.empty())    return ;
    
    int num = q.front();
    q.pop();
    
    rev(q, k - 1);
    
    q.push(num);
}

queue<int> modifyQueue(queue<int> q, int k) {
    
    rev(q, k);
    
    int rem = q.size() - k;
    
    while(rem--){
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}