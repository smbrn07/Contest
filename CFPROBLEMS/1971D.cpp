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

string proc(string s) {
	string ans = ""; ans += s[0];
	for (int i = 1; i < sz(s); ++i) {
		if (s[i]!=ans.back()) ans.pb(s[i]);
	}
	return ans;
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);   
   int tt; cin >> tt;
   while (tt--) {
   	string s; cin >> s;
   	string b = proc(s);
   	// cout << b << endl;
   	int cnt = 0, cnt01=0;
   	int cur = 0;
   	while (cur<sz(b)) {
   		if (b[cur]=='1') {
   			++cnt;
   			++cur;
   		}
   		if (b[cur]=='0' && cur+1<sz(b)) {
   			++cnt01;
   			cur+=2;
   		} else if (b[cur]=='0') { ++cnt; ++cur; }
   	}
   	cout << cnt+max(2*(cnt01-1)+1, 0) << endl;
   }
   return 0;
}