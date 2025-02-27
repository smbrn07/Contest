#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 1e6 + 7;

// bool p[nmax];
// vector<int> v;

// void sieve() {
// 	for (int i = 2; i <= nmax; ++i) p[i]=1;
// 	for (int i = 2; i <= nmax; ++i) {
// 		if (p[i]) {
// 			v.push_back(i);
// 			for (ll j = 1ll*i*i; j <= nmax; j+=i) p[j]=0;
// 		}
// 	}
// }

bool check(ll x) {
	for (int i = 2; i*i <= x; ++i) {
		if (x%i==0) return 0;
	}
	return (x>1);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  // sieve();
  // cout << v.size() << endl;
  // int pos = lower_bound(v.begin(), v.end(), n)-v.begin();
  // // cout << pos << endl;
  // for (int i = 2; i*i <= n; ++i) {
  // 	for (int j = i+1; j*j <= n; ++j) {
  // 		if (p[i] && p[j] && p[i*i+j*j] && i*i+j*j<=n) cout << i << ' ' << j << ' ' << i*i+j*j << '\n';
  // 	}
  // }
  bool flag = 0;
  for (int i = 3; 4+i*i <= n; ++i) {
  	if (check(4+i*i) && check(i)) {
  		flag = 1;
  		cout << 2 << ' ' << i << ' ' << 4+i*i << '\n';
  	}
  }
  if (flag==0) cout << -1;
  return 0;
}