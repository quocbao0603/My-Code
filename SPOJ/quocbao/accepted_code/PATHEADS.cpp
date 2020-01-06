#include <fstream>
#include <iostream>
#include <algorithm>
#define ten "patheads"
using namespace std;
const int maxn=int(1e6)+100;
int n,top;
int a[maxn],b[maxn],d[maxn],res[maxn];
void nhap()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
}
bool ss(int a,int b)
{
    return(a<b);
}
void xuli()
{
    top=0;
    for (int i=1;i<=n;i++)b[i]=a[i];
    sort(a+1,a+1+n,ss);
    //for (int i=1;i<=n;i++)cout<<a[i]<<endl;
    d[1]=1;
    top=1;
    for (int i=2;i<=n;i++)
        if (a[i]!=a[i-1])
        {
            top++;
            a[top]=a[i];
            d[top]=1;
        }
        else d[top]=d[top]+1;
    //for (int i=1;i<=top;i++)
    //    cout<<a[i]<<" "<<d[i]<<endl;
    for (int i=1;i<=top;i++)
        for (int j=1;j<=maxn/a[i];j++) res[a[i]*j]=res[a[i]*j]+d[i];
}
void xuat()
{
    for (int i=1;i<=n;i++)
        printf("%d\n",res[b[i]]-1);
}
main()
{
    //freopen(ten".inp","r",stdin);
    //freopen(ten".out","w",stdout);
    nhap();
    xuli();
    xuat();
}

