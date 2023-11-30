#include <bits/stdc++.h>
using namespace std;

int d1[20000020],d2[20000020],l,ans=1;
string s;

void mnc1(string s) {
	int len=s.size();
	for(int i = 0,l = 0,r = -1;i < len;i++) {
		int k=(i>r)? 1:min(d1[l+r-i],r-i+1);
		while(0<=i-k&&i+k<len&&s[i-k]==s[i+k]) {
			k++;
		}
		d1[i]=k--;
		if(i+k>r) {
			l=i-k,r=i+k;
		}
	}
}

void mnc2(string s) {
	int len=s.size();
	for(int i = 0,l = 0,r = -1;i < len;i++) {
		int k=(i>r)? 0:min(d1[l+r-i+1],r-i+1);
		while(0<=i-k-1&&i+k<len&&s[i-k-1]==s[i+k]) {
			k++;
		}
		d2[i]=k--;
		if(i+k>r) {
			l=i-k-1,r=i+k;
		}
	}
}

int main() {
	//freopen("P3805_3.in","r",stdin);
	cin>>s;
	l=s.size();
	mnc1(s),mnc2(s);
	for(int i = 0;i < l;i++) {
		ans=max(ans,d1[i]*2-1);
	}
	for(int i = 0;i < l;i++) {
		ans=max(ans,d2[i]*2);
	}
	cout<<ans<<endl;
	return 0;
}
