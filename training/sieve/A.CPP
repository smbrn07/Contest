#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

ll uoc(ll x) {
	int cnt = 0;
	for (ll i = 1; i*i<=x; ++i) {
		if (x%i==0) {
			cnt+=2;
			if (i*i==x) --cnt;
		}
	}
	return cnt;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll x; cin >> x;
  cout << uoc(x);
  return 0;
}