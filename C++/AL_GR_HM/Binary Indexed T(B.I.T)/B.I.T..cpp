#include <bits/stdc++.h>
using namespace std;

int n,m,l,r,arr[500050],trr[500050],tmp[500050];

inline int lowbit(int x) {
	return x&-x;
}

void init() {
	for(int i = 1;i <= n;i++) {
		trr[i]+=arr[i];
		int l=i+lowbit(i);
		if(l<=n) {
			trr[l]+=trr[i];
		}
	}
}

int query(int x) {
	int tmp=0;
	while(x!=0) {
		tmp+=trr[x];
		x-=lowbit(x);
	}
	return tmp;
}

int pt_set(int x,int p) {
	
}

int main() {
	cin>>n>>m;
	for(int i = 1;i <= n;i++) {
		cin>>arr[i];
	}
	init();
	//for(int i = 1;i <= n;i++) {
		//cout<<trr[i]<<' ';
	//}
	//cout<<endl;
	for(int i = 1;i <= m;i++) {
		cin>>l>>r;
		//cout<<query(r)-query(l-1)<<endl;
	}
	return 0;
}
