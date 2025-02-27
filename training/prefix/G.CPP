#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int a[nmax];
int inc[nmax], lasinc[nmax], decr[nmax];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
  	inc[i]=inc[i-1]+(a[i]<a[i-1]);
  	lasinc[inc[i]]=i;
  }
  for (int i = n; i >= 1; --i) decr[i]=decr[i+1]+(a[i]<a[i+1]);
  while (q--) {
  	int l, r; cin >> l >> r;
  	// luon tang
  	if (inc[r]==inc[l]) cout << "Yes" << endl;
  	// luon giam
  	else if (decr[l]==decr[r]) cout << "Yes" << endl;
  	// tang -> giam
  	else if (decr[lasinc[inc[l]]]==decr[r]) cout << "Yes" << endl;
  	else cout << "No" << endl;
  }
  return 0;
}