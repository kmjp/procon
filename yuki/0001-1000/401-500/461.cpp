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
int P[404040],A[404040],B[404040];
vector<long double> V[3];
ll ret;

void solve() {
	int i,j,k,l,r,x,y; string s;
	long double eps=1e-18;
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i]>>A[i]>>B[i];
		V[P[i]].push_back((long double)1.0*A[i]/(A[i]+B[i]));
	}
	FOR(i,3) sort(ALL(V[i]));
	ll ret=N+1;
	FORR(r,V[0]) {
		FORR(r2,V[1]) if(r+r2>1+eps) ret++;
		FORR(r2,V[2]) if(r+r2>1+eps) ret++;
	}
	FORR(r,V[1]) {
		FORR(r2,V[2]) if(r+r2>1+eps) ret++;
	}
	FORR(r,V[0]) FORR(r2,V[1]) {
		if(r+r2<1-eps) continue;
		long double hoge=1-min(r,r2);
		ret += V[2].end()-lower_bound(ALL(V[2]),hoge-eps);
		hoge=2-(r+r2);
		ret-=lower_bound(ALL(V[2]),hoge+eps)-lower_bound(ALL(V[2]),hoge-eps);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
