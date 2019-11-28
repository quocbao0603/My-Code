#include <bits/stdc++.h>

using namespace std;

int n;

int main(){
    freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);
    int testcase;
    cin >> testcase;
    while (testcase--){
            int c, sum;
        cin >> c >> sum;
        if (c > sum){
            cout << sum << endl;
        }
        else {
            int loai1 = sum / c;
            int loai2 = sum / c + 1;
            long long res = 0;
            for (int i = 1; i <= sum % c; i++){
                res += 1ll * loai2 * loai2;
            }
            for (int i = 1; i <= c - sum % c; i++){
                res += 1ll * loai1 * loai1;
            }
            cout << res << endl;
        }
    }
}
