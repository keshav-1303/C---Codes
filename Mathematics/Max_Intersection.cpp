#include <bits/stdc++.h>
#define int long long int
using namespace std;

bool open_interval(pair<int, char> a, pair<int, char> b){
    if(a.first == b.first){
        return a.second > b.second;
    }
    return a.first < b.first;
}

bool closed_interval(pair<int, char> a, pair<int, char> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

signed main{

    // 3
    // 1 5
    // 2 4
    // 5 6        Ans = 2 2

    // 4
    // 3 4
    // 4 5
    // 4 6
    // 8 10       Ans = 4 2

    int n;    scanf("%lld", &n);
    
    vector<pair<int, char>> v;

    for(int i=0 ; i<n ; i++){
        int temp1, temp2;   scanf("%lld %lld", &temp1, &temp2);
        v.push_back({temp1, 'B'});
        v.push_back({temp2, 'E'});
    }

    sort(v.begin(), v.end(), open_interval);

    int count = 0, ans = 0, maxcount = 0;

    for(int i=0 ; i<v.size() ; i++){

        if(v[i].second == 'B')    count++;
        else    count--;

        if(count > maxcount){
            maxcount = count;
            ans = v[i].first;
        }
    }

    printf("%lld %lld\n", ans, maxcount);
    return ;

}
