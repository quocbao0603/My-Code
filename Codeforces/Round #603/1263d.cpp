#include <bits/stdc++.h>
#define  io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define db(X) ({ if(1) cerr << "db: " << (#X) << " = " << (X) << endl; })
typedef long long ll;
#define N 211111
const int oo = 1e9;
using namespace std;
string s[N];
int cha[N], con[N], res, n;

vector <int> c[30];

void read(){
    freopen("d.inp", "r",stdin);
    freopen("d.out", "w", stdout);
}
int findset(int x){
    if (cha[x] == -1){
        return x;
    }
    else {
        cha[x] = findset(cha[x]);
        return cha[x];
    }
}

void uni(int u, int v){
    u = findset(u);
    v = findset(v);
    if (u == v)return;
    res--;
    if (con[u] > con[v]){
        cha[u] = v;
        con[v] += con[u];
    }
    else {
        cha[v] = u;
        con[u] += con[v];
    }
}

int main(){
    read();
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < s[i].size(); j++){
            int x = s[i][j] - 'a';
            c[x].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++){
        con[i] = 1;
        cha[i] = -1;
    }
    res = n;
    for (int i = 0; i < 26; i++){
        for (int j = 1; j < c[i].size(); j++){
            uni(c[i][j], c[i][j - 1]);
        }
    }
    cout << res;
}
