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

int a[N], n;
int f[N][50];
void read(){
    freopen("inp.inp", "r",stdin);
    freopen("out.out", "w", stdout);
}
void batbit(int &n, int k){
    n = n | (1 << k);
}

int value(int x){
    int res = 0;
    for (int j = 0; j < 32; j++){
        if ((x & 1 == 1) && (f[n][j] == 1)){
            batbit(res, j);
        }
        x = x >> 1;
    }
    //cerr << res << endl;
    return res;
}

int main(){
    io
    read();
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        int x = a[i];
        for (int j = 0; j < 32; j++){
            f[i][j] = f[i - 1][j];
            if (x & 1 == 1){
                f[i][j]++;
            }
            x = x >> 1;
        }
    }
//    for (int j = 0 ; j< 32; j++){
//        cout << f[n][j] << " ";
//    }
//    cout << endl;
    int res = 0;
    for (int i = 1; i <= n; i++){
        int tmp = value(a[i]);
        //cout << tmp << endl;
        if (tmp > res){
            swap(a[1], a[i]);
            res = tmp;
        }
    }
    //cout << res << endl;
    for (int i = 1; i <= n; i++){
        cout << a[i] <<  " ";
    }
}
