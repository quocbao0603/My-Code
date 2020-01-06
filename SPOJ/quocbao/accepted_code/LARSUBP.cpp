#include <bits/stdc++.h>
#define name "XAUCON"
using namespace std;
const int maxn=1e4+100;
const int base=1e9+7;
char s[maxn];
int d[100];
int n;
void nhap(){
    scanf("%s",s+1);
    n=strlen(s+1);
}
void xuli(){
    int res=0;
    for (int i=0;i<=9;i++)d[i]=0;
    for (int i=1;i<=n;i++){
        int x=s[i]-'0';
        d[x]++;
        for (int j=0;j<x;j++){
            d[x]=(d[x]+d[j])%base;
        }
    }
    for (int i=0;i<=9;i++)res=(res+d[i])%base;
    printf("%d\n",res);
}
int main(){
    //freopen(name".inp","r",stdin);
   // freopen(name".out","w",stdout);
    int test=0;
    scanf("%d",&test);
    for (int i=1;i<=test;i++){
        printf("Case %d: ",i);
        nhap();
        xuli();
    }
}
