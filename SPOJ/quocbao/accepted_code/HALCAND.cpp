#include <bits/stdc++.h>
#define name "HALCAND"
using namespace std;
const int maxn=1010;
int n,k;
int a[maxn];
long long res;
void nhap(){
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
}
bool check(long long  x){
    long long sl=x*k;
    for (int i=1;i<=n;i++){
        sl-=min(1ll*a[i],x);
    }
    if (sl<=0)return(true);
    return(false);
}
void xuli(){
    long long  l=0;
    long long  r=1e12;
    res=0;
    while (l<=r){
        long long mid=(l+r)>>1;
        if (check(mid)==true){
            l=mid+1;
            res=mid;
        }
        else r=mid-1;
    }
}
int main(){
    //freopen(name".inp","r",stdin);
    //freopen(name".out","w",stdout);
    int test=0;
    scanf("%d",&test);
    for (int t=1;t<=test;t++){
        nhap();
        xuli();
        printf("Case %d: %lld\n",t,res);
    }
}
