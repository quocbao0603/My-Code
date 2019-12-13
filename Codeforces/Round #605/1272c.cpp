#include <bits/stdc++.h>
#define  io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
typedef long long ll;
const double PI = acos(-1.0);
const int N = 333333;
const int oo = 1e9;

using namespace std;
struct ii{
    int value, index;
};

//Khai bao

int n, k;
string s;
char x;
int d[1000];
int a[1000];

void read(){
    freopen("inp.inp", "r",stdin);
    freopen("out.out", "w", stdout);
}

int main(){
    io

    read();
    cin >> n >> k;
    getline(cin, s);
    getline(cin, s);
    for (int i = 1; i <= k; i++){
        cin >> x;
        int l = x - 'a';
        d[l] = 1;
    }
    int j = 0, sl = 0;
    ll res = 0;
    int l;
    for (int i = 0; i < s.size(); i++){
        l = s[i] - 'a';
        a[l] += d[l];
        sl += d[l];
        while (j < s.size() && sl < i - j + 1){
            l = s[j] - 'a';
            a[l] -= d[l];
            sl -= d[l];
            j++;
        }
        if (i >= j) res += 1ll * i - j + 1;
        //cout << i << " " << j << " " << sl << endl;
    }
    cout << res << endl;
}
