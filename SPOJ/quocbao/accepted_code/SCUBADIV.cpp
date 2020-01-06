#include <bits/stdc++.h>

using namespace std;

const int MAX_OXI = 22;
const int MAX_NITRO  = 80;
const int INF = 100000000;

vector<vector<vector<int>>> dp;
vector<int> oxiCylinder;
vector<int> nitroCylinder;
vector<int> weight;

int solve(int i, int oxiNeed, int nitroNeed) {
    if (dp[i][oxiNeed][nitroNeed] != -1)
        return dp[i][oxiNeed][nitroNeed];
    else if (oxiNeed == 0 && nitroNeed == 0) {
        dp[i][oxiNeed][nitroNeed] = 0;
        return dp[i][oxiNeed][nitroNeed];
    } else if (i == 0) {
        dp[i][oxiNeed][nitroNeed] = INF;
    } else {
        int donTakeThisCylinder = solve(i-1, oxiNeed, nitroNeed);
        int newOxiNeed = max(oxiNeed - oxiCylinder[i], 0);
        int newNitroNeed = max(nitroNeed- nitroCylinder[i], 0);
        int takeThisCylinder = solve(i-1, newOxiNeed, newNitroNeed) + weight[i];
        dp[i][oxiNeed][nitroNeed] = min(donTakeThisCylinder, takeThisCylinder);
    }
    return dp[i][oxiNeed][nitroNeed];
}



int main(int argc, char const* argv[])
{
    int T;
    cin >> T;
    while (T--) {
        int oxi, nitro;
        cin >> oxi >> nitro;

        int n;
        cin >> n;
        oxiCylinder = vector<int>(n+1);
        nitroCylinder = vector<int>(n+1);
        weight = vector<int>(n+1);
        dp = vector<vector<vector<int> > >(n+1, vector<vector<int>>(MAX_OXI, vector<int>(MAX_NITRO, -1)));
        for (int  i = 1; i <= n; i++) {
            cin >> oxiCylinder[i] >> nitroCylinder[i] >> weight[i];
        }
        solve(n, oxi, nitro);
        cout << dp[n][oxi][nitro] << endl;
    }
    return 0;
}
