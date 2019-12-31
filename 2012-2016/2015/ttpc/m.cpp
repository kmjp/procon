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

int N,M,C[101010];
vector<int> E[101010];
vector<int> A[101010],B[101010];
int D[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>C[i],D[i]=101010;
	
	FOR(i,M) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	
	queue<int> Q;
	D[0]=0;
	Q.push(0);
	while(Q.size()) {
		int cur = Q.front();
		Q.pop();
		FORR(r,E[cur]) if(D[r]>D[cur]+1) D[r]=D[cur]+1, Q.push(r);
	}
	ll a=0;
	FOR(i,N) if(D[i]%2) a ^= C[i];
	FOR(i,N) FORR(r,E[i]) ((D[r]<D[i])?A[i]:B[i]).push_back(r);
	if(a==0) _P("Second\n");
	else _P("First\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
