#include "bits/stdc++.h"

using namespace std;

const int MOD = 1e8 + 7;

struct Node {
  int x, y;
};

int bfs(const vector<string> &grid, int n, int m) {
  vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
  vector<vector<int>> path_count(n, vector<int>(m, 0));
  queue<Node> q;

  // Starting point
  distance[0][0] = 0;
  path_count[0][0] = 1;
  q.push({0, 0});

  // Directions for moving up, down, left, right
  int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  while (!q.empty()) {
    Node current = q.front();
    q.pop();
    int x = current.x;
    int y = current.y;

    for (auto &dir : directions) {
      int nx = x + dir[0];
      int ny = y + dir[1];

      if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '1') {
        if (distance[nx][ny] > distance[x][y] + 1) {
          distance[nx][ny] = distance[x][y] + 1;
          path_count[nx][ny] = path_count[x][y];
          q.push({nx, ny});
        } else if (distance[nx][ny] == distance[x][y] + 1) {
          path_count[nx][ny] = (path_count[nx][ny] + path_count[x][y]) % MOD;
        }
      }
    }
  }

  return path_count[n - 1][m - 1];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("ANT.INP", "r", stdin);
  freopen("ANT.OUT", "w", stdout);
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);

  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }

  int shortest_steps = bfs(grid, n, m);
  int min_steps = grid[n - 1][m - 1] == '1'
                      ? n + m - 2
                      : INT_MAX; // Placeholder, to be calculated properly

  cout << shortest_steps << endl;
  cout << min_steps << endl;

  return 0;
}

