#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int nmax = 207;

int n;
ll w[nmax], s, sum = 0;
vector<ll> A, B;

void TryA(int i, ll k) {
  if (k > s)
    return;
  if (i > n / 2)
    A.push_back(k);
  else {
    TryA(i + 1, k);
    TryA(i + 1, sum + w[i]);
  }
}

void TryB(int i, ll k) {
  if (k > s)
    return;
  if (i > n)
    B.push_back(k);
  else {
    TryB(i + 1, k);
    TryB(i + 1, k + w[i]);
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> s;
  for (int i = 1; i <= n; ++i) {
    cin >> w[i];
    sum += w[i];
  }
  if (n <= 40) {
    TryA(1, 0);
    TryB(n / 2 + 1, 0);
  } else if (n > 40 && sum * n >= s) {
    for (int i = 1; i <= n; ++i) {
      for (ll j = s; j >= 0; --j) {
      }
    }
  } else
    cout << -1;

  return 0;
}
