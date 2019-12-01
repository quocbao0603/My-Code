#include <bits/stdc++.h>
#define  io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define db(X) ({ if(1) cerr << "db: " << (#X) << " = " << (X) << endl; })
typedef long long ll;
#define N 333333
const int oo = 1e9;
using namespace std;

int n;
ll a[10];
ll res;
void read(){
    freopen("a.inp", "r",stdin);
    freopen("a.out", "w", stdout);
}
int main(){
    read();
    int testcase;
    cin >> testcase;
    while (testcase--){
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        //cout << a[0] << " " << a[1] << " " << a[2] << endl;
        if (a[0] + a[1] >= a[2]){
            res = (a[1] + a[2] + a[0]) / 2;
        }
        else {
            res = (a[0] + a[1]);
        }
        cout << res << endl;
    }
}
