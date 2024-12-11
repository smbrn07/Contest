#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define make_unique(x) (x).erase(unique(all(x)), (x).end())
#define read(x) for (int& i : x) cin >> i;
#define write(x) for (auto& i : x) cerr << i << ' '; cerr << endl
#define dbg(x) cerr << "Line(" << _LINE_ << ")->" << #x << " = " << (x) << endl
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define IO(file) freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout)
const int MAX = 2e6;
signed main() {
    IOS;
    IO("stem");
    int n;
    cin >> n;
    vector<int> freq(MAX + 1, 0);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        freq[x]++;
    }
    int res = 0;
    for (int i = 1; i <= MAX; i++) {
        int cnt = 0;
        for (int j = i; j <= MAX; j += i) {
            cnt += freq[j];
        }
        res = max(res, i * cnt);
    }
    cout << res;
}