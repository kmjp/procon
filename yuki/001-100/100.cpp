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
int A[100],C[100];
ll used;

bool dfs(int cur) {
	int ne=C[cur];
	
	if(C[ne]!=-1) return C[ne]==A[cur];
	C[ne]=A[cur];
	bool ret=dfs(ne);
	C[ne]=-1;
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N;
	FOR(i,N) cin>>A[i], A[i]--;
	MINUS(C);
	FOR(i,N) if(A[i]==i) C[i]=i, used |= 1LL<<i;
	
	FOR(i,N) if(C[i]==-1) {
		FOR(j,N) if((used & (1LL<<j))==0) {
			if(C[j]!=-1 && C[j]!=A[i]) continue;
			y=C[j];
			C[i]=j;
			C[j]=A[i];
			if(dfs(j)) break;
			C[i]=-1;
			C[j]=y;
		}
		if(C[i]==-1) return _P("No\n");
	}
	return _P("Yes\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
