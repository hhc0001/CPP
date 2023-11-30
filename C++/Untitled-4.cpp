#include <bits/stdc++.h>
using namespace std;

const long long kMod = 998244353;

long long x, y;

long long qinv(long long a, long long mod) {
  long long ans = 1;
  a = a % mod;
  long long x = mod - 2;
  for(; x; x >>= 1) {
    if(x & 1) {
      ans = ans * a % mod;
    }
    a = a * a % mod;
  }
  return ans;
}

int main() {
  cin >> x >> y;
  cout << qinv(y, kMod) * x % kMod << '\n';
  return 0;
}