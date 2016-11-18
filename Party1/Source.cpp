#include <iostream>
#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

//find the optimal set of parties that offer the most fun
//keep in mind that your budget need not necessarily be reached
//achieve the highest possible fun level and do not spend more money than absolutely necessary

/*OUTPUT:
	for each test case, output:
	1) the sum of the entrance fees and 
	2) the sum of all the fun values of an optimal solution separated by a single space
*/
void calculate(int budget, int n, int fun[101], int fee[101]);

int main() {
	int fee[101], fun[101];
	int budget, n, val;
	
	//first line
	cin >> budget;		//party budget (0 - 500)
	cin >> n;			//number n of parties (0 - 100)
	//cin.ignore();		//dump the newline character left by cin

	if (budget == 0 && n == 0) {
		return 0;
	}

	do {
		// the following n lines contain 2 numbers:
		for ( int i = 0; i < n; i++) {
			cin >> val;
			fee[i] = val;		//1)the entrance fee of each parties (5-25 francs)
			cin >> val;
			fun[i] = val;		// 2)the amount of fun of each party (0-10)
		}
		if (budget == 0 || n == 0)
			cout << "0 0" << endl;
		else
			calculate(budget, n, fun, fee);	//call function to detmine the 	

		cin >> budget;		//party budget (0 - 500)
		cin >> n;			//number n of parties (0 - 100)
		//cin.ignore();		//dump the newline character left by cin
	} while (budget != 0 && n != 0);
	
	return 0;
}

void calculate(int budget, int n, int fun[101], int fee[101]){
	int sumFee = 0;
	int uno[101][501] = { 0 }, dos[101][501] = { 0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < budget; j++) {
			if (i == 0 || j == 0) {
				uno[i][j] = 0;
				dos[i][j] = 0;
			}
			else if (fee[i - 1] <= j) {
				uno[i][j] = max(uno[i - 1][j], fun[i - 1] + uno[i - 1][j - fee[i - 1]]);
				if (fun[i - 1] + uno[i - 1][j - fee[i - 1]] > uno[i - 1][j])
					dos[i][j] = 1;
				else
					dos[i][j] = -1;
			}
			else {
					dos[i][j] = -1;
					uno[i][j] = uno[i - 1][j];
			}
		}
	}

	int items = n, bud = budget;
	while (items > 0) {
		if (dos[items][bud] == 1) {
			sumFee += fee[items - 1];
			--items;
			bud -= fee[items];
		}
		else
			--items;
	}

	cout << sumFee << " " << uno[n][budget] << endl;
}