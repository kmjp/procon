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
vector<int> E[202020];
vector<int> C[202020];
int P[202020];
int vis[202020];
int NC[202020];
int PA[202020];
int le[202020];

int dfs(int cur,int par) {
	vis[cur]=1;
	P[cur]=par;
	NC[cur]=1;
	FORR(e,E[cur]) if(vis[e]==0) {
		NC[cur]+=dfs(e,cur);
		C[cur].push_back(e);
	}
	return NC[cur];
}

int dfs2(int cur) {
	int ano=-1;
	
	FORR(e,C[cur]) {
		dfs2(e);
		if(le[e]>=0) {
			if(ano>=0) {
				PA[ano]=le[e];
				PA[le[e]]=ano;
				ano=-1;
			}
			else {
				ano=le[e];
			}
		}
	}
	
	if(ano==-1) {
		le[cur]=cur;
	}
	else {
		PA[cur]=ano;
		PA[ano]=cur;
		le[cur]=-1;
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	dfs(0,0);
	
	dfs2(0);
	if(le[0]==0) {
		x=C[0][0];
		y=PA[x];
		PA[0]=x;
		PA[x]=y;
		PA[y]=0;
	}
	FOR(i,N) cout<<PA[i]+1<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
