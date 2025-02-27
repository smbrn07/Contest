#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 2e5 + 7;

pair<int, int> t[4*nmax];
//  <len, cnt>

pair<int,int> proc(pair<int,int> a, pair<int,int> b) {
	if (a.first == b.first) return {a.first, a.second+b.second};
	return max(a, b);
}

void update(int v, int l, int r, int pos, int val) {
	
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  return 0;
}