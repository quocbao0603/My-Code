#include <bits/stdc++.h>
#define  io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define ALL(a) a.begin(),a.end()

typedef long long ll;
const double PI = acos(-1.0);
const int N = 1234567;
const int oo = 1e9;

using namespace std;
struct ii{
    ll value;
    int sl;
};

//Khai bao
int a[N];
ii s[N];
int n, top;

bool cmp(int i){
    ll A = s[i - 1].value, B = s[i - 1].sl;
    ll C = s[i].value, D = s[i].sl;
    return (A * D >= C * B);
}

void read(){
    freopen("inp.inp", "r",stdin);
    freopen("out.out", "w", stdout);
}

int main(){
    io

    read();

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    s[1] = {a[1], 1};
    top = 1;

    for (int i = 2; i <= n; i++){
        top++;
        s[top] = {a[i], 1};
        while (top > 1 && cmp(top)){
            s[top - 1].value += s[top].value;
            s[top - 1].sl += s[top].sl;
            top--;
        }
    }
    fixed(cout);
    for (int i = 1; i <= top; i++){
        //cout << s[i].value <<"  " << s[i].sl << endl;
        double res = 1.0 * s[i].value / s[i].sl;
        for (int j = 1; j <= s[i].sl; j++){
            cout << setprecision(9) << res << '\n';
        }
    }
}
