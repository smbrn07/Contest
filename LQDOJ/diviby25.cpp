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

int check00(string s, int n) {
  int pos[2] = {-1, -1};
  int cnt = 0;
  s = " " + s;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '0') {
      pos[cnt] = i;
      ++cnt;
    }
  }
  if (pos[1] == n || pos[1] == -1)
    return 1e9;
  return pos[1] - pos[0] - 1;
}

int check25(string s, int n) {
  int pos2 = -1, pos5 = -1;
  int cnt = 0;
  s = " " + s;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '2')
      pos2 = i;
    if (s[i] == '5')
      pos5 = i;
  }
  if (pos2 == -1 || pos5 == -1 || pos2 < pos5)
    return 1e9;
  return pos2 - pos5 - 1;
}

int check50(string s, int n) {
  int pos5 = -1, pos0 = -1;
  int cnt = 0;
  s = " " + s;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '0')
      pos0 = i;
    if (s[i] == '5')
      pos5 = i;
  }
  if (pos5 == -1 || pos0 == -1 || pos5 < pos0)
    return 1e9;
  return pos5 - pos0 - 1;
}

int check75(string s, int n) {
  int pos7 = -1, pos5 = -1;
  int cnt = 0;
  s = " " + s;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '7')
      pos7 = i;
    if (s[i] == '5')
      pos5 = i;
  }
  if (pos7 == n || pos5 == -1 || pos7 == -1 || pos7 < pos5)
    return 1e9;
  return pos7 - pos5 - 1;
}

int proc(string s) {
  int n = sz(s);
  int ans = 1e9;
  reverse(allin(s));
  ans = min({check00(s, n), check25(s, n), check50(s, n), check75(s, n)});
  return ans;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    // cout << (proc(s) == 1e9 ? 100 : proc(s)) << endl;
  }
  cout << check25("265", 3);
  return 0;
}
