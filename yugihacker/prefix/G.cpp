#include "bits/stdc++.h"

using namespace std;

bool isStrictlyIncreasing(const vector<long long>& a, int start, int end) {
   for (int i = start + 1; i <= end; i++) {
      if (a[i] < a[i - 1]) {
         return false;
      }
   }
   return true;
}

bool isStrictlyDecreasing(const vector<long long>& a, int start, int end) {
   for (int i = start + 1; i <= end; i++) {
      if (a[i] > a[i - 1]) {
         return false;
      }
   }
   return true;
}

int main() {
   int n, q;
   cin >> n >> q;
   vector<long long> a(n);

   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }

   vector<pair<int, int>> queries(q);
   for (int i = 0; i < q; ++i) {
      int l, r;
      cin >> l >> r;
      queries[i] = make_pair(l - 1, r - 1);
   }

   for (const auto& query : queries) {
      int l = query.first;
      int r = query.second;

      long long maxElement = a[l];
      int maxIndex = l;
      int maxCount = 1;

      for (int j = l + 1; j <= r; j++) {
         if (a[j] > maxElement) {
            maxElement = a[j];
            maxIndex = j;
            maxCount = 1;
         } else if (a[j] == maxElement) {
            maxCount++;
         }
      }

      if (maxCount == 1 && isStrictlyIncreasing(a, l, maxIndex) &&
          isStrictlyDecreasing(a, maxIndex, r)) {
         cout << "Yes" << endl;
      } else {
         cout << "No" << endl;
      }
   }
}
