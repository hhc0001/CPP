#include <bits/stdc++.h>
using namespace std;

int t, n, w[51], mx;

int main() {
  for(cin >> t; t--;) {
    cin >> n;
    mx = 0;
    for(int i = 1; i <= n; i++) {
      cin >> w[i];
    }
    sort(w + 1, w + n + 1);
    mx = w[n - 1] + w[n];
    int rns = 0;
    for(int i = 1; i <= mx; i++) {
      int ans = 0;
      for(int l = 1, r = n; l < r;) {
        if(w[l] + w[r] == i) {
          l++, r--, ans++;
        }
        if(w[l] + w[r] < i) {
          l++;
        }
        if(w[l] + w[r] > i) {
          r--;
        }
      }
      rns = max(rns, ans);
    }
    cout << rns << '\n';
  }
  return 0;
}