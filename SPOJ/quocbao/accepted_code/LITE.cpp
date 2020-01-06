#include <iostream>
#include <fstream>
#define ten "swtch"
using namespace std;
int m,n,res,loai,x,y;
int a[100000],it[1000009],lazy[1000009];
void nhap()
{
    scanf("%d%d",&n,&m);
    //printf("%d %d",m,n);
}
void capnhatlazy(int i,int l,int r)
{
    if (lazy[i]==1)
        it[i]=(r-l+1)-it[i];
    if(l!=r)
        {
            lazy[i*2]=(lazy[i*2]+lazy[i])%2;
            lazy[i*2+1]=(lazy[i*2+1]+lazy[i])%2;
        }
    //cout<<l<<" "<<r<<" "<<lazy[i]<<endl;
    lazy[i]=0;
}
void update(int u,int v,int l,int r,int i)
{
    int mid;
    capnhatlazy(i,l,r);
    if (r<u || v<l) return;
    if (u<=l&&r<=v)
    {
        it[i]=(r-l+1)-it[i];
        if (l!=r)
        {
            lazy[i*2]=(lazy[i*2]+1)%2;
            lazy[i*2+1]=(lazy[i*2+1]+1)%2;
        }
        return;
    }
    mid=(l+r)/2;
    update(u,v,l,mid,i*2);
    update(u,v,mid+1,r,i*2+1);
    it[i]=(it[i*2]+it[i*2+1]);
}
void search(int u,int v,int l,int r,int i)
    {
        int mid;
        capnhatlazy(i,l,r);
        if (r<u || v<l) return;
        if (u<=l && r<=v)
        {
            res=res+it[i];
            return;
        }
        mid =(l+r)/2;
        search(u,v,l,mid,i*2);
        search(u,v,mid+1,r,i*2+1);
        it[i]=(it[i*2]+it[i*2+1]);
        //cout<<l<<" "<<r<<" "<<it[i]<<endl;
    }
void xuat(int u,int v)
{
    res=0;
    search(u,v,1,n,1);
    printf("%d\n",res);
}
void xuattrau(int u,int v)
{
    //cout<<"Case "<<endl;
    res=0;
    for (int i=u;i<=v;i++)
        if (a[i]==1) res++;
    printf("%d\n",res);
}
void updatetrau(int u,int v)
{
    for (int i=u;i<=v;i++)
        a[i]=(a[i]+1)%2;
}
main()
{
    //freopen(ten".inp","r",stdin);
    //freopen(ten".out","w",stdout);
    nhap();
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&loai,&x,&y);
        //if (loai==1) xuattrau(x,y); else updatetrau(x,y);
        //printf("%d %d %d",loai,x,y);
        if (loai==1)xuat(x,y); else update(x,y,1,n,1);
        //cout<<endl;

    }
}
