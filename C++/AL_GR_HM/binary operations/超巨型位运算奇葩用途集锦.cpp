#include <bits/stdc++.h>
using namespace std;

int a,b;

int binabs(int n) {
	return (n^(n>>31))-(n>>31);
}

int binmax(int a,int b) {
	return (b&((a-b)>>31))|(a&(~(a-b)>>31));
}

int binmin(int a,int b) {//like binmax
	return (a&((a-b)>>31))|(b&(~(a-b)>>31));
}

bool binsmsgn(int x,int y) {//WARNING:NO 0!NO 0!NO 0!
	return (x^y)>=0;
}

void binswapint(int &x,int &y) {
	x^=y^=x^=y;
}

int bingetbit(int n,int p) {
	return (n>>p)&1;
}

int binsetbit0(int n,int p) {
	return n&(~(1<<p));
}

int binsetbit1(int n,int p) {
	return n|(1<<p);
}

int binswapbit(int n,int p) {
	return n^(1<<p);
}

int main() {
	cin>>a>>b;
	binswapint(a,b);
	cout<<a<<' '<<b<<endl;
	return 0;
}
