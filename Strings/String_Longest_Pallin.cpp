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

string longestPalin (string s) {
        
    int maxlen = 0;

    deque<char> ans;
    
    for(int i=0 ; i<s.size() ; i++){

        deque<char> temp1;
        deque<char> temp2;
        
        int a1 = i-1 , a2 = i+1;
        int len = 1;
        temp1.pb(s[i]);
        while(s[a1] == s[a2]){
            temp1.pf(s[a1]);
            temp1.pb(s[a2]);
            len+=2;
            a1--;
            a2++;
        }
        
        a1 = i-1;
        a2 = i;
        int len2 = 0;
        while(s[a1] == s[a2]){
            temp2.pf(s[a1]);
            temp2.pb(s[a2]);
            len2+=2;
            a1--;
            a2++;
        }
        
        // maxlen = max(maxlen, max(len, len2));

        if(temp1.size() > maxlen){
            ans = temp1;
            maxlen = ans.size();
        }

        else if(temp2.size() > maxlen){
            ans = temp2;
            maxlen = ans.size();
        }

        // print(ans);
    }

    string ansString = "";

    for(int i=0 ; i<ans.size() ; i++){
        ansString += ans[i];
    }
    
    cout << "Maxlen = " << maxlen << endl;  
    return ansString;      
}

int main(){

    string s;
    cout << "Enter string : ";     cin >> s;

    cout << longestPalin(s) << endl;
}