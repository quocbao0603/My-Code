#include <bits/stdc++.h>

using namespace std;

const int maxn = 212312;
pair<int,int> a[maxn];
int n;
int main() {
    freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);
	int testcase;
	cin >> testcase;
	while (testcase--)
	{
		cin >> n;
		int m = 0;
		for (int i = 1; i <= n; i++)
		{
			m++;
			cin >> a[m].first;
			a[m].second = 0;
			m++;
			cin >> a[m].first;
			a[m].second = 1;
		}
		int l1, l2, r1,r2;
		sort(a + 1, a + m + 1);
		for (int i = 1; i <= m; i++)
			if (a[i].second == 1)
			{
				l2 = a[i].first;
				l1 = a[i - 1].first;
				break;
			}
		for (int j = m; j >= 1; j--)
			if (a[j].second==0)
			{
				r1 = a[j].first;
				r2 = a[j + 1].first;
				break;
			}
		if (l2 < r1) cout << r1 - l2; else cout << 0;
		cout << "\n";
	}
	return 0;
}
