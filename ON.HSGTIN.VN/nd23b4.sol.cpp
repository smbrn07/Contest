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
const int MAX = 1e7;
int freq[MAX + 1];
signed main() {
    IOS;
    // IO("test");
    int n, m;
    cin >> n >> m;
    int a[n];
    read(a);
    if (n == 1) {
        cout << (a[0] == m ? 1 : 0);
        return 0;  
    }
    int l = 0, r = n;
    int i = 0, j = 0;
    int distinct = 0;
    while (j < n) {
        if (freq[a[j]] == 0) distinct++; 
        freq[a[j]]++;
        while (distinct == m) {
            if (j - i < r - l) {
                l = i;
                r = j;
            }
            freq[a[i]]--;
            if (freq[a[i]] == 0) distinct--;
            i++;
        }
        j++;
    }
    if (r == n) {
        cout << 0;
    } else {
        cout << r - l + 1;
    }
    return 0;
}