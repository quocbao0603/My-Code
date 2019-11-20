#include <bits/stdc++.h>

#define name "a"

using namespace std;

int main(){
    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);
    int test;
    cin >> test;
    while (test--){
            int a, b;
        cin >> a >> b;
        int c = abs(a - b);
        int res = 0;
        res +=  c /5;
        c %= 5;
        res += c/ 2;
        c %= 2;
        res += c / 1;
        c -= 1;
        cout << res << endl;
    }
}
