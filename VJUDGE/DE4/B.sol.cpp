#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define read(x)                                                                \
  for (int &i : x)                                                             \
    cin >> i;
#define write(x)                                                               \
  for (auto &i : x)                                                            \
    cerr << i << ' ';                                                          \
  cerr << endl;
#define dbg(x)                                                                 \
  cerr << "Line(" << __LINE__ << ")->" << #x << " = " << (x) << endl;
#define IOS                                                                    \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);
#define IO(file)                                                               \
  freopen(file ".inp", "r", stdin);                                            \
  freopen(file ".out", "w", stdout);
#define START_TIMER auto start_time = chrono::high_resolution_clock::now();
#define END_TIMER                                                              \
  auto end_time = chrono::high_resolution_clock::now();                        \
  cerr << "Execution Time: "                                                   \
       << chrono::duration_cast<chrono::milliseconds>(end_time - start_time)   \
              .count()                                                         \
       << " ms" << endl;
const int MAX = 1e5 + 1;
int n, m, total = 0;
int col[MAX], water[MAX];
bool check(int x) {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int h = water[i] - col[i], d = max(0ll, min(x, water[i]) - col[i]);
    ans += h - d;
    if (ans >= m)
      return 1;
  }
  return 0;
}

int bin_search() {
  int i = 0, j = 2e9;
  int best = -1;
  while (i <= j) {
    int mid = i + (j - i) / 2;
    if (check(mid)) {
      best = mid;
      i = mid + 1;
    } else {
      j = mid - 1;
    }
  }
  return best;
}

signed main() {
  IOS;
  cin >> n;
  cin >> m;
  for (int i = 0; i < n; i++)
    cin >> col[i];
  int left[n], right[n];
  left[0] = col[0];
  for (int i = 1; i < n; i++) {
    left[i] = max(left[i - 1], col[i]);
  }
  right[n - 1] = col[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    right[i] = max(right[i + 1], col[i]);
  }
  for (int i = 0; i < n; i++) {
    water[i] = max(0LL, min(left[i], right[i]) - col[i]);
    total += water[i];
  }
  cout << bin_search();
}
