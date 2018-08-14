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
vector<int> E[303],RE[303];
int A[100000],B[100000],R[100000];
int P[303];
ll D[303];
vector<int> V, LP;
map<pair<int,int>,int> mp;
int NG;

void dfs(int cur,ll v) {
	if(LP.size()) return;
	if(D[cur]!=1LL<<50) {
		if(D[cur]!=v) {
			int i;
			for(i=P[cur];i<V.size()-1;i++) LP.push_back(mp[{V[i],V[i+1]}]);
			LP.push_back(mp[{V.back(),cur}]);
			return;
		}
		return;
	}
	D[cur]=v;
	P[cur]=V.size();
	V.push_back(cur);
	FORR(e,E[cur]) dfs(B[e],v+R[e]);
	V.pop_back();
}

int dfs2(int cur,ll v) {
	if(D[cur]!=1LL<<50) {
		return D[cur]!=v;
	}
	D[cur]=v;
	FORR(e,E[cur]) if(e!=NG) {
		if(dfs2(B[e],v+R[e])) return 1;
	}
	FORR(e,RE[cur]) if(e!=NG) {
		if(dfs2(A[e],v-R[e])) return 1;
	}
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>A[i]>>B[i]>>R[i];
		A[i]--;
		B[i]--;
		E[A[i]].push_back(i);
		RE[B[i]].push_back(i);
		mp[{A[i],B[i]}]=i;
	}
	
	FOR(i,N) D[i]=1LL<<50;
	dfs(0,0);
	
	if(LP.empty()) return _P("Yes\n");
	FORR(v,LP) {
		NG=v;
		FOR(x,N) D[x]=1LL<<50;
		if(dfs2(0,0)==0) return _P("Yes\n");
	}
	_P("No\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
