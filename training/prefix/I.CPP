#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 407;

int n, a[nmax][nmax];
ll d1[nmax][nmax], d2[nmax][nmax];

ll cal(int i, int j, int k) {
	return d1[j][k+j-i]-d1[i-1][k-1]-d2[j][k]+d2[i-1][k+j-i+1];
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
  	for (int j = 1; j <= n; ++j) cin >> a[i][j];
  }
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			d1[i][j]=d1[i-1][j-1]+a[i][j];
			d2[i][j]=d2[i-1][j+1]+a[i][j];
		}
	}
	ll ans = 0;
	for (int i = 1; i < n; ++i) {
		for (int j = i+1; j <= n; ++j) {
			for (int k = 1; k+j-i <= n; ++k) {
				ans=max(ans, cal(i, j, k));
			}
		}
	}
	cout << ans << endl;
  return 0;
}