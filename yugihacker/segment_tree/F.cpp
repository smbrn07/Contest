#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int n, x, cnt[nmax], t[4*nmax];

void update(int v, int l, int r, int pos, int val) {
  if (l==r) {
    t[v]=val;
    return;
  }
  int mid = (l+r)/2;
  if (pos<=mid) update(2*v, l, mid, pos, val);
  else update(2*v+1, mid+1, r, pos, val);
  t[v]=t[2*v]+t[2*v+1];
}

int get(int v, int tl, int tr, int l, int r) {
  if (tl>r || tr<l) return 0;
  if (tl>=l && tr<=r) return t[v];
  int mid = (tl+tr)/2;
  return get(2*v, tl, mid, l, r)+get(2*v+1, mid+1, tr, l, r);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    ans+=get(1, 1, n, x+1, n);
    update(1, 1, n, x, ++cnt[x]);
  }
  cout << ans;
  return 0;
}