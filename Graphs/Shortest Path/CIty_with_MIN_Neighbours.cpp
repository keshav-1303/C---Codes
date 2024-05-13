#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=city-with-the-smallest-number-of-neighbors-at-a-threshold-distance
// Using FLOYD WARSHALL ALGORITHM-->

int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
                 
    vector<vector<int>> dist (n, vector<int> (n, 1e9));
    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int weight = it[2];
        
        dist[u][v] = weight;
        dist[v][u] = weight;
    }
    
    for(int i=0 ; i<n ; i++)    dist[i][i] = 0;
    
    for(int k=0 ; k<n ; k++){
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                
                if(dist[i][k] == 1e9 || dist[k][j] == 1e9)
                    continue;
                    
                else
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    int cntCity = n;
	int cityNo = -1;
	
	for (int city = 0; city < n; city++) {
		int cnt = 0;
		for (int adjCity = 0; adjCity < n; adjCity++) {
			if (dist[city][adjCity] <= distanceThreshold)
				cnt++;
		}

		if (cnt <= cntCity) {
			cntCity = cnt;
			cityNo = city;
		}
	}
	return cityNo;
                 
}