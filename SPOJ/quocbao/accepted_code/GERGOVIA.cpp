#include <bits/stdc++.h>
using namespace std;
int n;
int a[100001];
int main(){
    while (cin >> n){
        if (n == 0)return 0;
        long long s = 0 , res = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            s += a[i];
            res += abs(s);
        }
        cout << res << "\n";
    }
    return(0);
}
