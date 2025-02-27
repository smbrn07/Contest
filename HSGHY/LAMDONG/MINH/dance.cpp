#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define read(x) for (int& i : x) cin >> i;
#define write(stream, x) for (auto& i : x) stream << i << ' '; stream << endl;
#define dbg(x) cerr << "Line(" << _LINE_ << ")->" << #x << " = " << (x) << endl;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define IO(file) freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);
#define START_TIMER auto start_time = chrono::high_resolution_clock::now();
#define END_TIMER auto end_time = chrono::high_resolution_clock::now(); \
        cerr << "Execution Time: " << chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count() << " ms" << endl;
const int MOD = 1e9 + 7;
signed main() {
    IOS
    IO("dance")
    int n;
    string s;
    cin >> n >> s;
    int toggle = 0;
    int res = 0;
    unordered_map<int,int> mp;
    mp[0] = 1;
    for (char& c : s) {
        if (c == 'a') toggle--;
        else toggle++;
        if (mp.count(toggle)) res += mp[toggle];
        mp[toggle]++;
    }
    cout << res;
}