#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
#define pb push_back
#define endl '\n'

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int k;
  cin >> k;
  while (k--) {
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    vector<int> v;
    for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      ++mp[x];
      if (mp[x] > 1) {
        mp[x] -= 2;
        v.push_back(x);
      }
    }
    sort(v.begin(), v.end());
    if (v.size() < 2) {
      cout << -1 << endl;
    } else {
      ll ans = 1ll * v.back();
      v.pop_back();
      cout << ans * 1ll * v.back() << endl;
    }
  }
  return 0;
}
