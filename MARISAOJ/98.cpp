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

int n, m;
int a[nmax], b[nmax];
bool visited[nmax];
int ans = 0;
void proc(int x) {
	vector<int> cnt(nmax, 0);
	bool flagl=1, flagr=1;
	int l=x, r=x;
	visited[x]=1;
	++cnt[a[x]];
	while (flagl||flagr) {
		if (l-1>=1 && cnt[a[l-1]]+1<=b[a[l-1]]) {
			++cnt[a[l-1]];
			visited[l-1]=1;
			--l;
		} else flagl=0;
		if (r+1<=n && cnt[a[r+1]]+1<=b[a[r+1]]) {
			visited[r+1]=1;
			++cnt[a[r+1]];
			++r;
		} else flagr=0;
	}
	ans = max(ans, r-l+1);
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);   
   cin >> n >> m;
   for (int i = 1; i <= n; ++i) {
   	cin >> a[i];
   }
   for (int i = 1; i <= n; ++i) {
   	if (!visited) {
   		proc(i);
   	}
   }
   cout << ans << endl;
   return 0;
}