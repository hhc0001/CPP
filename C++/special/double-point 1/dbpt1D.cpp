#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;

int main() {
  for(cin >> t; t--;) {
    cin >> n >> s;
    int cnt = 0;
    for(int l = 0, r = n - 1; l <= r; l++, r--) {
      cnt += (cnt & 1) ^ (s[l] != s[r]);
    }
    cout << (cnt <= 3? "YES" : "NO") << endl;
  }
  return 0;
}
