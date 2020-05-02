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
int A[51],B[51],C[51],D[51];
int ma;

int V[11];

void dfs(int id,int v) {
	if(id==N+1) {
		int i,ret=0;
		FOR(i,Q) if(V[B[i]]-V[A[i]]==C[i]) ret+=D[i];
		ma=max(ma,ret);
		
		return;
	}
	
	int i;
	for(i=v;i<=M;i++) {
		V[id]=i;
		dfs(id+1,i);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	FOR(i,Q) {
		cin>>A[i]>>B[i]>>C[i]>>D[i];
	}
	dfs(1,1);
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
