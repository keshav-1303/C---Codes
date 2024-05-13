#include <bits/stdc++.h>
using namespace std;

struct Job { 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

static bool cmp(Job &a, Job &b){
    return a.profit > b.profit;
}

// T.C = O(NlogN + max_id*N)
vector<int> JobScheduling(Job arr[], int n) { 
    sort(arr, arr+n, cmp);
    // Now sorted in dec order by profit
    vector<int> seq(n, -1);   // to store seq of jobs
    // do all jobs at the latest possible
    int sum = 0, cnt = 0;
    for(int i=0 ; i<n ; i++){
        int ind = arr[i].dead-1;
        for(int j=ind ; j>=0 ; j--){
            if(seq[j] == -1){   // free slot found
                seq[j] = arr[i].id, sum += arr[i].profit, cnt++;
                break;
            }
        }
    }
    vector<int> ans = {cnt, sum};
    return ans;
} 

// T.C = O(NlogN)