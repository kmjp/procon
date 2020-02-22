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

ll N,S;

ll f(ll b,ll n) {
	if(n<b) return n;
	return f(b,n/b)+(n%b);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	if(S>N) return _P("-1\n");
	if(N==S) return _P("%lld\n",N+1);
	set<ll> SS;
	for(ll b=2;b*b<=N;b++) if(f(b,N)==S) SS.insert(b);
	
	for(ll p=1;p*p<N && p<=S;p++) {
		ll m=S-p;
		if(N-m>=0 && (N-m)%p==0) {
			ll b=(N-m)/p;
			if(b>p && b>m) SS.insert((N-m)/p);
		}
		
	}
	
	if(SS.size()) return _P("%lld\n",*SS.begin());
	return _P("-1\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
