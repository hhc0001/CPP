#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int n, m, arr[1010][1010], qx, qy, vis1[1010][1010], vis2[1010][1010], ans[1010][1010];
char c;

int DFS1(int x, int y) {
  if(vis1[x][y]) {
    return 0;
  }
  int res = vis1[x][y] = 1; ;
  for(int i = 0; i < 4; i++) {
    if(arr[x + dx[i]][y + dy[i]] != arr[x][y]) {
      res += DFS1(x + dx[i], y + dy[i]);
    }
  }
  return res;
}

void DFS2(int x, int y, int num) {
  if(vis2[x][y]) {
    return ;
  }
  ans[x][y] = vis2[x][y] = num;
  for(int i = 0; i < 4; i++) {
    if(arr[x + dx[i]][y + dy[i]] != arr[x][y]) {
      DFS2(x + dx[i], y + dy[i], num);
    }
  }
}

int main() {
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> c;
      arr[i][j] = c - '0';
    }
  }
  for(int i = 1; i <= n; i++) {
    arr[0][i] = arr[1][i], arr[i][0] = arr[i][1],arr[n + 1][i] = arr[n][i], arr[i][n + 1] = arr[i][n];
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(!vis1[i][j]) {
        DFS2(i, j, DFS1(i, j));
      }
    }
  }
  for(int i = 1; i <= m; i++) {
    cin >> qx >> qy;
    cout << ans[qx][qy] << '\n';
  }
  return 0;
}
