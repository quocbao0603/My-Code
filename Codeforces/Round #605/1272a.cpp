#include <bits/stdc++.h>
#define  io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
typedef long long ll;
const double PI = acos(-1.0);
const int N = 333333;
const int oo = 1e10;

using namespace std;
struct ii{
    int value, index;
};

//Khai bao
ll res, a, b,c;

int q;

void read(){
    freopen("inp.inp", "r",stdin);
    freopen("out.out", "w", stdout);
}

ll thu(ll a, ll b, ll c){
    return abs(a - b) + abs(b - c) + abs(c - a);
}

int main(){
    io

    read();
    cin >> q;

    while (q--){
         res = oo;
        cin >> a >> b >> c;
        for (int i = -1; i <= 1; i++){
            for (int j = -1; j <= 1; j++){
                for (int k = -1; k <= 1; k++){
                    ll x = a + i, y = b + j, z = c + k;
                    res = min(res, thu(x, y, z));
                    res = min(res, thu(x, z, y));
                    res = min(res, thu(y, x, z));
                    res = min(res, thu(y, z, x));
                    res = min(res, thu(z, y, x));
                    res = min(res, thu(z, x, y));
                }
            }
        }
        cout << res << endl;
    }
}
