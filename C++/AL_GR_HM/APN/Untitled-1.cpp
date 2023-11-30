#include <bits/stdc++.h>
using namespace std;

int t, x, y;
queue<pair<int, int> > q;
set<int> s;

void REcord(pair<int, int> x) {
  if(s.find(x.first) != s.end()) {
    return ;
  }
  s.insert(x.first);
  q.push(x);
}

void BFS() {
  q.push(make_pair(x, 0));
  while(q.size()) {
    if(q.front().first == y) {
      cout << q.front().second << '\n';
      return ;
    }
    REcord(make_pair(q.front().first + 1, q.front().second + 1));
    REcord(make_pair(q.front().first - 1, q.front().second + 1));
    REcord(make_pair(q.front().first * 2, q.front().second + 1));
    q.pop();
  }
}

int main() {
  for(cin >> t; t--; ) {
    cin >> x >> y;
    BFS();
  }
  return 0;
}