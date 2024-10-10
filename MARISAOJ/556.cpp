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
const int nmax = 1e3 + 7;

pair<int, int> p[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 1; i <= n; ++i)
    cin >> p[i].ff;
  for (int i = 1; i <= n; ++i)
    cin >> p[i].ss, sum += p[i].ss;
  sort(p + 1, p + n + 1);
  int ans = 0;
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 1; i <= n; ++i) {
    if (p[i].ff > sz(pq))
      pq.push(p[i].ss);
    else if (pq.top() < p[i].ss) {
      pq.pop();
      pq.push(p[i].ss);
    }
  }
  while (!pq.empty())
    ans += pq.top(), pq.pop();
  cout << sum - ans << endl;
  return 0;
}
