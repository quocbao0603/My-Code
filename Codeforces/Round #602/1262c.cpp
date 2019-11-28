#include <bits/stdc++.h>
using namespace std;
int testcase, n, k;
string s, target;
int main(){
   // freopen("c.inp", "r", stdin);
   // freopen("c.out", "w", stdout);
    cin >> testcase;
    while (testcase --){
        cin >> n >> k;
        getline(cin, s);
        getline(cin, s);
        target.clear();
        for (int i = 0; i < k - 1; i++){
            target.push_back('(');
            target.push_back(')');
        }
        for (int i = 0; i < (n - 2 * (k - 1)) / 2; i++){
            target.push_back('(');
        }
        for (int i = 0; i < (n - 2 * (k - 1)) / 2; i++){
            target.push_back(')');
        }
        vector<pair<int, int>> operand;
        for (int i = 0; i < n; i++){
            if (s[i] != target[i]){
                for (int j = i + 1; j < n; j++){
                    if (s[j] == target[i]){
                        reverse(s.begin() + i, s.begin() + j + 1);
                        operand.push_back({i + 1, j + 1});
                        break;
                    }
                }
            }
        }
        //cout << s << endl;
        cout << operand.size() << endl;
        for (int i = 0; i < operand.size(); i++){
            cout << operand[i].first << " " << operand[i].second << endl;
        }
    }
}
