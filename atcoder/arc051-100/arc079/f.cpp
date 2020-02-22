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

int N;
int R[202020];
int G[202020];
set<int> S[202020];
int in[202020];

int dfs(int cur,int tar,int cand,int pre,int fir) {
	int hoge=0;
	while(S[cur].count(hoge) || hoge==cand) hoge++;
	if(R[cur]==tar) return (pre==-1 || pre==hoge) && (hoge!=fir);
	return dfs(R[cur],tar,hoge,pre,fir);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		in[x-1]++;
		R[i]=x-1;
	}
	MINUS(G);
	
	queue<int> Q;
	FOR(i,N) if(in[i]==0) Q.push(i);
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		G[x]=0;
		while(S[x].count(G[x])) G[x]++;
		
		y=R[x];
		in[y]--;
		S[y].insert(G[x]);
		if(in[y]==0) Q.push(y);
	}
	
	FOR(i,N) if(G[i]==-1) {
		int cand=0,pre=-1;
		for(j=0;cand<2;j++) {
			if(S[i].count(j)) continue;
			if(dfs(R[i],i,j,pre,j)) return _P("POSSIBLE\n");
			
			pre=j;
			cand++;
		}
	}
	_P("IMPOSSIBLE\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
