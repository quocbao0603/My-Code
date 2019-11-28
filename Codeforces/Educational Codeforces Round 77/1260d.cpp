#include <bits/stdc++.h>
#define db(X) ({ if(1) cerr << "db: " << (#X) << " = " << (X) << endl; })

using namespace std;
const int N = 2e5 + 100;
int n, m, k, t;
int l[N], r[N], d[N], a[N];

struct query{
    int l, r, d;
}q[N];



bool ss(query a, query b){
    return a.l < b.l;
}
int main(){
    freopen("d.inp", "r", stdin);
    freopen("d.out", "w", stdout);
    cin >> m  >> n  >>  k >> t;
    for (int i = 1; i <= m; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= k; i++){
        cin >> q[i].l >> q[i].r >> q[i].d;
    }
    sort(q + 1, q + 1 + k, ss);
    sort(a + 1, a + 1 + m, greater<int>());
    int limit = 0;
    int l = 1;
    int r = m;
    while (l <= r){
        int mid = (l + r) / 2;
        db(mid);
        int j = 1;
        int time = n + 1;
        vector<int>v(n + 1);
        for (int i = 1; i <= k; i++){
            if (q[i].d > a[mid]){
                v[q[i].l - 1]++;
                v[q[i].r]--;
            }
        }
        int bomb = 0;
        for (int i = 0; i < n + 1; i++){
            bomb += v[i];
            if (bomb > 0){
                time += 2;
            }
        }
        db(time);
        if (time <= t){
            l = mid + 1;
            limit = mid;
        }
        else  r = mid - 1;
    }
    cout << limit << endl;
}
