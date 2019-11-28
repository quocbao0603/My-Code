#include <bits/stdc++.h>
#define  io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define db(X) ({ if(1) cerr << "db: " << (#X) << " = " << (X) << endl; })
typedef long long ll;
#define N 333333
using namespace std;
void read(){
    freopen("inp.inp", "r",stdin);
    freopen("out.out", "w", stdout);
}


int n;
int a[N];

int main(){
    io
    read();
    cin >> n;
    int flag = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] == -1){
            flag = 1;
            a[i] = 0;
        }
        else {
            if (flag == 0){
                a[i] = 0;
            }
        }
    }
    reverse(a + 1, a + 1 + n);
    ll res = a[1];
    int i = 2;
    int round_ith = n;
    priority_queue <int, vector<int>, greater<int> >q;
    while (i <= n){
        round_ith /= 2;
        for (int l = i; l < i + round_ith; l++){
            q.push(a[l]);
        }
        res += q.top();
        q.pop();
        i += round_ith;
    }
    cout << res;
}
