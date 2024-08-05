#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)
#define file(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);

const int mod = 1e9+7;
const int nmax = 1e5+7;

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);   
   int tt; cin >> tt;
   while (tt--) {
   	int n; string s; cin >> n >> s;
   	vector<int> d(4, 0);
   	int cnt = 0;
   	for (char i : s) {
   		if (i=='?') ++cnt;
   		else ++d[i-'A'];
   	}
   	int minv = min({d[0], d[1], d[2], d[3]});
   	int ans = 0;
   	for (int i = 0; i < 4; ++i) {
   		ans += min(d[i], n);
   	}
   	cout << ans << endl;
   }
   return 0;
}