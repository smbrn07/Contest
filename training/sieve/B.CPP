#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

vector<ll> v;

void ptich(ll x) {
	for (ll i = 2; i*i<=x; ++i) {
		if (x%i==0) {
			v.push_back(i);
			while (x%i==0) x/=i;
		}
	}
	if (x!=1) v.push_back(x);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll n; cin >> n;
  ptich(n);
  vector<pair<ll,int>> p;
  for (int i = 0; i < v.size(); ++i) {
  	int cnt = 0;
  	while (n%v[i]==0) {
  		++cnt;
  		n/=v[i];
  	}
  	p.push_back({v[i], cnt});
  }
  if (!p.size()) cout << 1 << endl << 1 << ' ' << 1;
  else cout << p.size() << endl;
  for (int i = 0; i < p.size(); ++i) {
  	cout << p[i].first << ' ' << p[i].second << endl;
  }
  return 0;
}