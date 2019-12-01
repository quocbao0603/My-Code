#include <bits/stdc++.h>
#define  io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define db(X) ({ if(1) cerr << "db: " << (#X) << " = " << (X) << endl; })
typedef long long ll;
#define N 333333
const int oo = 1e9;
using namespace std;

string p[12];
void read(){
    freopen("b.inp", "r",stdin);
    freopen("b.out", "w", stdout);
}
int res;
int cong(string& s){
    if (s[3] == '9'){
        s[3] = '0';
    }
    else s[3] = s[3] + 1;
    return 1;
}

int main(){
    read();
    int test, n;
    cin >> test;
    while (test--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> p[i];
        }
        p[n + 1] = "";
        res = 0;
        for (int i = 1; i <= n; i++){
            int ans = 0;
            while(true){
                bool flag = true;
                for (int j = 1; j <= n; j++){
                    if (i !=j &&p[i] == p[j]){
                        flag = false;
                    }
                }
                if (flag) break;
                ans = cong(p[i]);

            }
            //cout << ans << endl;
            res += ans;
        }
            //cout << endl;
        cout << res << endl;
        for (int i = 1; i <= n; i++){
            cout << p[i] << endl;
        }
    }
    cerr << isalpha('A') << endl;
}
