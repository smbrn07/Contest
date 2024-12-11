#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 2e5 + 7;

int p[22], f[nmax];

signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
freopen("nhiphan.inp", "r", stdin);
freopen("nhiphan.out", "w", stdout);
  int n, k;
  string s;
  cin >> n >> k >> s;
  p[1] = 1;
  for (int i = 2; i <= 21; ++i) {
    p[i] = p[i - 1] * 2;
    if (k - 1 == p[i]) {
      k = i;
      break;
    }
  }
  if (k == 1) {
    cout << s;
    return 0;
  }
  reverse(s.begin(), s.end());
  for (int i = 0; i < n; ++i)
    f[i + 1] = s[i] - '0';
  int mem = 0;
  for (int i = k; i < n + k; ++i) {
    if (s[i - k] == '1' && f[i] == 1) {
      if (mem) {
        f[i] = 1, mem = 1;
      } else {
        f[i] = 0, mem = 1;
      }
    } else if (s[i - k] == '0' && f[i] == 0) {
      if (mem) {
        f[i] = 1, mem = 0;
      } else {
        f[i] = 0, mem = 0;
      }
    } else {
      if (mem) {
        f[i] = 0, mem = 1;
      } else {
        f[i] = 1, mem = 0;
      }
    }
  }
  if (mem)
    cout << ++f[n + k];
  for (int i = n + k - 1; i >= 1; --i)
    cout << f[i];
  return 0;
}
