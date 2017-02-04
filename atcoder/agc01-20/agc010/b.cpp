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
ll A[101010],S;
ll D[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		S+=A[i];
	}
	ll B=1LL*N*(N+1)/2;
	if(S%B) return _P("NO\n");
	ll num=S/B;
	
	A[N]=A[0];
	
	ll tot=0;
	FOR(i,N) {
		ll D=A[i+1]-A[i]+num*(N-1);
		if(D%N) return _P("NO\n");
		ll E=num-D/N;
		if(E<0) return _P("NO\n");
		tot += E;
	}
	if(tot==num) _P("YES\n");
	else  _P("NO\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
