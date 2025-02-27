#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, d, m;
  cin >> n >> d >> m;
  int cnt =0;
  for (int i = 1; i <= n; ++i) {
  	int x; cin >> x;
  	if (x%d==0||x%m==0) ++cnt;
  }
  cout << cnt;
  return 0;
}