#include <bits/stdc++.h>
#define name "adacut"
using namespace std;
const int maxn=3e5+100;
long long s[maxn];
int a[maxn];
int n;
void nhap(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
}
void xuli(){
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    a[n+1]=a[n];
    long long w=0;
    long long res=1e18;
    for (int i=n;i>=1;i--){
        w=w+1ll*(a[i+1]-a[i])*(n-i);
        res=min(res,w+s[i-1]);
    }
    cout<<res<<endl;
}
int main(){
 //   freopen(name".inp","r",stdin);
  //  freopen(name".out","w",stdout);
    nhap();
    xuli();
}
