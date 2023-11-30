#include <bits/stdc++.h>
using namespace std;

int t, n, m, x, y;
string s;

int main() {
  for(cin >> t; t--;) {
    cin >> n >> m >> x >> y;
    int z = y / 2 + (y & 1), ans = 0;
    if(z < x) {//多用一点1*2的瓷砖会更省钱。
      for(int i = 1; i <= n; i++) {
        cin>>s;
        for(int j = 0; j < m;) {
          if(s[j] == '.' && s[j + 1] == '.') {
            ans += y, j += 2;
          }
          else {
            if(s[j] == '.' && s[j + 1] == '*' || j == m - 1 && s[j] == '.') {
              ans += x, j += 2;
            }
            else {
              j++;
            }
          }
        }
      }
      cout << ans << endl;
    }
    else {//****************，这商家怎么这么黑心？用1*2的瓷砖还不如全用1*1的瓷砖更便宜，我要举报奸商！
      for(int i = 1; i <= n; i++) {
        cin >> s;
        for(int j = 0; j < m; j++) {
          ans += s[j] == '.';
        }
      }
      cout << x * ans << endl;
    }
  }
  return 0;
}
