#include <bits/stdc++.h>
using namespace std;

int r, c;
bool cal[20][20];
string s, arr[20][20];

string ToUpper(string &x) {
  for(int i = 0; i < x.size(); i++) {
    if(x[i] >= 'a' && x[i] <= 'z') {
      x[i] -= 'a' - 'A';
    }
  }
  return x;
}

pair<bool, int> IsNumber(string x) {
  int ans = 0;
  for(int i = 0; i < x.size(); i++) {
    if(isdigit(x[i])) {
      ans = ans * 10 + x[i] - '0';
    }else {
      return {0, 0};
    }
  }
  return {1, ans};
}

pair<vector<pair<int, int> >, vector<int> > Range(string s) {
  for(int i = 0; i < s.size(); i++) {
  }
}

void Calculate(string s, int x, int y) {
  int p = 0, f = 1;
  while(s[p++] != '(') {
  }
  string t = "";
  while(s[p] != ')') {
    t = t + s[p];
  }
  if(p + 1 != s.size()) {
    cal[x][y] = 1, arr[x][y] = "#SYN#";
    return ;
  }
}

//Process the string s
void Process(string s) {
  s += " ";
  ToUpper(s);
  int p = 0;
  //New row
  if(s[0] == 'R') {
    if(isdigit(s[2])) {
      r = 10, p = 4;
    }else {
      r = s[1] - '0', p = 3;
    }
    c = 1;
  }
  string t = "";
  for(; p < s.size(); p++) {
    if(s[p] != ' ') {
      t += s[p];
    }else {
      if(t == "B" || IsNumber(t).first) {
        cal[r][c] = 1;
      }
      arr[r][c++] = t == "B"? "     " : t;
      t = "";
    }
  }
}

void MainTain() {
  for(int i = 1; i <= 10; i++) {
    for(int j = 1; j <= 10; j++) {
      while(arr[i][j].size() < 5) {
        arr[i][j] = " " + arr[i][j];
      }
    }
  }
}

int main() {
  getline(cin, s);
  while(s != "") {
    Process(s);
    getline(cin, s);
  }
  MainTain();
  cout << "         A    B    C    D    E    F    G    H    I    J" << '\n';
  for(int i = 1; i <= 10; i++) {
    if(i < 10) {
      cout << ' ';
    }
    cout << "   " << i;
    for(int j = 1; j <= 10; j++) {
      cout << arr[i][j];
    }
    cout << '\n';
  }
  return 0;
}
