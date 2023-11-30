#include <bits/stdc++.h>
using namespace std;

int n, vis[10][256];
char ans[10][10];
string r, c;

bool check() {
  for(int i = 1; i <= n; i++) {
    if(!vis[i]['A'] || !vis[i]['B'] || !vis[i]['C']) {
      return 0;
    }
  }
  for(int i = 1; i <= n; i++) {
    int j = 1, k = 1;
    for(; ans[i][j] == '.'; j++) {
    }
    for(; ans[k][i] == '.'; k++) {
    }
    if(ans[i][j] != r[i - 1] || ans[k][i] != c[i - 1]) {
      return 0;
    }
  }
  return 1;
}

void DFS(int x) {
  /*
  cout << x << '\n';
  for(int i = 1; i <= n; i++) {
    cout << "col. " << i << ':' << vis[i]['A'] << vis[i]['B'] << vis[i]['C'] << '\n';
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cout << ans[i][j];
    }
    cout << '\n';
  }
  */
  if(x > n) {
    /*
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        cout << ans[i][j];
      }
      cout << '\n';
    }
    */
    if(check()) {
      cout << "Yes" << '\n';
      for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
          cout << ans[i][j];
        }
        cout << '\n';
      }
      exit(0);
    }
    return ;
  }
  char a[3] = {'A', 'B', 'C'};
  do {
    for(int i = 1; i + 2 <= n; i++) {
      for(int j = i + 1; j + 1 <= n; j++) {
        for(int k = j + 1; k <= n; k++) {
          if(!vis[i][a[0]] && !vis[j][a[1]] && !vis[k][a[2]]) {
            vis[i][a[0]] = vis[j][a[1]] = vis[k][a[2]] = 1, ans[x][i] = a[0], ans[x][j] = a[1], ans[x][k] = a[2];
            DFS(x + 1);
            vis[i][a[0]] = vis[j][a[1]] = vis[k][a[2]] = 0, ans[x][i] = ans[x][j] = ans[x][k] = '.';
          }
        }
      }
    }
  }while(next_permutation(a, a + 3));
}

int main() {
  cin >> n >> r >> c;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      ans[i][j] = '.';
    }
  }
  DFS(1);
  cout << "No" << '\n';
  return 0;
}