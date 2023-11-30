#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
int l[11], arr[11][11];
int vis[11];

void DFS(int pos) {
  if(pos > m) {
    for(int i = 1; i <= n; i++) {
      if(!vis[i]) {
        return;
      }
    }
    ans++;
    return;
  }
  for(int i = 1; i <= l[pos]; i++) {
    vis[arr[pos][i]]++;
  }
  DFS(pos + 1);
  for(int i = 1; i <= l[pos]; i++) {
    vis[arr[pos][i]]--;
  }
  DFS(pos + 1);
}

int main() {
  cin >> n >> m;
  for(int i = 1; i <= m; i++) {
    cin >> l[i];
    for(int j = 1; j <= l[i]; j++) {
      cin >> arr[i][j];
    }
  }
  DFS(1);
  cout << ans << endl;
  return 0;
}