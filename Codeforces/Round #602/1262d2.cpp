#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 1000;

struct o{
    int value, index;
};

struct oq{
    int value, index, tt;
};
o a[maxn];
oq q[maxn];
int b[maxn], res[maxn];
int n, m;
o it[maxn * 10];
o ans;
bool cmp(o a, o b){
    return a.value < b.value || a.value == b.value && a.index > b.index;
}


bool cmp_query(oq a, oq b){
    return a.value > b.value;
}

void updateit(int u, int w, int l, int r, int i){
    if (r < u || u < l) return;
    if (u == l && r == u){
        it[i].value = w;
        if (it[i].value > 0){
            it[i].index = u;
        }
        else it[i].index = 0;
        return;
    }
    int mid = l + (r - l) / 2;
    updateit(u, w, l, mid, i * 2);
    updateit(u, w, mid + 1, r , i * 2 + 1);
    it[i].value = it[i * 2].value + it[i * 2 + 1].value;
    if (it[i * 2 + 1].value == 0){
        it[i].index = it[i * 2].index;
    }
    else {
        it[i].index = it[i * 2 + 1].index;
    }
}

void findit(int u, int v, int l, int r, int i){
    if (r < u) return;
    if (v < l) return;
    if (u <= l && r <= v){
        ans.value += it[i].value;
        if (it[i].value > 0){
            ans.index = it[i].index;
        }
        return;
    }
    int mid = l + (r - l) / 2;
    findit(u, v, l, mid, i * 2);
    findit(u, v, mid + 1, r , i * 2 + 1);
}

int main(){
    //freopen("d2.inp", "r",stdin);
    //freopen("d2.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].value;
        b[i] = a[i].value;
        a[i].index = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    cin >> m;

    for (int i = 1; i <= m; i++){
        cin >> q[i].value >> q[i].index;
        q[i].tt = i;
    }

    sort(q + 1, q + 1 + m, cmp_query);

    for (int i = 1; i <= n; i++){
        updateit(i, 1, 1, n, 1);
    }

    int sl = n;
    int isl = 0;

    for (int i = 1; i <= m; i++){
        while (sl > q[i].value){
            sl--;
            isl++;
            updateit(a[isl].index, 0, 1, n, 1);
        }
        int l = 1;
        int r = n;
        int rid = 1;
        //cout << i << endl;
        while (l <= r){
            int mid = l + (r - l) / 2;
            ans = {0, 0};
            findit(1, mid, 1, n, 1);
            if (ans.value <= q[i].index){
                rid = mid;
                l = mid + 1;
            }
            else r = mid - 1;
            //cout << mid << " "<< rid << " " << ans.value << " " << q[i].index << endl;
        }

        l = 1;
        r = n;
        int lid = 1;
        while (l <= r){
            int mid = l + (r - l) / 2;
            ans = {0, 0};
            findit(1, mid, 1, n, 1);
            if (ans.value >= q[i].index){
                lid = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        ans = {0, 0};
        findit(lid, rid, 1, n, 1);
        res[q[i].tt] = b[ans.index];
        //cout << lid << " " << rid << " " << q[i].tt << endl;
        //cout << "res: " << ans.index << endl;

    }
    for (int i = 1; i <= m; i++){
        cout << res[i] << "\n";
    }
}
