//algo:SPEXSLF+mcfx--SPFA
#include <bits/stdc++.h>
using namespace std;

struct edge {
	int to,wei;
};

struct vrt {
	int id,dis;
	friend bool operator <(vrt a,vrt b) {
		return a.dis<b.dis;
	}
};

int n,m,s,a,b,w,sum,spslf,sssp[100010];
bool vis[100010];
vector<edge> g[100010];
deque<vrt> dq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	//freopen("P4779_1.in","r",stdin);
	//freopen("SPEXSLF-SPFA.out","w",stdout);
	cin>>n>>m>>s;
	for(register int i = 1;i <= m;i++) {
		cin>>a>>b>>w;
		sum+=w;
		g[a].push_back((edge){b,w});
	}
	spslf=sqrt(sum);
	fill(sssp,sssp+n+5,INT_MAX);
	dq.push_back((vrt){s,0});
	sssp[s]=0,vis[s]=true;
	while(dq.size()) {
		if(rand()%((dq.size()>>3)+1)==0) {
			sort(dq.begin(),dq.end());
		}
		vrt tmp=dq.front();
		dq.pop_front();
		vis[tmp.id]=false;
		for(register int i = 0;i < g[tmp.id].size();i++) {
			if(sssp[g[tmp.id][i].to]>sssp[tmp.id]+g[tmp.id][i].wei) {
				sssp[g[tmp.id][i].to]=sssp[tmp.id]+g[tmp.id][i].wei;
				if(!vis[g[tmp.id][i].to]) {
					if(sssp[g[tmp.id][i].to]>dq.front().dis+spslf) {
						dq.push_back((vrt){g[tmp.id][i].to,sssp[g[tmp.id][i].to]});
					}
					else {
						dq.push_front((vrt){g[tmp.id][i].to,sssp[g[tmp.id][i].to]});
					}
				}
				vis[g[tmp.id][i].to]=true;
			}
		}
		if(sssp[dq.front().id]>sssp[dq.back().id]+spslf) {
			swap(dq.front(),dq.back());
		}
	}
	for(register int i = 1;i<= n;i++) {
		cout<<sssp[i]<<' ';
	}
	cout<<endl;
	return 0;
}
