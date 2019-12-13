
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int d[4];
int Ttest, n,lr,du;
int main()
{
	cin >> Ttest;
	while (Ttest--)
	{
		string s;
		cin >> s;
		d[0] = d[1] = d[2] = d[3] = 0;
		for (int i = 0; i < s.length(); i++)
		{
			int tmp;
			if (s[i] == 'L') tmp = 0;
			if (s[i] == 'R') tmp = 1;
			if (s[i] == 'D') tmp = 2;
			if (s[i] == 'U') tmp = 3;
			d[tmp]++;
		}
		lr = min(d[0], d[1]);
		du = min(d[2], d[3]);
		if (min(lr, du) == 0)
		{
			lr = min(1, lr);
			du = min(1, du);
		}
		cout << lr*2 + du*2 << endl;
		for (int i = 1; i <= lr; i++)
			cout << "L";
		for (int i = 1; i <= du; i++)
			cout << "D";
		for (int i = 1; i <= lr; i++)
			cout << "R";
		for (int i = 1; i <= du; i++)
			cout << "U";
		cout << endl;
	}
	return 0;
}
