#include <iostream>
#include <string>
#include <algorithm>
#define N 212345
using namespace std;
int n;
int a[N], f1[N], f2[N];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n;i++)
	if (a[i] > a[i - 1])
		f1[i] = f1[i - 1] + 1;
	else
		f1[i] = 1;

	for (int i = n; i >= 1;i--)
	if (a[i] < a[i + 1])
		f2[i] = f2[i + 1] + 1;
	else
		f2[i] = 1;

	int kq = 1;

	for (int i = 1; i <= n; i++)
		kq = max(kq, f1[i]);

	for (int i = 1; i + 2 <= n;i++)
	if (a[i] < a[i + 2])
		kq = max(kq, f1[i] + f2[i + 2]);
	cout << kq;
	return 0;
}
