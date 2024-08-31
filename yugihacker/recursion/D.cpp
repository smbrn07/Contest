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

int n, s;
bool c[21];
int a[21];
int sum = 0, cnt = 0;

void dq(int i) {
   if (i > n) {
      bool flag = 0;
      for (int j = 1; j <= n; ++j) {
         if (c[j] == 1) {
            sum += a[j];
            flag = 1;
         }
      }
      if (sum == s) ++cnt;
      sum = 0;
   } else {
      for (int j = 0; j <= 1; ++j) {
         c[i] = j;
         dq(i + 1);
         c[i] = 0;
      }
   }
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   cin >> n >> s;
   for (int i = 1; i <= n; ++i) cin >> a[i];
   dq(1);
   cout << cnt << endl;
   return 0;
}
