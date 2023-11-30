#include <bits/stdc++.h>
using namespace std;

int n, len;
string s;

int main() {
  for(cin >> n; n--;) {
    cin >> s;
    len=s.size();
    int cnt[4]={0}, ans = len, rns = 0;
    for(int l = 0, r = -1; r < len;) {
      if(cnt[1] && cnt[2] && cnt[3]) {
        ans = min(ans, r - l + 1);
        cnt[s[l++] - '0']--, rns = 1;
      }
      else {
        if(r == len - 1) {
          break;
        }
        cnt[s[++r] - '0']++;
      }
    }
    cout << (rns? ans : 0) << '\n';
  }
  return 0;
}