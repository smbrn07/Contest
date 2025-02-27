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
#define dbg(x) cerr << "Line(" << __LINE__ << ")->" << #x << " = " << (x) << endl;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define IO(file) freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);
#define START_TIMER auto start_time = chrono::high_resolution_clock::now();
#define END_TIMER auto end_time = chrono::high_resolution_clock::now(); \
        cerr << "Execution Time: " << chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count() << " ms" << endl;
const int MOD = 1e9 + 7;
signed main() {
    IOS
    IO("scp")
    int n;
    cin >> n;
    int sum = 0;
    vector<int> res(4);
    for (int i = 0; i * i <= n; i++) {
        for (int j = 0; j * j <= n - i * i; j++) {
            for (int k = 0; k * k <= n - i * i - j * j; k++) {
                int l = n - i * i - j * j - k * k;
                int r = sqrt(l);
                if (r * r == l) {
                    int curr_sum = i + j + k + r;
                    if (curr_sum > sum) {
                        sum = curr_sum;
                        res = {i, j, k, r};
                    }
                }
            }
        }
    }
    sort(all(res));
    write(cout, res);
}