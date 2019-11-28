#include <iostream>
#define N 4567
using namespace std;
int n,testcase;
int a[N];
typedef long long ll;
const ll MOD = 998244353;
ll dp[N][N];
ll k;
void cal(ll &a, ll b,ll k)
{
	a = (a + b * k)%  MOD;
}
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	a[n + 1] = a[1];
	a[0] = a[n];
	dp[0][n] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = n-i; j <= n+i; j++)
		if (a[i] == a[i-1])
			cal(dp[i][j],dp[i - 1][j],k);
		else
		{
			cal(dp[i][j], dp[i - 1][j-1],1);
			cal(dp[i][j], dp[i - 1][j+1], 1);
			cal(dp[i][j], dp[i - 1][j], k-2);
		}
	}
	ll kq = 0;
	for (int i = n+1; i <= 2*n; i++)
		cal(kq, dp[n][i], 1);
	cout << kq;
	return 0;
}
