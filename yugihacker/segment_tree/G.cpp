///giangcbg - TST 2022
#include <bits/stdc++.h>
using namespace std;
const char ginp[]="KINV.INP";
const char gout[]="KINV.OUT";
const int N = 2e5 + 5;
typedef long long ll;
const ll MOD = 1e9+7;
int n,k;
int a[N], t[N], b[N];
ll f[11][N];
void nhap()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    #ifndef ONLINE_JUDGE
//    freopen(ginp,"r",stdin);
//  freopen(gout,"w",stdout);
//    #endif
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    b[i]=a[i];
  }
  sort(b+1, b+n+1);
  for (int i = 1; i <= n; ++i) {
    a[i]=lower_bound(b+1, b+n+1, a[i])-b;
  }
}

void update(int u, int val)
{
    while (u > 0)
    {
        t[u] += val;
        if (t[u] >= MOD) t[u] -= MOD;
        u -= u & (-u);
    }
}

ll get(int u)
{
    ll ans = 0;
    while (u <= n)
    {
        ans += t[u];
        if (ans >= MOD) ans -= MOD;
        u += u & (-u);
    }
    return ans;
}

void sub2()
{
    for (int i = 1; i <= n; i++) f[1][i] = 1;
    for (int i = 2; i <= k; i++)
    {
        for (int j = 1; j <= n; j++) t[j] = 0;
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = get(a[j] + 1);
            update(a[j], f[i-1][j]);
        }
    }

    ll res = 0;
    for (int i = 1; i <= n; i++) {res += f[k][i]; if (res >= MOD) res -= MOD;}
    cout<<res;
}

void solve()
{
//    if (n <= 3000) sub1();
//    else sub2();
    sub2();
}

int main()
{
    nhap();
    solve();
    return 0;
}
