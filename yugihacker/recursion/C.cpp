#include "bits/stdc++.h"
#include <cmath>

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

int n;
vector<int> v;
bool visited[11];

void sinhtamphan(int pos) {
   if (pos > n) {
      for (int i : v)
         cout << i;
      cout << endl;
   } else {
      for (int i = 1; i <= n; ++i) {
         if (!visited[i]) {
            visited[i] = 1;
            v.pb(i);
            sinhtamphan(pos + 1);
            v.pop_back();
            visited[i] = 0;
         }
      }
   }
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   cin >> n;
   sinhtamphan(1);
   return 0;
}
