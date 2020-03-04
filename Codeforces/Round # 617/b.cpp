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

int a[N];
int n;

void read(){
    freopen("inp.inp", "r",stdin);
    freopen("out.out", "w", stdout);
}

int main(){
    io
    read();
    int test;
    cin >> test;
    while(test--){
        cin >> n;
        for (int i = 1; i <= 2 * n; i++){
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n * 2);
        cout << a[n + 1] - a[n] << endl;
    }

}
