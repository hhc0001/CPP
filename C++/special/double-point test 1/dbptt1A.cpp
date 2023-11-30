#include <bits/stdc++.h>
#define int long long
using namespace std;

int t,n,arr[200020];

signed main() {
  for(cin >> t; t--;) {
    cin >> n;
    for(int i = 1; i <= n; i++) {
      cin >> arr[i];
    }
    sort(arr + 1,arr + n + 1);
    int ans = 0;
    for(int l = 1, r = n, sl = arr[1], sr = arr[n]; l < r;) {
      //cout<<l<<' '<<r<<' '<<sl<<' '<<sr<<endl;
      while(l < r && sl < sr && n - r + 1 >= l) {
        sl += arr[++l];
        //cout<<l<<' '<<r<<' '<<sl<<' '<<sr<<endl;
      }
      if(n - r + 1 < l && sl < sr) {
        ans = 1;
        break;
      }
      sr += arr[--r];
    }
    cout << (ans? "YES" : "NO") << endl;
  }
  return 0;
}
