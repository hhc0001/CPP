#include <bits/stdc++.h>
using namespace std;

int t, n, m, x, y;
string s;

int main() {
  for(cin >> t; t--;) {
    cin >> n >> m >> x >> y;
    int z = y / 2 + (y & 1), ans = 0;
    if(z < x) {//����һ��1*2�Ĵ�ש���ʡǮ��
      for(int i = 1; i <= n; i++) {
        cin>>s;
        for(int j = 0; j < m;) {
          if(s[j] == '.' && s[j + 1] == '.') {
            ans += y, j += 2;
          }
          else {
            if(s[j] == '.' && s[j + 1] == '*' || j == m - 1 && s[j] == '.') {
              ans += x, j += 2;
            }
            else {
              j++;
            }
          }
        }
      }
      cout << ans << endl;
    }
    else {//****************�����̼���ô��ô���ģ���1*2�Ĵ�ש������ȫ��1*1�Ĵ�ש�����ˣ���Ҫ�ٱ����̣�
      for(int i = 1; i <= n; i++) {
        cin >> s;
        for(int j = 0; j < m; j++) {
          ans += s[j] == '.';
        }
      }
      cout << x * ans << endl;
    }
  }
  return 0;
}
