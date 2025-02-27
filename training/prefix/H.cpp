#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 2e5 + 7;

string s;
int n, q, a[nmax];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> s >> q;
  n = int(s.size());
  while (q--) {
  	int k; cin >> k;
  	++a[k]; --a[n-k+2];
  }
  string revs = s;
  reverse(revs.begin(), revs.end());
  for (int i = 1; i <= n; ++i) a[i]+=a[i-1];
	for (int i = 1; i <= n; ++i) {
		if (a[i]%2) cout << revs[i-1];
		else cout << s[i-1];
	}
  return 0;
}