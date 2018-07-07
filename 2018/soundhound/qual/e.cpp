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
vector<pair<int,ll>> E[101010];

ll V[2][2][101010];

void dfs(int id,int st,int cur,ll v) {
	if(V[id][st][cur]==1LL<<60) {
		V[id][st][cur]=v;
		FORR(e,E[cur]) dfs(id,st^1,e.first,e.second-v);
	}
	if(V[id][st][cur]!=v) {
		cout<<0<<endl;
		exit(0);
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	FOR(i,2) FOR(j,2) FOR(x,N) V[i][j][x]=1LL<<60;
	dfs(0,0,0,0);
	dfs(1,0,0,1);
	
	if(V[0][1][0]!=1LL<<60) {
		ll ret=abs(V[0][0][0]-V[0][1][0]);
		FOR(x,N) V[0][0][x]=V[0][1][x]=1LL<<60;
		dfs(0,0,0,ret/2);
		FOR(i,N) if(min(V[0][0][i],V[0][1][i])<=0) {
			cout<<0<<endl;
			return;
		}
		cout<<1<<endl;
	}
	else {
		
		ll L=1,R=1LL<<60;
		for(i=1;i<N;i++) {
			int cur=V[0][0][i]==1LL<<60;
			ll dif=V[1][cur][i]-V[0][cur][i];
			
			if(dif==1) L=max(L,1-V[0][cur][i]);
			if(dif==-1) R=min(R,V[0][cur][i]-1);
		}
		cout<<max(0LL,R-L+1)<<endl;
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
