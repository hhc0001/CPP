#include <bits/stdc++.h>
using namespace std;

int t, n, arr[200020], pre[200020];

int main() {
  for(cin >> t; t--;) {
    cin >> n;
    fill(pre + 1, pre + n + 1, 0);
    int ans = 1e9;
    for(int i = 1; i <= n; i++) {
      cin >> arr[i];
      if(pre[arr[i]]) {
        ans = min(ans, i - pre[arr[i]] + 1);
      }
      pre[arr[i]] = i;
    }
    cout << (ans == 1000000000? -1 : ans) << '\n';
  }
  return 0;
}
