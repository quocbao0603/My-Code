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
int countn, sum;
int a[N];

void read(){
    freopen("inp.inp", "r",stdin);
    freopen("out.out", "w", stdout);
}

int main(){
    io

    read();
    int test, n;
    cin >> test;
    while(test--){
        countn = 0;
        sum = 0;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++){
            if (a[i] == 0){
                countn++;
                a[i]++;
            }
            sum += a[i];
        }
        if (sum == 0){
            countn++;
        }
        cout << countn << endl;
    }
}
