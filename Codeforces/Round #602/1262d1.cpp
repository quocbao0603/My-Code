#include <bits/stdc++.h>
#define NMAX 500000
using namespace std;
int n;
int a[NMAX];

struct data{
	int gt, vt;
};
vector <data> b;
vector <int> pos;
bool cmp(const data  &a, const data &b){
	if (a.gt != b.gt)
	return a.gt > b.gt;
	return a.vt < b.vt;
}

int main(){
	cin >> n;
	for (int i = 1; i < n + 1; i++){
		cin >> a[i];
	}
	int m;
	for (int j = 1; j <= n; j++){
		data tmp;
		tmp.gt = a[j];
		tmp.vt = j;
		b.push_back(tmp);
	}
	sort(b.begin(), b.end(), cmp);
	cin >> m;
	for (int i = 1; i < m + 1; i++){
		int x, y;
		cin >> x >> y;
		pos.clear();
		for (int j = 0; j < x; j++){
			pos.push_back(b[j].vt);
		}
		sort(pos.begin(), pos.end());
		cout << a[pos[y - 1]] << endl;
	}
}
