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
int k;
vector<string> v;
void in(string s) {
   for (char i : s) {
      if (int(i) + k > 122)
         cout << char(int(i) + k - 26);
      else
         cout << char(int(i) + k);
   }
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   string s;
   int cnt = 0;
   while (cin >> s) {
      v.pb(s);
      ++cnt;
   }
   int d = 0;
   k = stoi(v.back());
   for (string i : v) {
      ++d;
      if (d == cnt)
         break;
      in(i);
      cout << " ";
   }
   return 0;
}
