#include <bits/stdc++.h>

#define int long long
using namespace std;

const int bl = 316;
struct Query{
    int l, r, id;
    bool operator< (Query const& other) {
        if (l / bl != other.l / bl) return l < other.l;
        if ((l / bl) & 1) return r > other.r;
        return r < other.r;
    }
};

const int N = 1e5 + 5;
int n;
int c[N], a[N], res[N], cnt[N], sum[N], mx;
int tin[N], tout[N], now;
vector<int> g[N];
vector<Query> v;

void dfs(int u, int p) {
    tin[u] = ++now;
    a[now] = c[u];
    for (auto v : g[u]) if (v != p) {
        dfs(v, u);
    }
    tout[u] = now;
}

void add(int i) {
    cnt[a[i]]++;
    if (sum[cnt[a[i]]] == 0) mx++;
    sum[cnt[a[i]]] += a[i];
}

void dec(int i) {
    sum[cnt[a[i]]] -= a[i];
    if (sum[cnt[a[i]]] == 0) mx--;
    cnt[a[i]]--;
}

signed main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1, 0);
    for (int i = 1; i <= n; i++) v.push_back({tin[i], tout[i], i});
    sort(v.begin(), v.end());

    int l = 1, r = 0;
    for (auto q : v) {
        while (l > q.l) add(--l);
        while (r < q.r) add(++r);
        while (l < q.l) dec(l++);
        while (r > q.r) dec(r--);
        res[q.id] = sum[mx];
    }

    for (int i = 1; i <= n; i++) cout << res[i] << " ";

}
