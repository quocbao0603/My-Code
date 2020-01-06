#include <bits/stdc++.h>
#define name "np01"
using namespace std;
int n,m;
const int maxn=1e5;
string x;
int s[maxn];
long long sum[maxn],ss[maxn];
long long sum1(int l,int r){
    long long t=1ll*s[r]*(r-l);
//    cout<<s[r]<<endl;
//    cout<<t<<" "<<(ss[r-1]-ss[l-1])<<" "<<sum[r-l]<<" "<<r-l<<endl;;
    t=t-(ss[r-1]-ss[l-1])-(sum[r-l]);
    return(t);
}
long long sum2(int l,int r){
    long long t=s[l]*(r-l);
    t=(ss[r]-ss[l])-t-(sum[r-l]);
    return(t);
}
void nhap(){
    cin>>m;
    getline(cin,x);
    getline(cin,x);
    n=x.size();
    int top=0;
    for (int i=1;i<=n;i++){
        if (x[i-1]=='1'){
            top++;
            s[top]=i;
            ss[top]=ss[top-1]+s[top];
        }
    }
//    cout<<top<<endl;
//    for (int i=1;i<=top;i++){
//        cout<<ss[i]<<" ";
//    }
//    cout<<endl;
    for (int i=1;i<=m;i++){
        sum[i]=sum[i-1]+i;
    }
//    for (int i=1;i<=m;i++){
//        cout<<sum[i]<<" ";
//    }
//    cout<<endl;
    long long res=2e9;
    for (int i=1;i<=top-m+1;i++){
        if (m%2==0){
            int l=i;
            int r=i+m-1;
            int mid=(l+r)>>1;
//            cout<<l<<" "<<mid<<" "<<r<<endl;
            res=min(res,sum1(l,mid)+sum2(mid,r));
//            cout<<sum1(l,mid)<<" "<<mid<<" "<<sum2(mid,r)<<endl;
            mid++;
            res=min(res,sum1(l,mid)+sum2(mid,r));
//            cout<<sum1(l,mid)<<" "<<sum2(mid,r)<<endl;
//            cout<<res<<endl;
        }
        else {
            int l=i;
            int r=i+m-1;
            int mid=(l+r)>>1;
            res=min(res,sum1(l,mid)+sum2(mid,r));
//            cout<<res<<endl;
        }
    }
    cout<<res<<"\n";
}
int main(){
 //   freopen(name".inp","r",stdin);
  //  freopen(name".out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test=0;
    cin>>test;
    while (test--){
    nhap();
    }
}
