#include <bits/stdc++.h>
using namespace std;

int pf[10000010],l;
string p,t,c;

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

void KMP(string tx,string pt) {
	c=pt+'#'+tx;
	prfun(c);
	//for(int i = 1;i < c.size();i++) {
		//cout<<pf[i]<<' ';
	//}
	//cout<<endl;
	int l1=tx.size(),l2=pt.size();
	for(int i = l2 + 1;i <= l1 + l2;i++) {
		if(pf[i]==l2) {
			cout<<i-2*l2+1<<endl;
		}
	}
}

int main() {
	cin>>t>>p;
	l=p.size();
	KMP(t,p);
	for(int i = 0;i < l;i++) {
		cout<<pf[i]<<' ';
	}
	cout<<endl;
	return 0;
}
