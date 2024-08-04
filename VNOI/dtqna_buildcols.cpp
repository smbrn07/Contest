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
const int nmax = 1e3+7;

int n, a[nmax];

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);   
   cin >> n;
   priority_queue<int, vector<int>(), greater<int> pq;
   for (int i = 1; i <= n; ++i) {
   	cin >> a[i];
   	pq.push(a[i]);
   }
   int cur=pq.top(); pq.pop();
   int ans = 0;
   while (!q.empty()) {
   	bool hi=0, lo=0;
   	for (int i = 1; i <= n; ++i) {
   		
   	}
   }
   return 0;
}