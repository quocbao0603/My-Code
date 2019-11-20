#include <bits/stdc++.h>
using namespace std;

const int maxn = 150;
char a[maxn][maxn], ans[maxn][maxn];
vector <char> res;
vector <int> dchicken;
int testcase, m, n, k;
int main(){
    //freopen("d.inp", "r", stdin);
    for (char c = 'a'; c <= 'z'; c++){res.push_back(c);}
    for (char c = 'A'; c <= 'Z'; c++){res.push_back(c);}
    for (char c = '0'; c <= '9'; c++){res.push_back(c);}
    cin >> testcase;

    while(testcase--){
        cin >> m >> n >> k;
        for (int i = 0; i <= m; i++){
            gets(&a[i][1]);
        }
        int rice = 0;
        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j ++){
                if (a[i][j] == 'R')rice++;
            }
        }
        int type1 = rice / k;
        int type2 = rice / k + 1;
        int sltype1 = rice % k;
        dchicken.clear();
        for (int i = 0 ; i < k; i++){
            if (i < sltype1){
                dchicken.push_back(type2);
            }
            else dchicken.push_back(type1);
        }
        int idchicken = 0;
        for (int i = 1; i <= m; i++){
            if (i % 2 == 0){
                for (int j = 1; j <= n; j++){
                    if (a[i][j] == 'R'){
                        if (dchicken[idchicken] == 0){
                            idchicken++;
                        }
                        dchicken[idchicken]--;
                    }
                    ans[i][j] = res[idchicken];
                }
            }
            else {
                for (int j = n; j >= 1; j--){
                    if (a[i][j] == 'R'){
                        if (dchicken[idchicken] == 0){
                            idchicken++;
                        }
                        dchicken[idchicken]--;
                    }
                    ans[i][j] = res[idchicken];
                }
            }
        }
        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                cout << ans[i][j];
            }
            cout << endl;
        }
    }
}
