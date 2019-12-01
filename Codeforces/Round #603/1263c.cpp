#include <bits/stdc++.h>
#define  io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define db(X) ({ if(1) cerr << "db: " << (#X) << " = " << (X) << endl; })
typedef long long ll;
#define N 333333
const int oo = 1e9;
using namespace std;
void read(){
    freopen("c.inp", "r",stdin);
    freopen("c.out", "w", stdout);
}
vector <int>res;
int main(){
    read();
    int test;
    cin >> test;
    while (test--){
        int n;
        cin >> n;
        res.clear();
        res.push_back(0);
        for (int i = 1; i * i <= n; i++){
            res.push_back(i);
            if (i != (n / i)){
                res.push_back(n / i);
            }
        }
        sort(res.begin(),res.end());
        cout << res.size() << endl;
        for (int i = 0 ; i < res.size(); i++){
            cout << res[i] << " " ;
        }
        cout << endl;
    }
}
