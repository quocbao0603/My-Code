#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("C.inp", "r", stdin);
    int T;
    cin >> T;
    while (T--){
        int r, b, k;
        cin >> r >> b >> k;
        if (r > b)swap(r, b);
        int x = __gcd(r, b);
        if (b == 1){
            cout << "OBEY" << endl;
            continue;
        }
        r /= x;
        b /= x;
        int res = 1 + (b - 2) / r;
        if (k > res){
            cout << "OBEY" << endl;
        }
        else {
            cout << "REBEL" << endl;
        }
    }
}
