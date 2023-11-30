#include <bits/stdc++.h>
using namespace std;

int t, a[3000030], c;
long long p[300030];
long long n;

void euler() {
  a[1] = 1;
  for(long long i = 2; i <= 3000000; i++) {
    if(!a[i]) {
      p[++c] = i;
    }
    for(int j = 1; j <= c; j++) {
      if(i * p[j] > 3000000) {
        break;
      }
      a[i * p[j]] = 1;
      if(!i % p[j]) {
        break;
      }
    }
  }
}

long long sqrtll(long long x) {
  long long ans;
  for(long long l = 1, r = x; l <= r; ) {
    long long mid = (l + r) >> 1;
    if(mid > 3000000000 || mid * mid > x) {
      r = mid - 1;
    }else {
      ans = mid, l = mid + 1;
    }
  }
  return ans;
}

bool isp(long long x) {
  for(long long i = 2; i * i <= x; i++) {
    if(!x % i) {
      return 0;
    }
  }
  return x > 1;
}

int main() {
  euler();
  for(cin >> t; t--; ) {
    cin >> n;
    for(int i = 1; p[i] * p[i] * p[i] <= n; i++) {
      if(n % p[i] == 0) {
        long long tmp = sqrtll(n / p[i]);
        if(tmp * tmp == n / p[i] && isp(tmp)) {
          cout << tmp << ' ' << p[i] << '\n';
          goto nxt;
        }
      }
      if(n % (p[i] * p[i]) == 0 && isp(n / p[i] / p[i])) {
        cout << p[i] << ' ' << n / p[i] / p[i] << '\n';
        goto nxt;
      }
    }
    nxt:
    ;;;;
  }
  return 0;
}