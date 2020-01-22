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
int A[51],B[51];
int M;
int U[21],V[21];
vector<pair<int,ll>> E[51];
ll P[51][51];
ll C[21];

void dfs(int cur,int pre,int id,ll m) {
	P[id][cur]=m;
	FORR(e,E[cur]) if(e.first!=pre) dfs(e.first,cur,id,m|e.second);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>A[i]>>B[i];
		A[i]--;
		B[i]--;
		E[A[i]].push_back({B[i],1LL<<i});
		E[B[i]].push_back({A[i],1LL<<i});
	}
	FOR(i,N) dfs(i,i,i,0);
	
	cin>>M;
	FOR(i,M) {
		cin>>x>>y;
		C[i]=P[x-1][y-1];
	}
	
	ll ret=0;
	int mask;
	FOR(mask,1<<M) {
		ll m=0;
		FOR(i,M) if(mask&(1<<i)) m|=C[i];
		ll pat=1LL<<(N-1-__builtin_popcountll(m));
		if(__builtin_popcount(mask)%2==0) {
			ret+=pat;
		}
		else {
			ret-=pat;
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
