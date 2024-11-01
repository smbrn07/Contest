#include <bits/stdc++.h>
#define maxn 1000005
#define MOD 1e9 + 7
using namespace std;

int n, k;
int d[maxn];
long long f[maxn];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    int x;
    cin >> x;
    d[x] = 1;
  }

  f[1] = 1;

  for (int i = 2; i <= n; i++)
    if (!d[i])
      f[i] = (f[i - 1] + f[i - 2]) % MOD;
  cout << f[n];
}
