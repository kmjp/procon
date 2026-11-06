#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T,N;
vector<int> E[303030];

int P[21][300005],D[300005];
int L[302020],R[302020],re[302020];
int id;

void dfs(int cur) {
	L[cur]=id++;
	re[L[cur]]=cur;
	FORR(e,E[cur]) if(e!=P[0][cur]) D[e]=D[cur]+1, P[0][e]=cur, dfs(e);
	R[cur]=id;
}

int getpar(int cur,int up) {
	int i;
	FOR(i,20) if(up&(1<<i)) cur=P[i][cur];
	return cur;
}

int in(int a,int b,int v) {
	if((L[a]<L[v]||L[a]>=R[v])&&L[b]>L[v]&&L[b]<R[v]) return 1;
	if((L[b]<L[v]||L[b]>=R[v])&&L[a]>L[v]&&L[a]<R[v]) return 1;
	if(L[a]>L[v]&&L[a]<R[v]&&L[b]>L[v]&&L[b]<R[v]) {
		a=getpar(a,D[a]-D[v]-1);
		b=getpar(b,D[b]-D[v]-1);
		return a!=b;
		
	}
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		FOR(i,N) E[i].clear();
		cin>>N;
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		if(N%2==0) {
			cout<<N+1<<endl;
			continue;
		}
		id=0;
		dfs(0);
		FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
		
		int ret=N;
		// N+1‚ðŽæ‚ê‚é‚©
		FOR(i,N/2) {
			x=N/2;
			y=N-1-i;
			if(in(i,y,x)) ret=N+1;
		}
		//N+2‚ðŽæ‚ê‚é‚©
		for(i=1;i<=N/2;i++) {
			x=0;
			y=N-1-(i-1);
			if(in(i,y,x)) ret=N+2;
		}
		cout<<ret<<endl;
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
