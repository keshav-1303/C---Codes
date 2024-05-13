#include <iostream>
#include <vector>
#include <numeric> // for iota
using namespace std;

int main(){

	vector<int> numbers (11);
	// Initialising starting value as 10
	int start = 10;

	iota(numbers.begin(), numbers.end(), start);
	// Fills indices with start, start+1, start+2 ... and so on.

	cout << "Elements are :";
	for (auto i : numbers)
		cout << ' ' << i;
	cout << endl;

	return 0;
}
