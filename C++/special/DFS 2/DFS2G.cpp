#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c, q, u, v, fa[110][110], sz[110][110];

int findfa(int type, int x) {
  return fa[type][x] == x? x : fa[type][x] = findfa(type, fa[type][x]);
}

bool issmset(int type, int a, int b) {
  return findfa(type, a) == findfa(type, b);
}

void unionn(int type, int a, int b) {
  int c = findfa(type, a), d = findfa(type, b);
  if(issmset(type, c, d)) {
    return ;
  }
  int e = sz[type][c], f = sz[type][d];
  if(e >= f) {
    sz[type][c] += f;
    fa[type][d] = c;
  }
  else {
    sz[type][d] += e;
    fa[type][c] = d;
  }
}

int main() {
  cin >> n >> m;
  for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= n; j++) {
      fa[i][j] = j, sz[i][j] = 1;
    }
  }
  for(int i = 1; i <= m; i++) {
    cin >> a >> b >> c;
    unionn(c, a, b);
  }
  cin >> q;
  for(int i = 1; i <= q; i++) {
    cin >> u >> v;
    int ans = 0;
    for(int i = 1; i <= m; i++) {
        ans += issmset(i, u, v);
    }
    cout << ans << endl;
  }
  return 0;
}