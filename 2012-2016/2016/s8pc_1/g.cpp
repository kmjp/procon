#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
vector<pair<int,pair<ll,ll>>> E[50];

ll dist[16][1<<16];
ll num[16][1<<16];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	if(N==1) return _P("0 1\n");
	FOR(i,M) {
		ll d,t;
		cin>>x>>y>>d>>t;
		E[x-1].push_back({y-1,{d,t}});
		E[y-1].push_back({x-1,{d,t}});
	}
	memset(dist,0x3f,sizeof(dist));
	dist[0][0]=0;
	num[0][0]=1;
	priority_queue<pair<ll,int> > Q;
	Q.push({0,0});
	
	while(Q.size()) {
		auto r=Q.top();
		Q.pop();
		ll co=-r.first;
		int cur=r.second % 100;
		int mask=r.second / 100;
		if(co!=dist[cur][mask]) continue;
		
		FORR(e,E[cur]) {
			int tar=e.first;
			if(mask&(1<<tar)) continue;
			ll co2=co+e.second.first;
			if(co2>e.second.second) continue;
			if(co2<dist[tar][mask|(1<<tar)]) {
				num[tar][mask|(1<<tar)] = 0;
				dist[tar][mask|(1<<tar)]=co2;
				Q.push({-co2,(mask|(1<<tar))*100+tar});
			}
			if(co2==dist[tar][mask|(1<<tar)]) num[tar][mask|(1<<tar)] += num[cur][mask];
		}
		
	}
	
	if(num[0][(1<<N)-1]==0) return _P("IMPOSSIBLE\n");
	_P("%lld %lld\n",dist[0][(1<<N)-1],num[0][(1<<N)-1]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
