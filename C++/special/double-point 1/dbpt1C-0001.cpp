#include <bits/stdc++.h>
using namespace std;

const string ts = "";

int t, k, l[2], p[2], c[2];
string s[2];
priority_queue<char, vector<char>, greater<char> > pq1, pq2;

int main() {
  for(cin>>t; t--;) {
    cin >> l[0] >> l[1] >> k >> s[0] >> s[1];
    sort(s[0].begin(), s[0].end()), sort(s[1].begin(), s[1].end());
    for(c[0] = c[1] = p[0] = p[1] = 0; p[0] < l[0] && p[1] < l[1];) {
      bool o1 = c[0] == k || /*没法选第一个了？*/ 
             c[1] < k && /*还可以选第二个？*/ 
             s[0][p[0]] > s[1][p[1]]; //选第二个更优？ 
      cout << s[o1][p[o1]++];
      c[o1]++, c[!o1] = 0;
    }
    cout << '\n';
  }
  return 0;
}
