#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 5e5 + 7;

int n, q;
int t[26][4*nmax];
string s;

void build(int v, int l, int r, int pos, int val) {
	if (l==r) {
		++t[val][v];
		return;
	}
	int mid = (l+r)/2;
	if (pos<=mid) build(2*v, l, mid, pos, val);
	else build(2*v+1, mid+1, r, pos, val);
	t[val][v]=t[val][2*v]+t[val][2*v+1];
}

void update(int v, int l, int r, int pos, int val) {
	int pre = s[pos]-'a';
	if (l==r) {
		++t[val][v];
		--t[pre][v];
		return;
	}
	int mid = (l+r)/2;
	if (pos<=mid) {
		update(2*v, l, mid, pos, val);
		update(2*v, l, mid, pos, pre);
	} else {
		update(2*v+1, mid+1, r, pos, val);
		update(2*v+1, mid+1, r, pos, pre);
	}
	t[val][v]=t[val][2*v]+t[val][2*v+1];
	t[pre][v]=t[pre][2*v]+t[pre][2*v+1];
}

int get(int v, int tl, int tr, int l, int r, int val) {
	if (tl>r || tr<l) return 0;
	if (tl>=l && tr<=r) return t[val][v];
	int mid = (tl+tr)/2;
	return get(2*v, tl, mid, l, r, val)+get(2*v+1, mid+1, tr, l, r, val);
}

signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> s;
  s=" "+s;
  for (int i = 1; i <= n; ++i) {
  	build(1, 1, n, i, s[i]-'a');
  }
  cin >> q;
  while (q--) {
  	int type, l, r, pos;
  	char ch;
  	cin >> type;
  	if (type==1) {
  		cin >> pos >> ch;
  		update(1, 1, n, pos, ch-'a');
  		s[pos]=ch;
  	} else {
  		int ans = 0;
  		cin >> l >> r;
  		for (int i = 0; i < 26; ++i) {
  			ans+=(get(1, 1, n, l, r, i)>0);
  		}
  		cout << ans << endl;
  	}
  }
  return 0;
}