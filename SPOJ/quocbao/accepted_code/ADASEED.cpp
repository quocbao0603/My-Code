#include <bits/stdc++.h>
#define name "ADASEED"
using namespace std;
const int maxn=2e5+100;
int a[maxn],b[maxn],bit[maxn];
vector <int>vt[maxn];
int n,l;
void nhap(){
    scanf("%d%d",&n,&l);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for (int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        vt[b[i]].push_back(i);
    }
}
void updatebit(int x, int val) {
  while (x <= n) {
    bit[x] = max(bit[x], val);
    x += (x) & (-x);
  }
}

int findbit(int x) {
  int res = 0;
  while (x) {
    res = max(res, bit[x]);
    x -= (x) & (-x);
  }
  return res;
}
void xuli(){
    int res=0;
    for (int i=1;i<=n;i++){
        for (int j=vt[a[i]].size()-1;j>=0;j--){
            int u=vt[a[i]][j];
            int gt=findbit(u-1);
            updatebit(u,gt+1);
            res=max(res,gt+1);
        }
    }
    printf("%d\n",(n-res)*2);
}
void init(){
    memset(bit,0,sizeof bit);
    for (int i=0;i<l;i++)vt[i].clear();
}
int main(){
    //freopen(name".inp","r",stdin);
    //freopen(name".out","w",stdout);
    int test=0;
    scanf("%d",&test);
    while (test--){
        nhap();
        xuli();
        init();
    }
}
