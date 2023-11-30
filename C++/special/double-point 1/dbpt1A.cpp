#include <bits/stdc++.h>
using namespace std;

int n, arr[1010], l, r, s[2];

int main() {
    cin >> n;
    r = n;
    for(int i = l = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int f = 0;
    for(; l <= r; f ^= 1) {
      if(arr[l] > arr[r]) {
        s[f] += arr[l++];
      }
      else {
        s[f] += arr[r--];
      }
    }
    cout << s[0] << ' ' << s[1] << endl;
    return 0;
}
