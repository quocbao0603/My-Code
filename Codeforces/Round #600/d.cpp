#include <bits/stdc++.h>
#define  io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define db(X) ({ if(1) cerr << "db: " << (#X) << " = " << (X) << endl; })
typedef long long ll;
#define N 333333
const int oo = 1e9;
using namespace std;

int p[N], con[N], maxC[N], n , m;

void read(){
    freopen("inp.inp", "r",stdin);
    freopen("out.out", "w", stdout);
}

int findset(int x){
    if (p[x] == -1)return x;
    else {
        p[x] = findset(p[x]);
        return p[x];
    }
}

void uni(int u, int v){
    u = findset(u);
    v = findset(v);
    if (u == v)return;
    if (con[u] > con[v]){
        p[u] = v;
        con[v] += con[u];
        maxC[v] = max(maxC[u], maxC[v]);
    }
    else {
        p[v] = u;
        con[u] += con[v];
        maxC[u] = max(maxC[u], maxC[v]);
    }
}

int main(){
    read();
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        p[i] = -1;
        con[i] = 1;
        maxC[i] = i;
    }
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        uni(u, v);
    }
    int i = 1;
    int res = 0;
    while (i <= n){
        for (int j = i; j <= maxC[findset(i)]; j++){
            if (findset(i) != findset(j)){
                uni(i, j);
               // cout << i << " " << j << endl;
                res++;
            }
        }
        i = maxC[findset(i)] + 1;
    }
    cout << res << endl;
}
