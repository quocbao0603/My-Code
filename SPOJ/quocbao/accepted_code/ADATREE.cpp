#include <bits/stdc++.h>
#define name "ADATREE"
using namespace std;
const int maxn=3e5+100;
int n,q,res;
int a[maxn],ans[maxn];
int it[maxn*5];
pair <int,int>b[maxn];
struct qs{
    int l,r,cs,h;
};
qs query[maxn];
void mo(){
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
}
void nhap(){
    scanf("%d%d\n",&n,&q);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    scanf("\n");
    for (int i=1;i<=q;i++){
        scanf("%d%d%d\n",&query[i].l,&query[i].r,&query[i].h);
        query[i].l++;
        query[i].r++;
        query[i].cs=i;
    }
}
void update(int u,int w,int l,int r,int i){
    if (r<u || u<l)return;
    if (u==l && l==r){
        it[i]=w;
        return;
    }
    int mid=(l+r)>>1;
    update(u,w,l,mid,i*2);
    update(u,w,mid+1,r,i*2+1);
    it[i]=max(it[i*2],it[i*2+1]);
}
void findit(int u,int v,int l,int r,int i){
    if (r<u || v<l)return;
    if (u<=l && r<=v){
//        cout<<l<<" "<<r<<" "<<it[i]<<endl;
        res=max(res,it[i]);
        return;
    }
    int mid=(l+r)>>1;
    findit(u,v,l,mid,i*2);
    findit(u,v,mid+1,r,i*2+1);
}
bool ss(qs a,qs b){
    return(a.h<b.h);
}
void xuli(){
    for (int i=1;i<=n;i++){
        b[i].first=a[i];
        b[i].second=i;
    }
    sort(b+1,b+1+n);
    sort(query+1,query+1+q,ss);
//    for (int i=1;i<=q;i++){
//        cout<<query[i].l<<" "<<query[i].r<<" "<<query[i].h<<" "<<query[i].cs<<endl;
//    }
    int j=1;
    for (int i=1;i<=q;i++){
        int ll=query[i].l;
        int rr=query[i].r;
        int hh=query[i].h;
        while (j<=n && b[j].first<=hh){
            update(b[j].second,b[j].first,1,n,1);
            j++;
        }
        res=0;
        findit(ll,rr,1,n,1);
        ans[query[i].cs]=res;
//        cout<<res<<endl;
    }
    for (int i=1;i<=q;i++){
        printf("%d\n",ans[i]);
    }
}
int main(){
//    mo();
    nhap();
    xuli();
}
