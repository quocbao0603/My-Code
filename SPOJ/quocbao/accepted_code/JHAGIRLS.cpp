#include <bits/stdc++.h>
#define name "JHAGIRLS"
using namespace std;
int n,row,col;
int main(){
    //freopen(name".inp","r",stdin);
    //freopen(name".out","w",stdout);
    int test;
    cin>>test;
    while (test--){
        scanf("%d",&n);
        row=1;
        col=1;
        for (int i=1;i<=n;i++){
            printf("%d %d\n",row,col);
            col=col+2;
            row=row+1;
            if (col>n)col=2;
        }
    }
}
