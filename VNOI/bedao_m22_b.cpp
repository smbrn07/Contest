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
const int nmax = 2e5+7;

int a[nmax];

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   int n; cin >> n;
   for (int i = 1; i <= n; ++i) {
   	cin >> a[i];
   	a[i]%=23;
   }
   map<int,int> mp;
   ll cnt = 0;
   for (int i = 1; i <= n; ++i) {
   	cnt+=mp[a[i]];
   	if (i-5>0) ++mp[a[i-5]];
   }
   cout << cnt << endl;
   return 0;
}