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

bool islow(char i) {
   if (i >= 'a' && i <= 'z')
      return 1;
   return 0;
}

bool isup(char i) {
   if (i >= 'A' && i <= 'Z')
      return 1;
   return 0;
}

bool isnum(char i) {
   if (i >= '0' && i <= '9')
      return 1;
   return 0;
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   int len = 0;
   bool up = 0, down = 0, num = 0;
   string s;
   cin >> s;
   for (char i : s) {
      ++len;
      if (isup(i))
         up = 1;
      if (islow(i))
         down = 1;
      if (isnum(i))
         num = 1;
   }
   cout << ((up && down && num && len > 7) ? "STRONG" : "WEAK") << endl;
   // cout << len << endl;
   return 0;
}
