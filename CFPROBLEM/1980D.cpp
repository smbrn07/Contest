#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)
#define file(name)                  \
   freopen(name ".in", "r", stdin); \
   freopen(name ".out", "w", stdout);

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

bool check(vector<int> a) {
	int posgcd=-1, curgcd=-1;
	for (int i = 1; i < sz(a)-1; ++i) {
		curgcd=__gcd(a[i], a[i+1]);
		if (curgcd<posgcd) return 0;
		posgcd=curgcd;
	}
	return 1;
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   int tt; cin >> tt;
   while (tt--) {
   	int n; cin >> n;
   	vector<int> a(n+1, 0);
   	for (int i = 1; i <= n; ++i) cin >> a[i];
   	int pos = -1, posgcd=-1, curgcd=-1;
   	for (int i = 1; i < n; ++i) {
   		curgcd=__gcd(a[i], a[i+1]);
   		if (curgcd<posgcd) {
   			pos=i; break;
   		}
   		posgcd=curgcd;
   	}
   	if (pos==-1) {cout << "YES" << endl;}
   	else {
   		vector<int> b1=a, b2=a, b3=a;
   		if (pos>0) b1.erase(begin(b1)+pos-1);
   		if (pos<n) b3.erase(begin(b3)+pos+1);
   		b2.erase(begin(b2)+pos);
   		cout << ((check(b1)||check(b2)||check(b3)) ? "YES" : "NO") << endl;
   	}
   }
   return 0;
}