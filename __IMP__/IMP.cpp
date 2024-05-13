#include <bits/stdc++.h>
using namespace std;
#define int long long int

// GCD & LCM -----------------------------------------------
int gcd(int a, int b) { 
    return((b == 0) ? a : gcd(b, a % b)); 
}

int lcm(int a, int b) {  
    return (b / gcd(a, b)) * a; 
}

// Power ---------------------------------------------------
int power(int a, int b, int mod) {
    int res = 1; 
    while (b > 0) {
        if (b & 1)   res = (res * a) % mod; 
        a = (a * a) % mod; 
        b = b >> 1;
    } 
    return res;
}

int power(int a, int b) {
    int res = 1; 
    while (b > 0) {
        if (b & 1)   res = (res * a); 
        a = (a * a); 
        b = b >> 1;
    } 
    return res;
}

// Factorial table -----------------------------------------

vector<int> factorial = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000};

// ---------------------------------------------------------

// checking prime or not?-----------------------------------
bool isprime(int n){
    for(int i=2 ; i<=sqrt(n) ; i++){
        if(n % i == 0){
            return 0;
        }
    }
    return (n == 1) ? 0 : 1;
}
//----------------------------------------------------------

// getting vector of primes from 1 to n --------------------
vector<int> getPrimes(int n){     // int n = 1e6;

    vector<int> arr(n, 1);
    vector<int> ans;
    ans.push_back(2);

    for(int i=2; i<=n; i++){     // Sieve of Eratosthenes
        if(arr[i] == 1){
            for(int j=i*i; j<=n; j+=i)    arr[j] = 0;
        }
    }

    for(int i=3; i<=n; i+=2){
        if(arr[i] == 1)    ans.push_back(i);
    }
    return ans;
}
//-----------------------------------------------------------

// Binary Search----------------------------------------------
int BinarySearch(vector<int> &arr, int n, int key){

    int start = 0, end = n-1;
    int mid = start + (end-start)/2;
    int ans = -1;

    while(start <= end){
        if (arr[mid] == key)    ans = mid + 1;
        if (arr[mid] > key)    end = mid - 1;
        else    start = mid + 1;
        mid = start + (end-start)/2;
    }
    return ans;
}
//-----------------------------------------------------------

// Calculating nCr-------------------------------------------

int nCr(int n, int r){

    if (r > n) {
        return 0;
    }

    int ans = 1;
    r = (r > n-r) ? n-r : r;    // because nCn-r == nCr
    int j = 1;

    for( ; j<=r ; j++, n--){

        if(n % j == 0){
            ans *= n / j;
        }
        else if(ans % j == 0){
            ans = ans / j*n;
        }
        else{
            ans = (ans * n) / j;
        }
    }
    return ans;
}
//------------------------------------------------------------

//Number of distinct elements in vector-----------------------

int distinct(vector<int> v){
    sort(v.begin(), v.end());
    int count = 0;
    for(int i=0 ; i<v.size() ; i++){
        while(v[i] == v[i+1] && i < v.size()-1)    i++;
        count++;
    }
    return count;
}
//------------------------------------------------------------

//Max freq of element in vector-------------------------------

int maxfreq(vector<int> v){

    sort_(v);
    int maxfreq = 0;

    for(int i=0 ; i<v.size() ; i++){
        int freq = 1;

        while(i+1 < v.size() && v[i] == v[i+1]){
            i++;
            freq++;
        }
        maxfreq = max(maxfreq, freq);
    }
    return maxfreq;
}
//------------------------------------------------------------

//Prime Factorisation-----------------------------------------

// for calculating prime factors and how many times each factor occurs for a vector -->
    // this can be done by 1st calc product of vector but integer overflow occurs
    // this uses sieve and time complexity is sqrt(n)
    // eg - 3 3 3 5 5 5 7 7 7
    // ans = 3:3, 5:3, 7:3

map<int, int> prime_factorisation(vector<int> &v){

    map<int, int> m;

    for(auto &x : v){
        int prod = x;

        for(int i=2 ; i*i <= prod ; i++){
            int count = 0;
            while(prod % i == 0){
                prod /= i;
                count++;
            }
            if(count > 0)    m[i] += count;
        }
        if(prod > 1)     m[prod]++;
    }

    return m;
}

//-----------------------------------------------------------

//Removing Duplicate elements -------------------------------

    sort(v.begin(), v.end());   // would not work in unsorted array

    vector<int>::iterator ip = std::unique(v.begin(), v.end());
    v.resize(std::distance(v.begin(), ip));
    n = v.size();

//-----------------------------------------------------------

//Remove common elements from both arrays -------------------

    unordered_set<int> common;
    set_intersection(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), inserter(common, common.begin()));
    arr1.erase(remove_if(arr1.begin(), arr1.end(), [&](int n) { return common.count(n); }), arr1.end());
    arr2.erase(remove_if(arr2.begin(), arr2.end(), [&](int n) { return common.count(n); }), arr2.end());
    
    p = arr1.size();
    q = arr2.size();

//Store Prime Factorisation----------------------------------

void primeFactors(int n, map<int, int> &ans) { 
    // map<int, int> stores ans as <factor, power of factor>
     
    while (n % 2 == 0) { 
        ans[2]++; 
        n = n/2; 
    } 
 
    for (int i = 3; i <= sqrt(n); i = i + 2) { 
        while (n % i == 0) { 
            ans[i]++; 
            n = n/i; 
        } 
    } 
 
    if (n > 2)    ans[n]++;     // for prime numbers
} 
//-----------------------------------------------------------

//Check is A(string) is a subsequence of B(string) ----------

bool checkSubsequence(string A, string B){

    // here, B is the greater guy.

    int i = 0, j = 0;
        
    while(i < A.size()){
        if(A[i] == B[j]){
            i++;
            j++;
        }
        else{
            j++;
        }
        
        if(j > B.size()){
            return false;
        }
    }
    return true;
}