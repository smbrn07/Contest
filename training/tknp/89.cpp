#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

ll bound[18];

ll binpow(ll a, ll b) {
	if (b==0) return 1;
	ll res = binpow(a, b/2);
	if (b&1) return res*res*a;
	return res*res;
}

void ktao() {
	ll cur = 9;
	for (ll i = 1; i <= 17; ++i) {
		bound[i]=i*binpow(10ll, i-1)*9ll+bound[i-1];
	}
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  ktao();
  ll k; cin >> k;
  ll cs = 1;
  for (int i = 1; i <= 17; ++i) {
  	// cout << bound[i] << endl;
  	if (k<=bound[i]) {
  		cs = i;
  		break;
  	}
  }
  bound[cs]-=bound[cs-1];
  k-=bound[cs-1];
  ll cur = binpow(10ll, cs-1)+(k-1ll)/cs;
  // cout << k << endl;
  ll nth = (k%cs);
  if (nth==0) nth=cs;
  // cout << nth << endl;
  cur/=binpow(10ll, cs-nth);
  cout << cur%10;
  return 0;
}