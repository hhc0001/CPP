#include <bits/stdc++.h>
using namespace std;

int t, n, k, cnt, ans;
string s;

int main() {
  for(cin >> t; t--;) {
    cnt = 0, ans = 200001;
    cin >> n >> k >> s;
    for(int i = 0; i < k; i++) {
      cnt += s[i] == 'W';
    }
    ans = cnt;
    for(int l = 1, r = k; r < n; l++, r++) {
      (cnt -= s[l-1] == 'W') += s[r] == 'W';
      ans = min(ans, cnt);
    }
    cout << ans << endl;
  }
  return 0;
}
