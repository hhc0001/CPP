#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};

int n, m, arr[1010][1010];
bool vis[1010][1010];
priority_queue<int, vector<int>, less<int> > pq;

int DFS(int x, int y) {
  if(x < 1 || x > n || y < 1 || y > m ||vis[x][y]) {
    return 0;
  }
  int ans = vis[x][y] = 1;
  for(int i = 0; i < 4; i++) {
    if(arr[x][y] >> i & 1 ^ 1) {
      ans += DFS(x + dx[i], y + dy[i]);
    }
  }
  return ans;
}

int main() {
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin >> arr[i][j];
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(!vis[i][j]) {
        pq.push(DFS(i, j));
      }
    }
  }
  while(pq.size()) {
    cout << pq.top() << ' ';
    pq.pop();
  }
  return 0;
}
