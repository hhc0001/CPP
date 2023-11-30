#include <bits/stdc++.h>
using namespace std;

int t, n;
char c;
deque<char> dq;

int main() {
  for(cin >> t; t--;) {
    dq.clear();
    cin >> n;
    for(int i = 1; i <= n; i++) {
      cin >> c;
      dq.push_back(c);
    }
    while((dq.front() - '0') ^ (dq.back() - '0') == 1 && dq.size()) {
      dq.pop_front();
      dq.pop_back();
    }
    //cout << endl;
    cout << dq.size() << endl;
    //cout << endl;
  }
  return 0;
}
