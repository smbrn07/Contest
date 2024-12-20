#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int cnt[nmax][26];

int check(int i, int j) {
  int res = 0;
  for (int s = 0; s < 26; ++s) {
    if (cnt[j][s] - cnt[i - 1][s] > 0)
      ++res;
  }
  return res;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  s = " " + s;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 26; ++j)
      cnt[i][j] += cnt[i - 1][j];
    ++cnt[i][s[i] - 'a'];
  }
  double ans = 1;
  pair<int, int> p = {1, 1};
  for (int diff = 1; diff <= 26; ++diff) {
    for (int i = 1, j = 1; j <= n; ++j) {
      while (check(i, j) > diff)
        ++i;
      if ((double)diff / (j - i + 1) < ans) {
        ans = min(ans, (double)diff / (j - i + 1));
        p = {i, j};
      }
    }
  }
  cout << p.first << ' ' << p.second;
  return 0;
}
