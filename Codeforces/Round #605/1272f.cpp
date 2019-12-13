#include <bits/stdc++.h>
#define  io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
typedef long long ll;
const double PI = acos(-1.0);
const int N = 210;
const int oo = 1e9;

using namespace std;
struct tt{
    int i, j, k;
    int ngoac;
};

//Khai bao

string s, t, ans;
int f[N][N][N * 2];
tt trace[N][N][N * 2];
int n, m;


void read(){
    freopen("inp.inp", "r",stdin);
    freopen("out.out", "w", stdout);
}

int main(){
    io
    read();
    cin >> s >> t;
    m = s.size();
    n = t.size();
    int maxn = max(m, n) * 2;
    s = "*" + s;
    t = "*" + t;
    for (int i = 0; i <= m; i++){
        for (int j = 0; j <= n; j++){
            for (int k = 0; k <= maxn; k++){
                f[i][j][k] = oo;
            }
        }
    }
    for (int k = 0; k <= maxn; k++){
        f[0][0][k] = k;
        trace[0][0][k] = {0, 0, k - 1, 1};
    }

    for (int i = 0; i <= m; i++){
        for (int j = 0; j <= n; j++){
            if (i == 0 && j == 0)continue;
            for (int k = 0; k <= maxn; k++){
                //add '('
                if (k > 0){
                    f[i][j][k] = f[i][j][k - 1] + 1;
                    trace[i][j][k] = {i, j, k - 1, 1};
                }
                //s[i] == '('
                if (s[i] == '('){
                    if (k > 0 && f[i - 1][j][k - 1] + 1< f[i][j][k]){
                        f[i][j][k] = f[i - 1][j][k - 1] + 1;
                        trace[i][j][k] = {i- 1, j, k - 1, 1};
                    }
                }
                //t[i] == '('
                if (t[j] == '('){
                    if (k > 0 && f[i][j - 1][k - 1] + 1 < f[i][j][k]){
                        f[i][j][k] = f[i][j - 1][k - 1] + 1;
                        trace[i][j][k] = {i, j - 1, k - 1, 1};
                    }
                }
                if (s[i] == '(' && t[j] == '('){
                    if (k > 0 && f[i - 1][j - 1][k - 1] + 1 < f[i][j][k])
                    {
                        f[i][j][k] = f[i - 1][j - 1][k - 1] + 1;
                        trace[i][j][k] = {i - 1, j - 1, k - 1, 1};
                    }
                }
                //add '('
                if (s[i] == ')')
                {
                    if (f[i - 1][j][k + 1] + 1 < f[i][j][k]){
                        f[i][j][k] = f[i - 1][j][k + 1] + 1;
                        trace[i][j][k] = {i- 1, j, k + 1, 2};
                    }
                }
                if (t[j] == ')'){
                    if (f[i][j - 1][ k + 1] + 1 < f[i][j][k]){
                        f[i][j][k] = f[i][ j - 1][k + 1] + 1;
                        trace[i][j][k] = {i, j - 1, k + 1, 2};
                    }
                }
                if (s[i] == ')' && t[j] == ')'){
                    if (f[i - 1][ j - 1][ k + 1]  + 1 < f[i][j][k]){
                        f[i][j][k] = f[i - 1][j  - 1][k + 1] + 1;
                        trace[i][j][k] = {i - 1, j - 1, k + 1, 2};
                    }
                }
            }
        }
    }
    int res = oo;
    int i = m, j = n, bac = 0;
    for (int k = 0; k <= maxn; k++){
        if (f[m][n][k] + k < res){
            res = f[m][n][k] + k;
            i = m, j = n, bac = k;
        }
    }
    ans.clear();
    for (int i = 1; i <= bac; i++){
        ans.push_back(')');
    }
    while (i != 0 || j != 0 || bac != 0){
        tt t = trace[i][j][bac];
        if (trace[i][j][bac].ngoac == 1){
            ans.push_back('(');
        }
        else ans.push_back(')');
        i = t.i;
        j = t.j;
        bac = t.k;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}
