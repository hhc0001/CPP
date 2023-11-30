#include <bits/stdc++.h>
using namespace std;

int t, n, arr[400040], ans;
char c;
string s;
vector<int> v;

int main() {
  for(cin >> t; t--;) {
    ans = 0;
    cin >> n >> c >> s;
    s = s + s;
    if(c == 'g') {
      cout << 0 << endl;
      continue;
    }
    for(int i = 0; i < n * 2; i++) {
      if(s[i] == 'g') {
        int l = v.size();
        for(int j = 0;j < l;j++) {
          arr[v[j]] = i - v[j];
          //cout<<v[j]<<' '<<i<<' '<<i-v[j]<<endl;
        }
        //cout<<endl;
        v.clear();
      }
      v.push_back(i);
    }
    //for(int i = 0; i < n; i++) {
      //cout << arr[i] << ' ';
    //}
    //cout << endl;
    //for(int i = 0; i < n; i++) {
      //cout << arr[i] << ' ';
    //}
    //cout << endl;
    for(int i = 0; i < n; i++) {
      if(s[i] == c) {
        ans = max(ans, arr[i]);
        //cout << "YES " << i << ' ' << ans << endl;
      }
    }
    v.clear();
    cout << ans << endl;
  }
  return 0;
}
