#include <bits/stdc++.h>
using namespace std;

int n, m, l[110], lang[110][110];
bool vis[110][110];
int fa[110], sz[110], cnt, ans;

int findfa(int x) {
  return fa[x] == x? x:fa[x] = findfa(fa[x]);
}

bool issmset(int a, int b) {
  return findfa(a) == findfa(b);
}

void unionn(int a, int b) {
  int c = findfa(a), d = findfa(b);
  if(c == d) {
    return ;
  }
  int e = sz[a], f = sz[b];
  if(e >= f) {
    sz[c] += sz[d];
    fa[d] = c;
  }
  else {
    sz[d] += sz[c];
    fa[c] = d;
  }
  cnt--;
}

int main() {
  cin >> n >> m;
  cnt = n;
  for(int i = 1; i <= n; i++) {
    fa[i] = i, sz[i] = 1;
  }
  for(int i = 1; i <= n; i++) {
    cin >> l[i];
    if(l[i] == 0) {
      cnt--, ans++;
    }
    for(int j = 1; j <= l[i]; j++) {
      cin >> lang[i][j];
      vis[i][lang[i][j]] = 1;
      for(int k = 1; k < i; k++) {
        if(vis[k][lang[i][j]]) {
          unionn(i, k);
        }
      }
    }
  }
  cout << ans + cnt - (cnt != 0) << endl;
  return 0;
}