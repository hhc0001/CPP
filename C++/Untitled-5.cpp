#include <bits/stdc++.h>
using namespace std;

const char kC[2] = {'+', '-'};

int n, x, y, nm[2], arr[2][55];
string ans[2];

bool check(int ax) {
}

int main() {
  cin >> n >> x >> y;
  for(int i = 1; i <= n; i++) {
    cin >> arr[0][0];
    arr[i & 1][++nm[i & 1]] = arr[0][0];
    arr[0][0] = 0;
  }
  return 0;
}