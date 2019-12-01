#include <bits/stdc++.h>
#define  io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
typedef long long ll;
const double PI = acos(-1.0);
const int N = 1e6 + 1;
const int oo = 1e9;

using namespace std;
struct o{
    int minValue, maxValue, lazyValue;
};


//Khai bao
o it[N * 4];
int c[N * 4];
int n;
string s;

void down(int i, int l, int r){
    if (it[i].lazyValue == 0)return;
    it[i].maxValue += it[i].lazyValue;
    it[i].minValue += it[i].lazyValue;
    if (l < r){
        it[i << 1].lazyValue += it[i].lazyValue;
        it[i << 1 | 1].lazyValue += it[i].lazyValue;
    }
    it[i].lazyValue = 0;
}

void update(int u, int v, int w, int l, int r, int i){
    down(i, l, r);
    if (r < u || v < l)return;
    if (u <= l && r <= v){
        it[i].lazyValue += w;
        down(i, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    update(u, v, w, l, mid, i << 1);
    update(u, v ,w, mid + 1, r, i << 1 | 1);
    it[i].maxValue = max(it[i << 1].maxValue, it[i << 1 | 1].maxValue);
    it[i].minValue = min(it[i << 1].minValue, it[i << 1 | 1].minValue);
}

void get(int u, int v, int l, int r, int i){
    down(i, l, r);
    if (r < u || v < l) return;
    if (u <= l && r <= v){
        it[0].minValue = min(it[0].minValue, it[i].minValue);
        it[0].maxValue = max(it[0].maxValue, it[i].maxValue);
        return;
    }
    int mid = (l + r) >> 1;
    get(u, v, l, mid, i << 1);
    get(u, v, mid + 1, r, i << 1 | 1);
    //it[i].maxValue = max(it[i << 1].maxValue, it[i << 1 | 1].maxValue);
    //it[i].minValue = min(it[i << 1].minValue, it[i << 1 | 1].minValue);
}
void read(){
    freopen("inp.inp", "r",stdin);
    freopen("out.out", "w", stdout);
}



void solve(){
    int cs = 1;
    int leng = 1;
    int delta = 0;

    for (int i = 1; i <= n; i++){
        char x = s[i - 1];
        if (x == 'L'){
            if (cs > 1){
                cs--;
            }
        }
        else if (x == 'R') {
            cs++;
            leng = max(leng, cs);
        }
        else {
            int value = c[cs];
            delta -= value;
            update(cs, n, -value, 1, n, 1);
            value = 0;
            if (x == '(')value = 1;
            if (x == ')')value = -1;
            c[cs] = value;
            delta += value;
            update(cs, n, value, 1, n, 1);
        }
//        o cur = it[1];
//        debug(cur.minValue);
//        debug(cur.maxValue);
//        continue;
        if (delta != 0){
            cout << -1 << " ";
            continue;
        }
        else {
            it[0].maxValue = -oo;
            it[0].minValue = oo;
            get(1, leng, 1, n, 1);
            o cur = it[0];
            //cerr << cur.minValue <<  " " << cur.maxValue << " " << i << endl;
            if (cur.minValue >= 0){
                cout << cur.maxValue << " ";
            }
            else {
                cout << -1 << " ";
            }
        }
    }
}

int main(){
    io

    read();
    cin >> n;
    getline(cin, s);
    getline(cin, s);
    solve();
}
