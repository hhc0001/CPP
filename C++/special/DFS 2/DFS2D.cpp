#include <bits/stdc++.h>
using namespace std;

int h, w;
int arr[11][11];

int main() {
  cin >> h >> w;
  for(int i = 1; i <= h; i++) {
    for(int j = 1; j <= w; j++) {
      cin >> arr[i][j];
    }
  }
  return 0;
}
