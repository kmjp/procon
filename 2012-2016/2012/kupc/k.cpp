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

int N,M,Q;
vector<pair<int,ll>> E[101010];
ll D[202020];
vector<ll> cand;

template<class C> int gf2_rank(vector<C>& V) { /* input */
	int i,j;
	int N=V.size();
	FOR(i,N) {
		int x=max_element(V.begin()+i,V.end())-V.begin();
		if(V[x]==0) break;
		swap(V[i],V[x]);
		C msb=1;
		while(msb<<1 <= V[i]) msb<<=1;
		FOR(j,N) if(j!=i) if(V[j]&msb) V[j]^=V[i];
	}
	return N-count(V.begin(),V.end(),0);
}

void dfs(int cur,ll v) {
	if(D[cur]!=-1) {
		if(D[cur]!=v) cand.push_back(v^D[cur]);
		return;
	}
	
	D[cur]=v;
	FORR(e,E[cur]) dfs(e.first,v^e.second);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	FOR(i,M) {
		ll v;
		cin>>x>>y>>v;
		E[x].push_back({y,v});
		E[y].push_back({x,v});
	}
	MINUS(D);
	dfs(0,0);
	
	x=gf2_rank(cand);
	cand.resize(x);
	
	FOR(i,Q) {
		cin>>x>>y;
		ll v=D[x]^D[y];
		FORR(c,cand) v=max(v,v^c);
		cout<<v<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
