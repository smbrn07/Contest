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

string ans1 = "", ans2 = "";

void decode(string s) {
   char cur = ' ';
   int cnt = 0;
   for (char i : s) {
      if (i != cur) {
         ans1 += to_string(cnt) + cur;
         cnt = 0;
         cur = i;
      } else {
         ++cnt;
      }
   }
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   string s;
   cin >> s;
   s += "*";
   int cur = 0;

   return 0;
}
