#include <bits/stdc++.h>
#define file "prime"
using namespace std;
int nTest = 100;

mt19937_64 Rd(time(0));

long long Rand(long long l, long long r) { return Rd() % (r - l + 1) + l; }

void sinh_test() { ofstream cout("prime.inp"); }

main() {
  for (int iTest = 1; iTest <= nTest; iTest++) {
    sinh_test();
    cout << "Test " << iTest;
    system(file ".exe");
    system(file "_trau.exe");

    if (system("fc " file ".out " file ".ans")) {
      cout << "Wrong";
      break;
    }
    cout << "Correct\n";
  }
}
