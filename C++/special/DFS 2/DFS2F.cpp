#include <bits/stdc++.h>
using namespace std;

int t, n, ft[5050], ans;
char type[5050];
vector<int> child[5050];

pair<int, int> DFS(int pos) {
  int len = child[pos].size();
  pair<int, int> cnt;
  cnt.first += type[pos] == 'B', cnt.second += type[pos] == 'W';
  for(int i = 0; i < len; i++) {
    pair<int, int> tmp = DFS(child[pos][i]);
    cnt.first += tmp.first, cnt.second += tmp.second;
  }
  ans += cnt.first == cnt.second;
  return cnt;
}

int main() {
  for(cin >> t; t--;) {
    cin >> n;
    ans = 0;
    for(int i = 1; i <= n; i++) {
      child[i].clear();
    }
    for(int i = 2; i <= n; i++) {
      cin >> ft[i];
      child[ft[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++) {
      cin >> type[i];
    }
    DFS(1);
    cout << ans << endl;
  }
  return 0;
}