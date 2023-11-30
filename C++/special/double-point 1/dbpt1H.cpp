#include <bits/stdc++.h>
using namespace std;

int t, n, arr[200020], pre, suf, ans;
map<int, int> m;

int main() {
	for(cin >> t; t--;) {
		cin >> n;
		ans = 0;
		for(int i = 1; i <= n; i++) {
			cin >> arr[i];
			pre += arr[i];
			m[pre] = i;
		}
		for(int i = n; i >= 1; i--) {
		  suf+=arr[i];
		  if(m.find(suf) != m.end() && m[suf] < i) {
		    ans = max(ans, m[suf] + n - i + 1);
      }
    }
    cout << ans << endl;
	}
	return 0;
}
