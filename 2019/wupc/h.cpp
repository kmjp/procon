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

int N,Q;
vector<ll> G[202020];
int X[202020],Y[202020];

set<int> C[202020],ev[202020];
ll ret[202020];
ll mo=1000000007;
vector<ll> cand[202020];
map<pair<int,int>,ll> memo;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		G[i].resize(x);
		cand[i].resize(x);
		FOR(j,x) cin>>G[i][j];
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>X[i]>>Y[i];
		if(X[i]>Y[i]) swap(X[i],Y[i]);
		x=min(G[X[i]].size(),G[Y[i]].size());
		ev[x].insert(i);
		C[x].insert(X[i]);
		C[x].insert(Y[i]);
	}
	
	for(i=1;i<=200000;i++) if(C[i].size()) {
		FORR(c,C[i]) {
			
			FOR(x,i) cand[c][x]=0;
			FOR(x,G[c].size()) cand[c][x%i]+=G[c][x];
			FOR(x,i) cand[c][x]%=mo;
		}
		FORR(e,ev[i]) {
			if(memo.count({X[e],Y[e]})) {
				ret[e]=memo[{X[e],Y[e]}];
			}
			else {
				FOR(j,i) (ret[e]+=cand[X[e]][j]*cand[Y[e]][j])%=mo;
				memo[{X[e],Y[e]}]=ret[e];
			}
		}
	}
	
	FOR(i,Q) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
