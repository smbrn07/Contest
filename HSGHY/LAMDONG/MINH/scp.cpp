#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen("scp.inp", "r", stdin);
  freopen("scp.out", "w", stdout);
  int n; cin >> n;
  vector<int> v;
  for (int i = 1; i*i <= 1e5; ++i) {
  	v.push_back(i*i);
  }
  vector<int> ans;
  int cur = 0;
  for (int i = 0; i < v.size(); ++i) {
  	for (int j = 0; j < v.size(); ++j) {
  		for (int k = 0; k < v.size(); ++k) {
  			if (binary_search(v.begin(), v.end(), n-v[i]-v[j]-v[k])) {
  				if (sqrt(v[i])+sqrt(v[j])+sqrt(v[k])+sqrt(n-v[i]-v[j]-v[k])>cur) {
  					cur = sqrt(v[i])+sqrt(v[j])+sqrt(v[k])+sqrt(n-v[i]-v[j]-v[k]);
  					ans.clear();
  					ans.push_back(sqrt(v[i]));
  					ans.push_back(sqrt(v[j]));
  					ans.push_back(sqrt(v[k]));
  					ans.push_back(sqrt(n-v[i]-v[j]-v[k]));
  				}
  			}
  		}
  	}
  }
  sort(v.begin(),v.end());
  if (cur>0) for (int i=0; i < ans.size(); ++i) cout << ans[i]<< ' ';
  else cout << -1;
  return 0;
}