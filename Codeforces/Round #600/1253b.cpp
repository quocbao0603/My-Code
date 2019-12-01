#include <bits/stdc++.h>
#define  io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define db(X) ({ if(1) cerr << "db: " << (#X) << " = " << (X) << endl; })
typedef long long ll;
const int N = 1e6 + 100;
const int oo = 1e9;
using namespace std;
void read(){
    freopen("inp.inp", "r",stdin);
    freopen("out.out", "w", stdout);
}

int a[N], check[N];
vector <int>res;
void sinhtest(){
    freopen("inp.inp", "w",stdout);
    cout << 100000 << endl;
    for (int i = 1; i <= 100000/2; i++){
        cout << 1 << " " << -1  << " ";
    }
}
int main(){
    //sinhtest();
//    return 0;
    io
    read();
    res.clear();
    int n;
    cin >> n;
    if (n % 2!= 0){
        cout << -1;
        return 0;
    }
    int day = 1, sl = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if (x > 0){
            if (check[x] == day){
                cout << -1;
                return 0;
            }
            sl++;
            a[x]++;
            check[x] = day;
        }
        else {
            x = -x;
            a[x]--;
            if (a[x] < 0){
                cout << -1;
                return 0;
            }
            else {
                sl--;
                if (sl == 0){
                    day++;
                    res.push_back(i + 1);
                }
            }
        }
//        for (int i = 1; i <= 6; i++){
//            cout << a[i] << " ";
//        }
//        cout << endl;
   // cout << sl << " "<< day << endl;
    }
    if (sl != 0){
        cout << -1;
        return 0;
    }
    cout << day - 1 << endl;
    for (int i = 0; i < res.size(); i++){
        if (i == 0){
            cout << res[i] - 1 << " ";
        }
        else {
            cout << res[i] - res[i - 1] << " ";
        }
    }
}
