#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> d;
long long demtg = 0;
int i, n;
int a[5001];
bool OK(int a, int b, int c) { return (a + b > c); }
bool tgnhon(int a, int b, int c) { return (a * a + b * b > c * c); }
long long demvuong() {
  long long kq, i, j;

  for (i = 1; i <= n - 1; i++)
    for (j = i + 1; j <= n; j++)
      d[a[i] * a[i] + a[j] * a[j]]++;
  ;
  kq = 0;
  for (i = 1; i <= n; i++)
    kq = kq + d[a[i] * a[i]];
  return kq;
}

long long demnhon() {
  long long kq = 0;
  int i, j, d, c;
  for (i = 1; i <= n - 2; i++) {
    d = i + 2;
    c = i + 2;
    for (j = i + 1; j <= n - 1; j++) {
      while (c <= n && OK(a[i], a[j], a[c]))
        c++;
      demtg = demtg + c - j - 1;
      while (d <= n && tgnhon(a[i], a[j], a[d]))
        d++;
      if (d - 1 <= c)
        kq = kq + d - j - 1;
    }
  }
  return kq;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("CAU5.INP", "r", stdin);
  freopen("CAU5.OUT", "w", stdout);
  long long nhon, tu, vuong;
  cin >> n;
  for (i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + 1 + n);
  vuong = demvuong();
  nhon = demnhon();
  tu = demtg - vuong - nhon;
  cout << nhon << " " << vuong << " " << tu;
  return 0;
}
