#include <bits/stdc++.h>
using namespace std;

string s;
vector<int> ans;

int main() {
  cin >> s;
  int len = s.size();
  for(int l = 0, r = len - 1; l < r;) {
    while(s[l] == ')') {
      l++;
    }
    while(s[r] == '(') {
      r--;
    }
    if(l < r) {
      ans.push_back(l);
      ans.push_back(r);
      l++, r--;
      //cout << l << ' ' << r << ' ' << endl;
    }
  }
  sort(ans.begin(), ans.end());
  if(ans.size() == 0) {
    cout << 0 << '\n';
  }
  else {
    cout << "1\n" << ans.size() << '\n';
    for(int i = 0;i < ans.size(); i++) {
      cout << ans[i] + 1 << ' ';
    }
    cout << endl;
  }
  return 0;
}
