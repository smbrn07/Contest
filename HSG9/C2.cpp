#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Match {
  int start, end, profit;
};

int findLastNonConflicting(const vector<Match> &matches, int i) {
  int lo = 0, hi = i - 1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (matches[mid].end < matches[i].start) {
      if (matches[mid + 1].end < matches[i].start) {
        lo = mid + 1;
      } else {
        return mid;
      }
    } else {
      hi = mid - 1;
    }
  }
  return -1;
}

int maxProfit(vector<Match> &matches) {
  sort(matches.begin(), matches.end(),
       [](const Match &a, const Match &b) { return a.end < b.end; });

  int n = matches.size();
  vector<int> dp(n);
  dp[0] = matches[0].profit;

  for (int i = 1; i < n; i++) {
    int includeCurrent = matches[i].profit;
    int lastNonConflict = findLastNonConflicting(matches, i);
    if (lastNonConflict != -1) {
      includeCurrent += dp[lastNonConflict];
    }

    dp[i] = max(dp[i - 1], includeCurrent);
  }
  return dp[n - 1];
}

int main() {
  int n;
  cin >> n;
  vector<Match> matches(n);
  for (int i = 0; i < n; i++) {
    cin >> matches[i].start >> matches[i].end >> matches[i].profit;
  }
  cout << maxProfit(matches) << endl;

  return 0;
}

