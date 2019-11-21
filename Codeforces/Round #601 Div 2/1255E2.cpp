#include <iostream>
#define MaxA 1000000
#define maxn 1111111
#define io    freopen("e.inp", "r",stdin); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const long long oo = 1e18;
using namespace std;

long long res = oo;
int n;
int a[maxn];
long long sum, s[maxn];

struct toado{
    long long value;
    int index;
} b[maxn];

long long cal(int n){
    long long value = 0;
    for (int i = 1; i <= n; i++){
        s[i] = s[i - 1] + b[i].value;
        value += b[i].value * b[i].index;
    }
    long long ans = value;
    //cout << "Truoc khi dat " << value << endl;
    for (int i = 1; i <= n; i++){
        value += s[i - 1] * (b[i].index - b[i - 1].index);
        value -= (s[n] - s[i - 1]) * (b[i].index - b[i - 1].index);
        ans = min(ans, value);
        //cout << value << endl;
    }
    return ans;
}

long long solve(long long mid){
    long long k = mid, ans = 0;
    int N = 0;
    b[0] ={0, 0};
    for (int i = 1; i <= n; i++){
        long long x = a[i] % mid;
        //cout << "k " << k << " " << x << endl;
        if (x >= k){
            N++;
            b[N] = {k, i};
            ans += cal(N);
            N = 0;
            x -= k;
            k = mid;
        }
        if (x == 0)continue;
        if (x < k){
            N++;
            b[N] = {x, i};
            k -= x;
        }
    }
    if (k == 0 || k == mid)return ans;
    return oo;
}

int main(){
    io
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if (sum == 1){
        cout << -1;
        return 0;
    }
    for (int i = 2; i <= MaxA; i++){
        if (sum % i == 0){
            while(sum % i == 0){
                sum /= i;
            }
            //cout << res << " " <<  solve(i) << " " << i<< endl;
            res = min(res, solve(i));
        }
    }
    if (sum > 1){
        res = min(res, solve(sum));
    }
    if (res == oo){
        cout << -1;
    }
    else cout << res;
}
