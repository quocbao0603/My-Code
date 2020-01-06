#include <iostream>
#include <fstream>
#include <vector>
#define ten "ADAPLNTS"
using namespace std;
const int maxn = 10000;
vector <int> a[maxn];
int matchx[maxn],matchy[maxn],Visit[maxn],b[maxn],c[maxn];
int Count,m,n,socanh;
void mo(){
    freopen(ten".inp","r",stdin);
    freopen(ten".out","w",stdout);
}
int ucln(int a,int b){
    while (b!=0){
        a=a%b;
        swap(a,b);
    }
    return(a);
}
void nhap(){
    cin>>m>>n;
    for (int i=1;i<=m;i++){
        cin>>b[i];
    }
    for (int i=1;i<=n;i++){
        cin>>c[i];
    }
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            if (ucln(b[i],c[j])>=2){
                a[i].push_back(j);
            }
        }
    }
}
bool dfs(int u){
    if (Visit[u]!=Count) Visit[u]=Count; else return(false);
    for (int i=0;i<a[u].size();i++){
        int v;
        v=a[u][i];
        if (matchy[v]==0 || dfs(matchy[v])==true ){
            matchy[v]=u;
            return(true);
        }
    }
    return(false);
}
void xuli(){
    int res;
    res=0;
    for (int i=1;i<=m;i++){
        if (matchx[i]==0){
            Count++;
            if (dfs(i)==true) res++;
        }
    }
    cout<<n+m-res;
}
int main(){
 //  mo();
   nhap();
   xuli();
}
