#include <bits/stdc++.h> 

void solve(string str, string output, int index, vector<string> &ans){

	// Base case
	if(index >= str.size()){
		if(!output.empty())		ans.push_back(output);
		return ;
	}

	// Exclude
	solve(str, output, index+1, ans);

	// Include
	char element = str[index];
	output.push_back(element);
	solve(str, output, index+1, ans);
}

vector<string> subsequences(string str){
	
	vector<string> ans;
	string output = "";
	int index = 0;

	solve(str, output, index, ans);
	return ans;
	
}
