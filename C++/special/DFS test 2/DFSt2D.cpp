#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, fa[51], sz[51], ans = 1, x, y;

int findfa(int x) {
  return fa[x] == x? x:fa[x] = findfa(fa[x]);
}

bool issmset(int x, int y) {
  return findfa(x) == findfa(y);
}

void unionn(int x, int y) {
  int z = findfa(x), u = findfa(y);
  if(z == u) {
    return ;
  }
  int v = sz[z], w = sz[u];
  if(v >= w) {
    sz[z] += sz[u];
    fa[u] = z;
  }
  else {
    sz[u] += sz[z];
    fa[z] = u;
  }
  ans *= 2;
}

signed main() {
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    fa[i] = i, sz[i] = 1;
  }
  for(int i = 1; i <= m; i++) {
    cin >> x >> y;
    unionn(x, y);
  }
  cout << ans << '\n';
  return 0;
}
