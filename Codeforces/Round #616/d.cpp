#include <bits/stdc++.h>
#define  io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define ALL(a) a.begin(),a.end()

typedef long long ll;
const double PI = acos(-1.0);
const int N = 333333;
const int oo = 1e9;

using namespace std;
struct ii{
    int value, index;
};

//Khai bao

int n, l, r, countn;
string s;
int dp[N][30];

void read(){
    freopen("inp.inp", "r",stdin);
    freopen("out.out", "w", stdout);
}

int main(){
    io

    read();
    cin >> s;
    n = s.size();
    s = "*" + s + "*";
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < 26; j++){
            dp[i][j] = dp[i - 1][j];
        }
        dp[i][s[i] - 'a']++;
    }
    int testcase;
    cin >> testcase;
    while(testcase--){
        cin >> l >> r;
        if (s[l] != s[r] || l == r){
            cout << "Yes" << endl;
            continue;
        }
        countn = 0;
        for (int i = 0; i < 26; i++){
            if (dp[r][i] - dp[l - 1][i] > 0) countn++;
        }
        if (countn >= 3){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
}
