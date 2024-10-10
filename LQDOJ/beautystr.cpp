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
const int nmax = 1e5 + 7;

int cal(string s, int n) {
  int cnt = 0;
  s = " " + s;
  int i = 1;
  while (i <= n) {
    if (s.substr(i, 5) == "mapie" && i + 4 <= n) {
      ++cnt;
      i += 5;
    } else if (s.substr(i, 3) == "map" && i + 2 <= n) {
      ++cnt;
      i += 3;
    } else if (s.substr(i, 3) == "pie" && i + 2 <= n) {
      ++cnt;
      i += 3;
    } else
      i++;
  }
  return cnt;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    int n;
    cin >> n >> s;
    cout << cal(s, n) << endl;
  }
  return 0;
}
