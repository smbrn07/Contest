#include <bits/stdc++.h>
#define int long long
using namespace std;

int t, n, m;

bool check(int x, vector<int> nan, vector<int> ve) {
  int spnan = 0, spve = 0;
  for (int time : nan)
    spnan += x / time;
  for (int time : ve)
    spve += (t - x) / time;
  return spnan <= spve;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;

  cin >> n;
  vector<int> nan(n);
  for (int &x : nan)
    cin >> x;

  cin >> m;
  vector<int> ve(m);
  for (int &x : ve)
    cin >> x;

  int l = 0, r = t;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (check(mid, nan, ve))
      l = mid;
    else
      r = mid - 1;
  }
  int sp = 0;
  for (int x : nan)
    sp += l / x;
  cout << sp;
}
