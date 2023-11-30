#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

const ll kMod=998244353;

ll f[]={0,9,99,999,9999,99999,999999,9999999,99999999,999999999,9999999999,99999999999,999999999999,9999999999999,99999999999999,999999999999999,9999999999999999,99999999999999999};
ll n,l,ans;

ll len(ll n) {
	int ans=0;
	for(;n;n /= 10,++ans) {
	}
	return ans;
}

ll sum(ll x) {
	return (1+x)*x/2;
}

ll pow(ll x, ll y) {
	for(;y > 1;--y,x *= x) {
	}
	return x;
}

int main() {
	cin>>n;
	l=len(n);
	for(ll i = 1;i < l;++i) {
		ans+=sum(f[i]-ll(pow(10,i-1))+1);
		ans%=kMod;
	}
	ll t=n%ll(pow(10,l-1))+1,x=1;
	for (;n / x;x *= 10) {
	}
	x/=10;
	ans+=sum(t+n/x*x-f[l-1]-1);
	ans%=kMod;
	cout<<ans<<'\n';
	return 0;
}
