#include <bits/stdc++.h>
#define  io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define ALL(a) a.begin(),a.end()

typedef long long ll;
const double PI = acos(-1.0);
#define N 1123456
using namespace std;
int Ttest;
int n;
int a[N],b[N];
bool f1[N],f2[N];
int main()
{
	cin >> Ttest;
	while (Ttest--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		int dem = 0;
		f1[0] = true;
		for (int i = 1; i <= n; i++)
		{
			f1[i] = (f1[i - 1] && a[i] >= dem);
			dem++;
		}

		dem = 0;
		f2[n + 1] = true;
		for (int i = n; i >=1 ; i--)
		{
			f2[i] = (f2[i + 1] && a[i] >= dem);
			dem++;
		}

		bool kt = false;
		kt = (f1[n] || f2[1]);
		for (int i = 1; i <= n; i++)
		if (f1[i] && f2[i])
		{
			kt = true;
			break;
		}
		if (kt) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
