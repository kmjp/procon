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


ll N,K;
ll A[202020];
ll X[202020];
ll Y[202020];
ll Z[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>A[i];
	FOR(i,N) {
		if(i) X[i]+=X[i-1], Y[i]+=Y[i-1], Z[i]+=Z[i-1];
		A[i]-=X[i]*i*i+Y[i]*i+Z[i];
		
		if(A[i]<0) return _P("No\n");
		if(A[i]==0) continue;
		if(A[i]>10000000000000LL/K/K+1) return _P("No\n");
		if(i+2*K-1>N) return _P("No\n");
		X[i]+=A[i];
		Y[i]+=A[i]*(-2*(i-1));
		Z[i]+=A[i]*(i-1)*(i-1);
		Y[i+K]-=A[i]*(-2*(i-1));
		Z[i+K]-=A[i]*(i-1)*(i-1);
		Y[i+K]+=A[i]*(-2*(i+2*K-1));
		Z[i+K]+=A[i]*(i+2*K-1)*(i+2*K-1);
		X[i+2*K-1]-=A[i];
		Y[i+2*K-1]-=A[i]*(-2*(i+2*K-1));
		Z[i+2*K-1]-=A[i]*(i+2*K-1)*(i+2*K-1);
	}
	cout<<"Yes"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
