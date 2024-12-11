#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const int mod = 1e9 + 7;
const int nmax = 1e6 + 7;

char ch[5] = {'a', 'i', 'u', 'e', 'o'};
string s;
int pref[nmax], suff[nmax];
ll ans = 0;

bool check(char x) {
  for (int i = 0; i < 5; ++i) {
    if (x == ch[i])
      return 1;
  }
  return 0;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  freopen("CAU4.INP", "r", stdin);
  freopen("CAU4.OUT", "w", stdout);
  cin >> s;
  int n = s.size();
  s = " " + s;
  for (int i = 1; i <= n; ++i) {
    pref[i] += pref[i - 1];
    if (check(s[i]))
      ++pref[i];
  }
  for (int i = n; i >= 1; --i) {
    suff[i] += suff[i + 1];
    if (!check(s[i])) {
      ++suff[i];
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (check(s[i]))
      ans += suff[i + 1];
  }
  memset(suff, 0, sizeof(suff));
  memset(pref, 0, sizeof(pref));
  for (int i = 1; i <= n; ++i) {
    pref[i] += pref[i - 1];
    if (!check(s[i]))
      ++pref[i];
  }
  for (int i = n; i >= 1; --i) {
    suff[i] += suff[i + 1];
    if (check(s[i])) {
      ++suff[i];
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!check(s[i]))
      ans += suff[i + 1];
  }
  cout << ans;
  return 0;
}

