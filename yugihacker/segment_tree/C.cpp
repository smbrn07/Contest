#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 2e5 + 7;

int n, q;
ll a[nmax], t[4*nmax];

void mkt(int v, int l, int r) {
	if (l==r) t[v]=a[l];
	else {
		int mid = (l+r)/2;
		mkt(2*v, l, mid), mkt(2*v+1, mid+1, r);
	}
}

void update(int v, int tl, int tr, int l, int r, int val) {
	if (tl==tr && tl>=l && tr<=r) t[v]+=val;
	else {
		
	}
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  mkt(1, 1, n);
  return 0;
}