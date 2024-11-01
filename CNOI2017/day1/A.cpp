#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

using Int = long long;

template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
  return os << "(" << a.first << ", " << a.second << ")";
};
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) {
  const int sz = as.size();
  os << "[";
  for (int i = 0; i < sz; ++i) {
    if (i >= 256) {
      os << ", ...";
      break;
    }
    if (i > 0) {
      os << ", ";
    }
    os << as[i];
  }
  return os << "]";
}
template <class T> void pv(T a, T b) {
  for (T i = a; i != b; ++i)
    cerr << *i << " ";
  cerr << endl;
}
template <class T> bool chmin(T &t, const T &f) {
  if (t > f) {
    t = f;
    return true;
  }
  return false;
}
template <class T> bool chmax(T &t, const T &f) {
  if (t < f) {
    t = f;
    return true;
  }
  return false;
}
#define COLOR(s) ("\x1b[" s "m")

// k[0]    k[1]    k[2]      k[n-1]   INF
//   [------)[------)[-  ...  -)[------)
//     v[0]    v[1]              v[n-1]
template <class K, class V> struct Positional : map<K, V> {
  V b;
  Positional() : b(0) {}
  // k: least significant position
  Positional(K k, V b_) : map<K, V>{{k, 0}}, b(b_) {}
  auto split(K k) {
    auto it = this->upper_bound(k);
    assert(it != this->begin());
    auto it1 = it;
    --it1;
    return this->emplace_hint(it, k, it1->second);
  }
  // x += b^k
  void add(K k) {
    auto it = split(k);
    for (; it->second == b - 1; it = this->erase(it)) {
    }
    if (k < it->first)
      this->emplace(k, 0);
    split(it->first + 1);
    it->second += 1;
  }
  // x -= b^k
  void sub(K k) {
    auto it = split(k);
    for (; it->second == 0; it = this->erase(it)) {
    }
    if (k < it->first)
      this->emplace(k, b - 1);
    split(it->first + 1);
    it->second -= 1;
  }
  // x += b^k v
  void add(K k, V v) {
    assert(-b < v);
    assert(v < b);
    if (v > 0) {
      split(k + 1);
      auto it = split(k);
      if (it->second >= b - v) {
        it->second -= (b - v);
        add(k + 1);
      } else {
        it->second += v;
      }
    } else if (v < 0) {
      split(k + 1);
      auto it = split(k);
      if (it->second < -v) {
        it->second += (b + v);
        sub(k + 1);
      } else {
        it->second += v;
      }
    }
  }
  // min k s.t. x < b^k
  K length() {
    auto it = this->end();
    --it;
    for (;;) {
      if (it == this->begin())
        return it->first;
      auto itL = it;
      --itL;
      if (itL->second != 0)
        return it->first;
      this->erase(it);
      it = itL;
    }
  }
  // b^k's place
  V at(K k) const {
    auto it = this->upper_bound(k);
    assert(it != this->begin());
    --it;
    return it->second;
  }
};

constexpr int E = 60;

int main() {
  int N, T1, T2, T3;
  for (; ~scanf("%d%d%d%d", &N, &T1, &T2, &T3);) {
    Positional<int, Int> f(0, 1LL << E);
    for (int n = 0; n < N; ++n) {
      int O;
      scanf("%d", &O);
      if (O == 1) {
        Int A;
        int B;
        scanf("%lld%d", &A, &B);

        int sig = +1;
        if (A < 0) {
          sig = -sig;
          A = -A;
        }
        const int Q = B / E;
        const int R = B % E;
        f.add(Q, sig * ((A & ((1LL << (E - R)) - 1)) << R));
        f.add(Q + 1, sig * (A >> (E - R)));
      } else if (O == 2) {
        int K;
        scanf("%d", &K);

        const int Q = K / E;
        const int R = K % E;
        const Int res = f.at(Q);
        const Int ans = res >> R & 1;
        printf("%lld\n", ans);
      } else {
        assert(false);
      }
    }
  }
  return 0;
}
