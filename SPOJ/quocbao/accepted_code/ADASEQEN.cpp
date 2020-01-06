#include <bits/stdc++.h>
#define name "ADASEQE"
using namespace std;
const int maxn=2100;
int n,m;
int a[maxn],d[maxn],b[maxn];
int f[maxn][maxn];
void nhap(){
    string s;
    cin>>m>>n;
    getline(cin,s);
    for (int i=0;i<26;i++)cin>>d[i];
    getline(cin,s);
    getline(cin,s);
    for (int i=1;i<=m;i++){
        a[i]=s[i-1]-'a';
    }
    getline(cin,s);
    for (int i=1;i<=n;i++){
        b[i]=s[i-1]-'a';
    }
//    for (int i=1;i<=m;i++){
//        cout<<a[i]<<" ";
//    }cout<<endl;
//    for (int i=1;i<=n;i++){
//        cout<<b[i]<<" ";
//    }
//    cout<<endl;
}
void xuli(){
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            f[i][j]=max(f[i-1][j],f[i][j-1]);
            if (a[i]==b[j]){
                f[i][j]=max(f[i][j],f[i-1][j-1]+d[a[i]]);
            }
        }
    }
    cout<<f[m][n];
}
int main(){
   // freopen(name".inp","r",stdin);
   // freopen(name".out","w",stdout);
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    nhap();
    xuli();
}
