#include <bits/stdc++.h>
#define  io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define ALL(a) a.begin(),a.end()

typedef long long ll;
const double PI = acos(-1.0);
const int N = 5555;
const int oo = 1e9;

using namespace std;
struct ii{
    int value, index;
};

//Khai bao
int n, m, k;
int dq[N], a[N];
void process1(){
    int res = 0;
    for (int i = 1; i <= m; i++){
        res = max(res, a[i]);
        res = max(res, a[n - i + 1]);
    }
    cout << res << endl;
}

void process2(){
    int res = 0;
    for (int l_forced = 0; l_forced <= k; l_forced++){
        int r_forced = k - l_forced;
        int ans2 = oo;
        for (int l = 0; l <= (m - 1) - k; l++){
            int r = (m - 1) - k - l;
            int ans = max(a[l + l_forced + 1], a[n - (r + r_forced)]);
            //debug(r_forced);
            //debug(r);
            //cout << l + l_forced + 1 << " " << n - (r + r_forced) << endl;
            //debug(ans);
            ans2 = min(ans2, ans);
        }
        //cout << ans2 << endl;
        res = max(res, ans2);
    }
    cout << res << endl;
}

void read(){
    freopen("inp.inp", "r",stdin);
    freopen("out.out", "w", stdout);
}

int main(){
    io

    read();
    int testcase;
    cin >> testcase;
    while (testcase--){
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        if (k >= m - 1){
            process1();
        }
        else {
            process2();
        }
    }
}
