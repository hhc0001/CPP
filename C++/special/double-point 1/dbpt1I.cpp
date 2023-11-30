#include <bits/stdc++.h>
using namespace std;

int t, n, arr[2020];

int main() {
	for(cin >> t; t--;) {
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		int ans = n, tmp = 0;
		for(int i = 1; i < n; i++) {
			tmp += arr[i];
			int cnt = 0, ant = 1, tns = i, pos = 0;
			for(int j = i + 1; j <= n; j++) {
			  if(cnt > tmp) {
			    ant = 0;
			    break;
        }
        if(cnt == tmp) {
          cnt = arr[j], tns = max(tns, pos), pos = 1;
        }
        else {
          cnt += arr[j], pos++;
        }
        //cout << j << ' ' << cnt << ' ' << pos << endl;
      }
      ant = ant && (cnt == tmp), tns = max(tns, pos);
      if(ant) {
        ans = min(ans, tns);
      }
      //cout << i << ' ' << ans << endl;
		}
		cout << ans << endl;
	}
	return 0;
}
