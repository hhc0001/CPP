#include <bits/stdc++.h>
using namespace std;

int pf[100010],l;
string s;

void prfun(string x) {
	int len=x.size();
	for(int i = 1;i < len;i++) {
		int j=pf[i-1];
		while(j>0&&x[i]!=x[j]) {
			j=pf[j-1];
		}
		if(x[i]==x[j]) {
			j++;
		}
		pf[i]=j;
	}
}

int main() {
	cin>>s;
	l=s.size(),prfun(s);
	for(int i = 0;i < l;i++) {
		cout<<pf[i]<<' ';
	}
	cout<<endl;
	return 0;
}
