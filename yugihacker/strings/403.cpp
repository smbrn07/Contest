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

void string1(string s1) {
   pair<char, int> p = {s1[0], 0};
   for (char i : s1) {
      if (i != p.ff) {
         cout << p.ss << p.ff;
         p = {i, 1};
      } else {
         ++p.ss;
      }
   }
   cout << endl;
}

void string2(string s2) {
   pair<char, int> p = {' ', 0};
   for (char i : s2) {
      if (i <= '9') {
         p.ss = p.ss * 10 + i - '0';
      } else {
         for (int j = 1; j <= p.ss; ++j)
            cout << i;
         p.ss = 0;
      }
   }
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   string s1, s2;
   cin >> s1 >> s2;
   string1(s1 + " ");
   string2(s2);
   return 0;
}
