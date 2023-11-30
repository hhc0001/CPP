#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int n, m, vis[110][110], arr[110][110], ans;
char c;

void DFS(int x, int y) {
  if(arr[x][y] == 0 || vis[x][y]) {
    return ;
  }
  vis[x][y] = 1;
  for(int i = 0; i < 4; i++) {
    DFS(x + dx[i], y + dy[i]);
  }
}

int main() {
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin >> c;
      arr[i][j] = c - '0';
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(arr[i][j] && !vis[i][j]) {
        ans++, DFS(i, j);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
