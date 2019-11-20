#include <bits/stdc++.h>
#define N 111111
using namespace std;
int n;
int a[3];
int d[N], edgeid[N], check[N];

struct edge{
    int v1, v2, id;
};

vector <edge> adj[N];
vector <int> res;

void addEdge(int u, int v, int w, int id){
    adj[u].push_back({v, w, id});
}
int main(){
    freopen("c.inp", "r", stdin);
    freopen("c.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int id = 1; id <= n - 2; id ++){
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        do {
            addEdge(a[0], a[1], a[2], id);
        }while (next_permutation(a, a + 3));
        d[a[0]]++;
        d[a[1]]++;
        d[a[2]]++;
    }
    int start = 0;
    for (int i = 1; i <= n; i++){
        if (d[i] == 1){
            start = i;
        }
    }
    //tim diem bat dau
    res.push_back(start);
    check[start] = 1;
    // voi moi diem tim 2 thang tiep theo.
    for (int i = 1; i <= n - 2; i++){
        start = res[i - 1];
        for (edge v: adj[start]){
            if (edgeid[v.id])continue;
            edgeid[v.id] = 1;
            int v1 = v.v1, v2 = v.v2;
            if (d[v1] > d[v2]) swap(v1, v2);
            d[v1]--;
            d[v2]--;
            if (check[v1] == 0){
                res.push_back(v1);
                check[v1] = 1;
            }
            if (check[v2] == 0){
                res.push_back(v2);
                check[v2] = 1;
            }
        }
    }
    //xuat ket qua
    for (int i: res){
        cout << i << " ";
    }
}
