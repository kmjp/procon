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

int N,X;
int A[101010];

ll ret;


void dfs(int L,int R) {
	if(R<=L) return;
	if(L+1==R) {
		if(A[L]*3==X) ret++;
		return;
	}
	int M=(L+R)/2,i;
	dfs(L,M);
	dfs(M,R);
	
	
	map<int,vector<int>> lef,ri;
	int ma=0;
	for(i=M-1;i>=L;i--) {
		ma=max(ma,A[i]);
		lef[A[i]].push_back(ma);
	}
	
	FORR(m,lef) sort(ALL(m.second));
	ma=0;
	int nd=0;
	for(i=M;i<R;i++) {
		if(ma<A[i]) nd=0;
		ma=max(ma,A[i]);
		if(ma==A[i]) nd++;
		ri[A[i]].push_back(ma);
		int D=X-ma-A[i];
		if(lef.count(D)) ret+=1LL*nd*(lower_bound(ALL(lef[D]),ma+1)-lef[D].begin());
	}
	FORR(m,ri) sort(ALL(m.second));
	
	ma=nd=0;
	for(i=M-1;i>=L;i--) {
		if(ma<A[i]) nd=0;
		ma=max(ma,A[i]);
		if(ma==A[i]) nd++;
		int D=X-ma-A[i];
		if(ri.count(D)) ret+=1LL*nd*(lower_bound(ALL(ri[D]),ma+1)-ri[D].begin());
		
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	FOR(i,N) cin>>A[i];
	dfs(0,N);
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
