#include "bits/stdc++.h"
using namespace std;

const int MOD = 1e9 + 7;
const int BUF_SZ = 1 << 15;
const int nmax = 1e5 + 7;

#define endl '\n'
#define pb push_back

// BeginCodeSnip{Input}
inline namespace Input {
char buf[BUF_SZ];
int pos;
int len;
char next_char() {
	if (pos == len) {
		pos = 0;
		len = (int)fread(buf, 1, BUF_SZ, stdin);
		if (!len) { return EOF; }
	}
	return buf[pos++];
}

int read_int() {
	int x;
	char ch;
	int sgn = 1;
	while (!isdigit(ch = next_char())) {
		if (ch == '-') { sgn *= -1; }
	}
	x = ch - '0';
	while (isdigit(ch = next_char())) { x = x * 10 + (ch - '0'); }
	return x * sgn;
}
}  // namespace Input
// EndCodeSnip
// BeginCodeSnip{Output}
inline namespace Output {
char buf[BUF_SZ];
int pos;

void flush_out() {
	fwrite(buf, 1, pos, stdout);
	pos = 0;
}

void write_char(char c) {
	if (pos == BUF_SZ) { flush_out(); }
	buf[pos++] = c;
}

void write_int(int x) {
	static char num_buf[100];
	if (x < 0) {
		write_char('-');
		x *= -1;
	}
	int len = 0;
	for (; x >= 10; x /= 10) { num_buf[len++] = (char)('0' + (x % 10)); }
	write_char((char)('0' + x));
	while (len) { write_char(num_buf[--len]); }
	write_char('\n');
}

// auto-flush output when program exits
void init_output() { assert(atexit(flush_out) == 0); }
}  // namespace Output
// EndCodeSnip

vector<int> adj[nmax], adjk[nmax];
bool visited[nmax];
int parent[nmax];

void bfs(int u) {
	queue<int> q; q.push(u);
	visited[u]=1;
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int x : adj[v]) {
			if (!visited[x]) {
				parent[x]=v;
				visited[x]=1;
				q.push(x);
			}
		}
	}
}


signed main() {
	init_output();
	int n = read_int();
	int m = read_int();
	int k = read_int();
	for (int i = 1; i <= m; ++i) {
		int x = read_int(), y = read_int();
		adj[x].pb(y); adj[y].pb(x);
	}
	for (int i = 1; i <= n; ++i) {
		
	}
	return 0;
}