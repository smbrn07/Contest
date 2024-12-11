#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const ll mod = 1e9 + 7;
const int nmax = 1e6 + 7;
const int base = 31;

string s;
ll pref[nmax], suff[nmax], p[nmax];

ll getHash1(int l, int r) {
  return (pref[r] - pref[l - 1] * p[r - l + 1] + mod * mod) % mod;
}
ll getHash2(int l, int r) {
  return (suff[l] - suff[r + 1] * p[r - l + 1] + mod * mod) % mod;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> s;
  int q;
  cin >> q;
  int n = sz(s);
  string t = s;
  s = ' ' + s;
  p[0] = 1ll;
  for (int i = 1; i <= n; ++i) {
    p[i] = (p[i - 1] * base) % mod;
    pref[i] = (pref[i - 1] * base + s[i] - 'a' + 1) % mod;
  }
  for (int i = n; i >= 1; --i) {
    suff[i] = (suff[i + 1] * base + s[i] - 'a' + 1) % mod;
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (getHash1(l, r) == getHash2(l, r))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}
