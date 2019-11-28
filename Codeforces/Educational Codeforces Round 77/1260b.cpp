#include <bits/stdc++.h>

using namespace std;

int n;

bool thu(int a, int  b){
    if (a > b)return thu(b, a);
    if (((a + b) % 3 == 0) && (b >= a) && (b <= a*2))
        return true;
    return false;
}

int main(){
    freopen("b.inp", "r", stdin);
    freopen("b.out", "w", stdout);
    int testcase;
    cin >> testcase;
    while (testcase--){
        int a, b;
        cin >> a >> b;
        if(thu(a, b)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
