#include <bits/stdc++.h>
using namespace std;

int n, arr[11], m, shit[100010], x;
bool vis[100010];
queue<int> q;

void REcord(int pos) {
  if(pos > x || vis[pos]) {
    return;
  }
  if(pos == x) {
    cout << "Yes" << '\n';
    exit(0);
  }
  vis[pos] = 1;
  q.push(pos);
}

void BFS() {
  REcord(0);
  while(q.size()) {
    int tmp = q.front();
    q.pop();
    for(int i = 1; i <= n; i++) {
      REcord(tmp + arr[i]);
    }
  }
}

int main() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  cin >> m;
  for(int i = 1; i <= m; i++) {
    cin >> shit[i];
    vis[shit[i]] = 1;
  }
  cin >> x;
  BFS();
  cout << "No" << '\n';
  return 0;
}
