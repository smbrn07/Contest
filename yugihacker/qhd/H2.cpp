#include <bits/stdc++.h>

using namespace std;

typedef vector<pair<long long, long long>> vii;

#define pb push_back
#define all(x) x.begin(), x.end()

const int V = 1e6 + 7;
const int N = 1e5 + 7;
const int S = 2e3 + 7;
const int inf = 1e9;

long long s, n, v[N], w[N], k[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

#ifndef ONLINE_JUDGE
// freopen("test.inp", "r", stdin);
// freopen("test.out", "w", stdout);
#endif

  cin >> s >> n;
  for (int i = 1; i <= n; i++)
    cin >> v[i] >> w[i] >> k[i];

  int mx = *max_element(k, k + n);
  // Subtask 1
  if (n == 1) {
    cout << v[1] * min(s / w[1], k[1]) << endl;
  }
  // Subtask 2 & 3: Normal knapsack
  else if (1 <= n && n <= 100 && mx <= 10) {
    long long dp[2001];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i++)
      for (int j = s; j >= w[i]; j--)
        for (int t = 0; t <= k[i]; t++)
          if (j >= w[i] * t) {
            dp[j] = max(dp[j], dp[j - w[i] * t] + v[i] * t);
          }
    cout << dp[s] << endl;
  }
  // Subtask 4 & 5: knapsack with observation
  else if (1 <= n && n <= 1e5 && mx <= 1e9) {

    /*
      Observation: The numbers of taken product must less than S since 1 <= Wi
      <= S -> maximum taken product: S / W[i]
      -> consider the top valued S/W[i] items for each W[i]
    */
    vii obj[S];
    long long dp[2001];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i++) {
      obj[w[i]].pb({v[i], k[i]});
    }

    for (int i = 0; i <= s; i++) {
      if (obj[i].size() == 0)
        continue;
      sort(all(obj[i]), greater<pair<int, int>>());

      int id = 0;
      for (int j = 0; j * i < s; j++) {
        if (id >= obj[i].size())
          break;
        for (int k = s; k >= i; k--) {
          dp[k] = max(dp[k], dp[k - i] + obj[i][id].first);
        }
        --obj[i][id].second;
        if (obj[i][id].second == 0)
          ++id;
      }
    }
    cout << dp[s] << endl;
  }
}
