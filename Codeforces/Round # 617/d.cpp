#include <bits/stdc++.h>
#define  io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define ALL(a) a.begin(),a.end()

typedef long long ll;
const double PI = acos(-1.0);
const int N = 333333;
const int oo = 1e9;

using namespace std;

//Khai bao
struct dl{
    int x, y;
};

dl a[N],b[N];

int n,Ttest;

void read(){
    freopen("inp.inp", "r",stdin);
    freopen("out.out", "w", stdout);
}


int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].x >> a[i].y;

	if (n % 2 == 0)
	{
		a[n + 1] = { a[1].x, a[1].y };

		for (int i = 1; i <= n; i++)
			b[i] = { a[i + 1].x - a[i].x, a[i + 1].y - a[i].y };

		n = n / 2;
		for (int i = 1; i <= n;i++)
		if (b[i].x != -b[i + n].x || b[i].y != -b[i + n].y)
		{
			cout << "NO";
			return 0;
		}
		cout << "YES";
		return 0;
	}

	cout << "NO";
	return 0;
}
