#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,S,T;
int D[101000][2];
vector<int> E[101000];

void dfs(int cur,int pre,int type) {
	if(pre!=-1) D[cur][type]=D[pre][type]+1;
	FORR(r,E[cur]) if(r!=pre) dfs(r,cur,type);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>T;
	S--,T--;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(S,-1,0);
	dfs(T,-1,1);
	
	int mi=1<<20;
	FOR(i,N) if(E[i].size()>=3) {
		if(D[i][0]+D[i][1]==D[T][0] && D[i][0] && D[i][1]) mi=min(mi,2*D[T][0]+2);
		else mi=min(mi,2*(D[i][0]+D[i][1])+4);
	}
	if(mi>=1<<20) mi=-1;
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
