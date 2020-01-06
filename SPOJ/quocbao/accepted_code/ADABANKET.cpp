#include <bits/stdc++.h>
#define name "ADABANKET"
using namespace std;
const int maxn=910;
int n,top;
int a[maxn][maxn];
int d[maxn],c[maxn];
void nhap(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
}
void dfs(int u){
    for (int v=1;v<=n;v++){
        if (a[u][v]==1 &&d[v]==0){
            d[v]=1;
            dfs(v);
        }
    }
}
void xuli(){
    d[1]=1;
    dfs(1);
    for (int i=1;i<=n;i++){
        if (d[i]==0){
            cout<<-1;return;
        }
    }
    int res=n;
    for (int i=1;i<=n;i++){
        int ans=0;
        for (int j=1;j<=n;j++){
            if (a[i][j]==1)ans++;
        }
        res=min(res,ans);
    }
    cout<<res*2;
}
int main(){
 //   freopen(name".inp","r",stdin);
 //   freopen(name".out","w",stdout);
    nhap();
    xuli();
}
