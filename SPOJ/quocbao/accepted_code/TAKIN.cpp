#include <bits/stdc++.h>
#define name "takin"
using namespace std;
const int maxn=22;
long long m,res,ans;
int a[maxn];
int n;
int getbit(int k,int n){
    return(n>>k&1);
}
int main(){
   // freopen(name".inp","r",stdin);
   // freopen(name".out","w",stdout);
    int test;
    cin>>test;
    while (test--){
        cin>>n>>m;
        for (int i=0;i<n;i++)cin>>a[i];
        res=0;
        for (int i=0;i<(1<<n);i++){
            long long ans=0;
            for (int j=0;j<n;j++){
                if (getbit(j,i)==1){
                    ans+=a[j];
                }
            }
            if (ans<=m && res<ans){
                res=ans;
            }
        }
        cout<<res<<"\n";
    }
}
