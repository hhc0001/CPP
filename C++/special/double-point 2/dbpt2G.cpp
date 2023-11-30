#include <bits/stdc++.h>
using namespace std;

int t, n, arr[200020];

int main() {
  for(cin >> t; t--;) {
    cin >> n;
    for(int i = 1; i <= n; i++) {
      cin >> arr[i];
    }
    int mn = 1, mx = n, l = 1, r = n, fl = 0, fr = 0;
    while(l < r && (l != fl || r != fr)) {
      fl = l, fr = r;
      while(arr[l] == mn) {
        mn++, l++;
      }
      while(arr[l] == mx) {
        mx--, l++;
      }
      while(arr[r] == mn) {
        mn++, r--;
      }
      while(arr[r] == mx) {
        mx--, r--;
      }
      //cout << l << ' ' << r << ' ' << fl << ' ' << fr << '\n';
    }
    if(l < r) {
      cout << l << ' ' << r << '\n';
    }
    else {
      cout << -1 << '\n';
    }
  }
  return 0;
}
