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

int n;
char conv[2] = {'(', ')'};
int v[21];
vector<string> ans;

bool check(int v[]) {
   int flag = 0;
   for (int i = 1; i <= n; ++i) {
      if (flag < 0)
         return 0;
      if (!v[i]) {
         ++flag;
      } else
         --flag;
   }
   return flag == 0;
}

void dq(int pos) {
   if (pos > n) {
      if (check(v)) {
         string s = "";
         for (int j = 1; j <= n; ++j) {
            s.pb(conv[v[j]]);
         }
         ans.pb(s);
      }
   } else {
      for (int j = 0; j <= 1; ++j) {
         v[pos] = j;
         dq(pos + 1);
         v[pos] = 0;
      }
   }
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   cin >> n;
   n *= 2;
   dq(1);
   cout << sz(ans) << endl;
   for (string i : ans) {
      cout << i << endl;
   }
   return 0;
}
