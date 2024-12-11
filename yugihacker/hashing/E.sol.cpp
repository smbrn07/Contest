#include "bits/stdc++.h"

using namespace std;

const int maxn = 5e4, base = 31, MOD = 1e9 + 7;

int n, hashx[maxn + 1], hashn[maxn + 1], p[maxn + 1];
string s;

int getHashX(int l, int r) {
  return (hashx[r] - 1ll * hashx[l - 1] * p[r - l + 1] + 1ll * MOD * MOD) % MOD;
}

int getHashN(int l, int r) {
  return (hashn[n - l + 1] - 1ll * hashn[n - r] * p[r - l + 1] +
          1ll * MOD * MOD) %
         MOD;
}

bool check_distance(int length) {
  for (int i = 1; i <= n - length + 1; i++) {
    if (getHashX(i, i + length - 1) == getHashN(i, i + length - 1))
      return true;
  }
  return false;
}

int bs(int l, int r) {
  int ans = 1;
  while (l <= r) {
    int m = (l + r) / 2;
    bool check = false;
    if (check_distance(2 * m)) {
      ans = max(ans, 2 * m);
      l = m + 1;
      check = true;
    }
    if (check_distance(2 * m + 1)) {
      ans = max(ans, 2 * m + 1);
      l = m + 1;
      check = true;
    }
    if (!check)
      r = m - 1;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  cin.ignore();
  getline(cin, s);
  s = ' ' + s;
  p[0] = 1, hashx[0] = 0, hashn[0] = 0;
  for (int i = 1; i <= maxn; i++)
    p[i] = 1ll * p[i - 1] * base % MOD;
  for (int i = 1; i <= n; i++) {
    hashx[i] = (1ll * hashx[i - 1] * base + s[i] - 'a' + 1) % MOD;
    hashn[i] = (1ll * hashn[i - 1] * base + s[n - i + 1] - 'a' + 1) % MOD;
  }
  cout << bs(1, n / 2);
}
