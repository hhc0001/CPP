#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int n, arr[35][35];

void DFS(int x, int y) {
  if(arr[x][y] != 2) {
    return ;
  }
  arr[x][y] = 0;
  for(int i = 0; i < 4; i++) {
    DFS(x + dx[i], y + dy[i]);
  }
}

int main() {
  cin >> n;
  for(int i = 0; i <= n + 1; i++) {
    arr[0][i] = arr[n + 1][i] = arr[i][0] = arr[i][n + 1] = 2;
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> arr[i][j];
      arr[i][j] = (arr[i][j] == 0) * 2 + (arr[i][j] == 1);
    }
  }
  DFS(0, 0);
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cout << arr[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
