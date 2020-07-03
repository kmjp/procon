#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int L[101],S[101];
int vis[101],done[101];

int dfs(int cur,int tar) {
	int x;
	if(done[S[cur]]) return -1;
	if(cur==tar) return tar;
	if(vis[S[cur]]) return -1;
	
	vis[cur]=1;
	x = dfs(S[cur],tar);
	
	if(x<0) return -1;
	if(L[cur]<L[x]) return cur;
	return x;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>L[i]>>S[i], L[i]*=2, S[i]--;
	
	int ret=0;
	FOR(i,N) if(done[i]==0) {
		ZERO(vis);
		x=dfs(S[i],i);
		if(x>=0) ret += L[x], done[x]=1;
	}
	FOR(i,N) FOR(j,N) if(done[S[j]] && done[j]==0) done[j]=1, ret+=L[j]/2;
	
	_P("%.1lf\n",ret*0.5);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
