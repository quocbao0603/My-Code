#include <bits/stdc++.h>
using namespace std;
int testcase, sum, m, n, a;
int main() {
	cin >> testcase;
	while (testcase--){
		cin >> n >> m;
		sum = 0;
		for (int i = 1; i <= n; i++){
			cin >> a;
			sum += a;
		}
		if (m != n || n == 2)cout << -1 << endl;
		else {
			cout << sum * 2 << endl;
			for (int i = 1; i <= n; i++){
				cout << i << " "  << i % n + 1 << endl;
			}
		}
	}
	return 0;
}
