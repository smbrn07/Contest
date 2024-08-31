#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

#define FORl(i, s, e) for (int i = s; i < e; i++)
#define FOR(i, s, e) for (int i = s; i <= e; i++)
#define pb push_back
#define allin(v) v.begin(), v.end()

#define mod 19e+7
#define PI 3.1415926535897932384626433832795

bool diag1[21], diag2[21], hang[21], cot[21], a[9][9];
ll cnt = 0;

void dq(int i) {
   if (i > 8)
      ++cnt;
   else {
      for (int j = 1; j <= 8; ++j) {
         int cheo1 = i + j, cheo2 = i - j + 9;
         if (!a[i][j] && !hang[i] && !cot[j] && !diag1[cheo1] &&
             !diag2[cheo2]) {
            a[i][j] = 1, hang[i] = 1, cot[j] = 1, diag1[cheo1] = 1,
            diag2[cheo2] = 1;
            dq(i + 1);
            a[i][j] = 0, hang[i] = 0, cot[j] = 0, diag1[cheo1] = 0,
            diag2[cheo2] = 0;
         }
      }
   }
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(0);
   freopen("queens.inp", "r", stdin);
   freopen("queens.out", "w", stdout);
   for (int i = 1; i <= 8; ++i) {
      for (int j = 1; j <= 8; ++j) {
         char s;
         cin >> s;
         if (s == '*') a[i][j] = 1;
      }
   }
   dq(1);
   cout << cnt << endl;
   return 0;
}
