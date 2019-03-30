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
int A[101010],B[101010],D[101010];
vector<pair<int,ll>> E[101010];
vector<pair<int,ll>> E2[101010];
int vis[101010];
int NV[101010];

ll st[101010],en[101010],C[101010],X[101010];

ll dp[70707];
ll tobe[70707];

int dfs(int cur,int pre) {
	NV[cur]=1;
	FORR(e,E[cur]) if(e.first!=pre && vis[e.first]==0) NV[cur]+=dfs(e.first,cur);
	return NV[cur];
}

int dfs2(int cur,int pre,int TNV) {
	int tot=1;
	int ok=1;
	FORR(e,E[cur]) if(e.first!=pre && vis[e.first]==0) {
		int c = dfs2(e.first,cur,TNV);
		if(c!=-1) return c;
		tot += NV[e.first];
		if(NV[e.first]*2>TNV) ok=0;
	}
	if((TNV-tot)*2>TNV) ok=0;
	if(ok) return cur;
	return -1;
}

int dfs3(int cur,int pre,int base,ll d) {
	E2[cur].push_back({base,d});
	FORR(e,E[cur]) if(e.first!=pre && vis[e.first]==0) dfs3(e.first,cur,base,d+e.second);
}

void split(int cur) {
	int TNV = dfs(cur,-1);
	int center=dfs2(cur,-1,TNV);
	dfs3(center,-1,center,0);
	vis[center]=1;
	FORR(e,E[center]) if(vis[e.first]==0) split(e.first);
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N-1) {
		cin>>x>>y>>r;
		x--;
		y--;
		E[x].push_back({y,r});
		E[y].push_back({x,r});
	}
	
	split(0);
	
	vector<vector<ll>> ev;
	FOR(i,M) {
		cin>>st[i]>>en[i]>>C[i]>>X[i];
		C[i]--;
		
		FORR(e,E2[C[i]]) {
			ev.push_back({(int)st[i]-(int)e.second,1,e.first,i});
			ev.push_back({(int)en[i]+(int)e.second,0,e.first,i});
		}
	}
	sort(ALL(ev));
	ll ret=0;
	FORR(e,ev) {
		if(e[1]==1) {
			tobe[e[3]]=max(tobe[e[3]],dp[e[2]]+X[e[3]]);
		}
		else {
			dp[e[2]]=max(dp[e[2]],tobe[e[3]]);
			ret=max(ret,dp[e[2]]);
		}
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
