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
string s, res;
int testcase, n;

void read(){
    freopen("inp.inp", "r",stdin);
    freopen("out.out", "w", stdout);
}

int main(){
    io

    read();
    cin >> testcase;
    while (testcase--){
        cin >> n;
        cin >> s;
        res.clear();
        while (s.size() > 0 && (s.back() - '0') % 2 == 0)s.pop_back();
        //cout << s << endl;
        int noteven = 0;
        for (int i = 0; i < s.size(); i++){
            if ((s[i]- '0') % 2 == 1)noteven++;
        }
        if (noteven <= 1)cout << -1 << endl;
        else {
            if (noteven % 2 == 0){
                cout << s << endl;
                continue;
            }
            int del = 0;
            res.push_back(s.back());
            for (int i = s.size() - 2; i >= 0; i--){
                if (del == 0 && (s[i] - '0') % 2 == 1){
                    del++;
                }
                else res.push_back(s[i]);
            }
            reverse(res.begin(), res.end());
            cout << res << endl;
        }
    }
}
