#include <bits/stdc++.h>
#define  io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define db(X) ({ if(1) cerr << "db: " << (#X) << " = " << (X) << endl; })
typedef long long ll;
#define N 333333
const int oo = 1e9;
using namespace std;
struct ii{
    int value, index;
};


int n, m;
ii a[N];
ll sum[N], s[N];
void read(){
    freopen("inp.inp", "r",stdin);
    freopen("out.out", "w", stdout);
}
bool ss(ii a, ii b){
    return a.value < b.value;
}

int main(){
    read();
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i].value;
        a[i].index = i;
    }
    sort(a + 1, a + 1 + n, ss);
    for (int i = 1; i <= n; i++){
        sum[i] = sum[i - 1] + a[i].value;
    }
    for (int i = 1; i <= n; i++){
        s[i] = sum[i];
        if (i > m) s[i] += s[i - m]- sum[i - m];
        if (i > m){
            s[i] += sum[i - m];
        }
        cout << s[i] << " ";
    }
}
