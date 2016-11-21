#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void maxFun(int budget, int n, vector<int> &sumFun, vector<int> &sumFee, int *fun, int *fee) {
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
	sumFun.push_back(B[b + 1]);
	sumFee.push_back(b + 1);
}

int getFirstLine(int &budget, int &n, vector<int> &sumFun, vector<int> &sumFee) {
	//first line to read in budget and n
	cin >> budget;		//party budget (0-500)
	cin >> n;			//number n of parties (0-100)

	if (budget == 0 && n == 0)
		return 3;
	else if (budget == 0 || n == 0) {
		sumFun.push_back(0);
		sumFee.push_back(0);
		return -1;
	}
	else {
		return 1;
	}
		
}

int main() {
	int fee[101];			//array of the fee for party[i]
	int fun[101];			//array of the fun for party[i]

	vector<int> sumFun;
	vector<int> sumFee;

	int budget = -1;
	int n = -1;			//budget, n (the number of parties)
	int value;

	do {
		value = getFirstLine(budget, n, sumFun, sumFee);
		if (value < 2) {
			for (int i = 0; i < n; i++) {
				cin >> fee[i];		//entrance fee of each party (5-25 francs)
				cin >> fun[i];		//amount of fun per party (0- 10)
			}
			if (value == 1) {
				maxFun(budget, n, sumFun, sumFee, fun, fee);		//determine the max fun without going over budget
			}
		}
	} while (budget != 0 && n != 0);

	for (unsigned int i = 0; i < sumFee.size(); i++)
		cout << sumFee[i] << " " << sumFun[i] << endl;

	sumFee.clear();
	sumFun.clear();

	return 0;
}