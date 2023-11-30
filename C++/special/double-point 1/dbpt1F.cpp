#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, arr[200020], b;

int tpbd(int x) {
  int l = 1, r = n, ans = 0;
  while(l <= r) {
    int mid = (l + r) >> 1;
    if(arr[mid] <= x) {
      ans = mid, l = ++mid;
    }
    else {
      r = --mid;
    }
    //cout << mid << ' ' << ans << endl;
  }
  return ans;
}

signed main() {
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    cin >> arr[i];
    arr[i] += arr[i-1];
  }
  //for(int i = 1; i <= n; i++) {
    //cout << arr[i] << ' ';
  //}
  //cout << endl;
  for(int i = 1; i <= m; i++) {
    cin >> b;
    int pos = tpbd(b);
    //cout << pos << endl;
    if(arr[pos] == b) {
      cout << pos << ' ' << arr[pos] - arr[--pos] << endl;
    }
    else {
      cout << pos + 1 << ' ' << b - arr[pos] << endl;
    }
  }
  return 0;
}
