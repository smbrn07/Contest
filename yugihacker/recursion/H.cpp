#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

bool sp[3];
vector<pair<char, char>> v;

void dq(int num, char x, char y, char z) {
   if (num > 0) {
      dq(num - 1, x, z, y);
      v.pb({x, z});
      dq(num - 1, y, x, z);
   }
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   int n;
   cin >> n;
   dq(n, '1', '2', '3');
   cout << sz(v) << endl;
   for (pair<char, char> i : v) {
      cout << i.ff << " " << i.ss << endl;
   }
   return 0;
}
