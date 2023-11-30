// LUOGU_RID: 134710765
#include <bits/stdc++.h>
using namespace std;

int n, vis[200020], stk[200020], top;
string s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> s;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == 'A' || s[i] == 'B') {
      stk[++top] = i;
    }else {
      if(top >= 2 && s[stk[top]] == 'B' && s[stk[top - 1]] == 'A') {
        top -= 2;
      }else {
        stk[++top] = i;
      }
    }
    for(int i = 1; i <= top; i++) {
      cout << s[stk[i]];
    }
    cout << '\n';
  }
  for(int i = 1; i <= top; i++) {
    cout << s[stk[i]];
  }
  cout << '\n';
  return 0;
}
