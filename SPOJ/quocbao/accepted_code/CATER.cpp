#include <bits/stdc++.h>
using namespace std;

int n, k, x, y;
int h[2510], fr[2510];
int a[2510][2510];
int cha[2510], b[2510];
int f[2510][100];
stack<int> s;
const int modu=10243;

int main(){
    //freopen("cater.inp","r",stdin);
    //freopen("cater.out","w",stdout);
    scanf("%d %d", &n ,&k);
    for (int i=1; i<=n-1; i++){
        scanf("%d %d", &x, &y);
        h[x]++;
        a[x][h[x]]=y;
        h[y]++;
        a[y][h[y]]=x;
    }
    s.push(1);
    fr[1]=1;
    int dem=1;
    b[1]=1;
    while (s.size()>0){
        int tmp=s.top();
        s.pop();
        for (int i=1; i<=h[tmp]; i++){
            if (fr[a[tmp][i]]==0){
                dem++;
                s.push(a[tmp][i]);
                fr[a[tmp][i]]=1;
                b[dem]=a[tmp][i];
                cha[a[tmp][i]]=tmp;
            }
        }
    }
    long long kq=0;
    for (int i=1; i<=n; i++) f[i][1]=1;
    for (int i=dem; i>=1; i--){
        int u=b[i];
        int v=cha[u];
        kq=(kq+f[u][k])%modu;
        for (int l=k; l>=2; l--){
            for (int j=l-1; j>=1; j--){
                f[v][l]=(f[v][l]+(f[v][l-j]*f[u][j])%modu)%modu;
//                cout<<u<<" "<<v<<" "<<l<<" "<<f[v][l]<<endl;
            }
        }
    }
    cout<<kq<<endl;
}
