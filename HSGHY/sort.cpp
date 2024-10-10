#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  int x = 0, t = 0, h = 0;
  for (int i = 1; i <= n; ++i) {
    char s;
    cin >> s;
    if (s == 'X')
      ++x;
    else if (s == 'T')
      ++t;
    else
      ++h;
  }
  while (x--)
    cout << "X ";
  while (t--)
    cout << "T ";
  while (h--)
    cout << "H ";
  return 0;
}
