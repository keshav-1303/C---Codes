#include <bits/stdc++.h>
using namespace std;
#define d 256

void search(string pat, string txt, int q){

	int m = pat.size();
	int n = txt.size();
	int i, j;
	int p = 0; // hash value for pattern
	int t = 0; // hash value for txt
	int h = 1;

	// The value of h would be "pow(d, m-1)%q"
	for (i = 0; i < m - 1; i++)
		h = (h * d) % q;

	for (i = 0; i < m; i++) {
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
	}

	for (i = 0; i <= n - m; i++){
		if (p == t) {
			/* Check for characters one by one */
			for (j = 0; j < m; j++) {
				if (txt[i + j] != pat[j]) {
					break;
				}
			}
			if(j == m){
				cout << "Pattern found at index " << i << endl;
            }
		}

		if(i < n-m) {
			t = (d * (t - txt[i] * h) + txt[i + m]) % q;
			if (t < 0)
				t = (t + q);
		}
	}
}

int main(){
	string txt = "GEEKS FOR GEEKS";
	string pat = "GEEK";

	int q = INT_MAX;

	search(pat, txt, q);
	return 0;
}