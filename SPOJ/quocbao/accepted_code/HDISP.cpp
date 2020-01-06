#include <bits/stdc++.h>
#define name "dispath"
using namespace std;
const int maxn=1e5+100;
vector <int>a[maxn];
int l[maxn],r[maxn],number[maxn],hire[maxn],ex[maxn],nguocnum[maxn],sl[maxn];
long long ans[maxn],kq;
int it[maxn*10],itw[maxn*10];
int n,m,countt,wres,res;
void nhap(){
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        int x;
        scanf("%d%d%d",&x,&hire[i],&ex[i]);
        if (i!=0)a[x].push_back(i);
    }
}
void dfs(int u){
    countt++;
    l[u]=countt;
    number[u]=countt;
    for (int i=0;i<a[u].size();i++){
        int v=a[u][i];
        dfs(v);
    }
    r[u]=countt;
}
void update(int u,int w,int l,int r,int i){
    if (u== l && r==l){
        it[i]=u;
        itw[i]=w;
        return;
    }
    if (r<u || u<l)return;
    int mid=(l+r)>>1;
    update(u,w,l,mid,i*2);
    update(u,w,mid+1,r,i*2+1);
    if (itw[i*2]>itw[i*2+1]){
        itw[i]=itw[i*2];
        it[i]=it[i*2];
    }
    else {
        itw[i]=itw[i*2+1];
        it[i]=it[i*2+1];
    }
}
void findit(int u,int v,int l,int r,int i){
    if (r<u || v<l)return;
    if (u<=l && r<=v){
        if (wres<itw[i]){
            wres=itw[i];
            res=it[i];
        }
        return;
    }
    int mid=(l+r)>>1;
    findit(u,v,l,mid,i*2);
    findit(u,v,mid+1,r,i*2+1);
}
void dft(int u){
    sl[u]++;
    ans[u]+=hire[u];
    for (int i=0;i<a[u].size();i++){
        int v=a[u][i];
        dft(v);
        sl[u]+=sl[v];
        ans[u]+=ans[v];
    }
    while (ans[u]>m){
        wres=0;
        findit(l[u],r[u],1,n,1);
        update(res,0,1,n,1);
        sl[u]--;
        ans[u]-=hire[nguocnum[res]];
    }
//    cout<<u<<" "<<sl[u]<<" "<<ans[u]<<" "<<endl;
    kq=max(kq,(long long)ex[u]*sl[u]);
}
void xuli(){
//    for (int i=1;i<=n;i++){
//        cout<<number[i]<<" "<<l[i]<<" "<<r[i]<<" "<<endl;
//    }
    for (int i=1;i<=n;i++){
        wres=0;
        nguocnum[number[i]]=i;
        update(number[i],hire[i],1,n,1);
    }
    dft(1);
}
int main(){
   // freopen(name".inp","r",stdin);
   // freopen(name".out","w",stdout);
    nhap();
    dfs(1);
    xuli();
    cout<<kq;
}
