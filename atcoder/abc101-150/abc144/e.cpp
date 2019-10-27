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
ll K;
int A[202020];
int F[202020];

int ok(ll v) {
	ll sum=0;
	int i;
	FOR(i,N) {
		ll ma=v/F[i];
		if(ma<A[i]) sum+=A[i]-ma;
		if(sum>K) return 0;
	}
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	ll S=0;
	FOR(i,N) {
		cin>>A[i];
		S+=A[i];
	}
	FOR(i,N) cin>>F[i];
	
	if(S<=K) return _P("0\n");
	
	sort(A,A+N);
	sort(F,F+N);
	reverse(F,F+N);
	ll mi=1LL<<60;
	for(i=59;i>=0;i--) if(ok(mi-(1LL<<i))) mi-=1LL<<i;
	cout<<mi<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
