#include <bits/stdc++.h>
#define int long long
using namespace std;

int arr[100010],d[1000010],t[1000010],n,maxc=INT_MIN,m,l,r;

int build(int a,int b,int c) {
	maxc=max(maxc,c);
	if(a==b) {
		return d[c]=arr[a];
	}
	int mid=(a+b)>>1;
	return d[c]=build(a,mid,c*2)+build(mid+1,b,c*2+1);
}

/*
int gsum(int l,int r,int s,int t,int p) {
	// [l, r] 为查询区间, [s, t] 为当前节点包含的区间, p 为当前节点的编号
	if(l<=s&&t<=r)
		return d[p];  // 当前区间为询问区间的子集时直接返回当前区间的和
	int m=s+((t-s)>>1),sum=0;
	if(l<=m)
		sum+=gsum(l,r,s,m,p*2);
	// 如果左儿子代表的区间 [s, m] 与询问区间有交集, 则递归查询左儿子
	if(r>m)
		sum+=gsum(l,r,m+1,t,p*2+1);
	// 如果右儿子代表的区间 [m + 1, t] 与询问区间有交集, 则递归查询右儿子
	return sum;
}
*/

int getsum(int l,int r,int s,int t,int p) {
	if(l<=s&&t<=r) {
		return d[p];
	}
	int mid=(s+t)>>1,sum;
	if(l<=mid) {
		sum+=getsum(l,r,s,mid,p*2);
	}
	if(r>mid) {
		sum+=getsum(l,r,mid+1,t,p*2+1);
	}
	return sum;
}

signed main() {
	cin>>n>>m;
	for(int i = 1;i <= n;i++) {
		cin>>arr[i];
	}
	build(1,n,1);
	for(int i = 1;i <= maxc;i++) {
		cout<<d[i]<<' ';
	}
	cout<<endl;
	for(int i = 1;i <= m;i++) {
		cin>>l>>r;
		cout<<getsum(l,r,1,n,1)<<endl;
	}
	return 0;
}
