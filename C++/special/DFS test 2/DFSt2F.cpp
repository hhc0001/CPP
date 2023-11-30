#include <bits/stdc++.h>
using namespace std;

int n, m;
string s, b;

int main() {
  cin >> n >> m >> s >> b;
  if((s[0] == '<' && s[n - 1] == '>' && b[0] == 'v' && b[m - 1] == '^') || (s[0] == '>' && s[n - 1] == '<' && b[0] == '^' && b[m - 1] == 'v')) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
  return 0;
}