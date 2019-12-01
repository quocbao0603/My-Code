#include <bits/stdc++.h>
#define  io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define db(X) ({ if(1) cerr << "db: " << (#X) << " = " << (X) << endl; })
typedef long long ll;
#define N 333333
const int oo = 1e9;
using namespace std;

int a[N], b[N];

void read(){
    freopen("inp.inp", "r",stdin);
    freopen("out.out", "w", stdout);
}

int main(){
    read();
    int testcase, n;
    cin >> testcase;
    while(testcase--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++){
            cin >> b[i];
        }
        int l = 1;
        int r = n;
        while (l <= n && a[l] == b[l])l++;
        while (r >= 1 && a[r] == b[r])r--;
        bool flag = true;
        if (l <= r && a[l] - b[l] > 0)flag = false;
        for (int i = l + 1; i <= r; i++){
            if (b[i] - a[i] != b[i - 1] - a[i -1]){
                flag = false;
                break;
            }
        }
        if (flag){
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

}
