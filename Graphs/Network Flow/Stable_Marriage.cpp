#include <bits/stdc++.h>
using namespace std;

// m1 -> curr marriage, m -> w likes more  
bool wPrefsM1OverM(vector<vector<int>> pref, int w, int m, int m1){
	int n = pref[0].size();
	for (int i=0 ; i<n ; i++){
		// if m1 comes before, priority[m1] > priority[m]
		if(pref[w][i] == m1)	return 1;
		if(pref[w][i] == m)		return 0;
	}
}

void stableMarriage(vector<vector<int>> pref){
	int n = pref[0].size();
	vector<int> wPartner(n, -1);	// -1 == woman[n+i] is free
	vector<bool> freeMen(n, 0);	   // freeMen[i] == 0 means i-th man is free
	int freeCnt = n;

	while(freeCnt > 0){
		int m = 0;	//Pick the first free man
		for( ; m<n ; m++){
			if(!freeMen[m])	  break;
		}
		// go to all women acc to prefence of m.
		for(int i=0 ; i<n && !freeMen[m] ; i++){
			int w = pref[m][i];
			if(wPartner[w-n] == -1){
				wPartner[w-n] = m;
				freeMen[m] = 1;
				freeCnt--;
			}
			else{
				int m1 = wPartner[w-n];
				if(!wPrefsM1OverM(pref, w, m, m1)){
					wPartner[w-n] = m;
					freeMen[m] = 1;
					freeMen[m1] = 0;
				}
			}
		}
	}
	cout << "Woman  Man" << endl;
	for (int i=0 ; i<n ; i++){
		cout << " " << i+n << "      " << wPartner[i] << endl;
	}
}

int main(){
	int n = 4;
	// First n of men, then n of women
	vector<vector<int>> pref = {
		{7, 5, 6, 4},
		{5, 4, 6, 7},
		{4, 5, 6, 7},
		{4, 5, 6, 7},
		{0, 1, 2, 3},
		{0, 1, 2, 3},
		{0, 1, 2, 3},
		{0, 1, 2, 3},
	};
	stableMarriage(pref);
}
