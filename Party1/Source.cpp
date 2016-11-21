#include <iostream>
#include <algorithm>
using namespace std;
int fee[101];			//array of the fee for party[i]
int fun[101];			//array of the fun for party[i]

void maxFun(int budget, int n) {
	int w, k, total = 0;
	int B[502];

	for (w = 0; w < budget; w++)
		B[w] = 0;

	for (k = 0; k < n; k++) {
		for (w = budget; w >= fee[k]; w--) {
			if (B[w - fee[k]] + fun[k] > B[w])
				B[w] = B[w - fee[k]] + fun[k];
		}
	}

	int b = budget; 
	while (B[b] == B[budget])
		b--;
	cout << b + 1 <<" " << B[b + 1] << endl;
}

int main() {
	int budget = -1;
	int n = -1;			//budget, n (the number of parties)
	
	do {
		//first line to read in budget and n
		cin >> budget;		//party budget (0-500)
		cin >> n;			//number n of parties (0-100)

		if (budget == 0 && n == 0)
			return 0;
	
		if (budget == 0 || n == 0)
			cout << "0 0" << endl;
		else {
			for (int i = 0; i < n; i++) {
				cin >> fee[i];		//entrance fee of each party (5-25 francs)
				cin >> fun[i];		//amount of fun per party (0- 10)
			}
			maxFun(budget, n);		//determine the max fun without going over budget
		}
	} while (budget != 0 && n != 0);

	return 0;
}