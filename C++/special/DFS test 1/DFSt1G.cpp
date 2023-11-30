#include <bits/stdc++.h>
using namespace std;

int n, cnt;
vector<int> ans[11];

int main() {
  cin >> n;
  if(n > 30) {
    cout << 0 << '\n';
    goto GG;
  }
  for(int i1 = 1; i1 <= 3; i1++) {
    for(int i2 = 1; i2 <= 3; i2++) {
      for(int i3 = 1; i3 <= 3; i3++) {
        for(int i4 = 1; i4 <= 3; i4++) {
          for(int i5 = 1; i5 <= 3; i5++) {
            for(int i6 = 1; i6 <= 3; i6++) {
              for(int i7 = 1; i7 <= 3; i7++) {
                for(int i8 = 1; i8 <= 3; i8++) {
                  for(int i9 = 1; i9 <= 3; i9++) {
                    for(int iX = 1; iX <= 3; iX++) {
                      if(i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9 + iX == n) {
                        cnt++;
                        ans[1].push_back(i1);
                        ans[2].push_back(i2);
                        ans[3].push_back(i3);
                        ans[4].push_back(i4);
                        ans[5].push_back(i5);
                        ans[6].push_back(i6);
                        ans[7].push_back(i7);
                        ans[8].push_back(i8);
                        ans[9].push_back(i9);
                        ans[10].push_back(iX);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  cout << cnt << '\n';
  for(int i = 0; i < ans[1].size(); i++) {
    cout << ans[1][i] << ' ' << ans[2][i] << ' ' << ans[3][i] << ' ' << ans[4][i] << ' ' << ans[5][i] << ' ' << ans[6][i] << ' ' << ans[7][i] << ' ' << ans[8][i] << ' ' << ans[9][i] << ' ' << ans[10][i] << '\n';
  }
  GG:
  return 0;
}