#include <bits/stdc++.h>
using namespace std;

const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n, m, vis[110][110], ans;
char c[110][110];

void DFS(int x, int y) {
  if(c[x][y] == '.' || c[x][y] == 0 || vis[x][y]) {
    return ;
  }
  vis[x][y] = 1;
  for(int i = 0; i < 8; i++) {
    DFS(x + dx[i], y + dy[i]);
  }
}

int main() {
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin >> c[i][j];
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(c[i][j] == 'W' && !vis[i][j]) {
        ans++, DFS(i, j);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
