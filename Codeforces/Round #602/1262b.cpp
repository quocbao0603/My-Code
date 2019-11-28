#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 100;

int n;
int a[maxn], p[maxn], d[maxn];

void solve(){
    for (int i = 1; i <= n; i++){
        d[i] = 0;
    }
    int c = 1;
    for (int i = 1; i <= n; i++){
        if (p[i] > p[i - 1]){
            a[i] = p[i];
            d[p[i]] = 1;
        }
        else {
            a[i] = 0;
        }
    }
    for (int i = 1;  i <= n;i ++){
        if (a[i] == 0){
            while (d[c] == 1)c++;
            if (c > p[i]){
                cout << -1 << endl;
                return;
            }
            a[i] = c++;
            d[a[i]] = 1;
        }
    }
    for (int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    freopen("b.inp", "r", stdin);
    freopen("b.out", "w", stdout);
    int testcase;
    cin >> testcase;
    while (testcase--){
       cin >> n;
       for (int i = 1; i <= n;i++){
        cin >> p[i];
       }
       solve();
    }
}
