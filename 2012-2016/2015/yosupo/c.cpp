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

int N,K,H;

int L[1001],LF[1001];
int nex[1001][10],val[10];
string S;

void dfs(int cur,int X,ll T) {
	int x;
	if(X>K) {
		_P("Found\n");
		exit(0);
	}
	if(cur>=N) return;
	if(N-cur<K-X-1) return;
	
	if(LF[L[X]]==X) {
		FOR(x,10) if(nex[cur][x]<N) dfs(nex[cur][x]+1,X+1, T | (((ll)x)<<(L[X]*4)));
	}
	else {
		int t=((T>>(L[X]*4))&15);
		if(nex[cur][t]<N) dfs(nex[cur][t]+1,X+1,T);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S;
	if((K&(K+1))!=0) return _P("Not Found\n");
	while(1<<(H+1) <= K) H++;
	
	FOR(i,10) val[i]=N;
	for(i=N-1;i>=0;i--) {
		val[S[i]-'0']=i;
		FOR(j,10) nex[i][j]=val[j];
	}
	
	FOR(i,K) {
		x=i+1;
		while(x%2==0) L[i+1]++, x/=2;
		if(LF[L[i+1]]==0) LF[L[i+1]]=i+1;
	}
	
	dfs(0,1,0);
	_P("Not Found\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
