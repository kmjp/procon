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

ll N,M;
ll A[404040];
ll S[404040];

ll dodo(ll v) {
	int x=lower_bound(A,A+M,v)-A;
	return (S[M]-S[x]-v*(M-x))+(v*x-S[x]);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) cin>>A[i];
	sort(A,A+M);
	FOR(i,M) S[i+1]=S[i]+A[i];
	
	ll ret=1LL<<60;
	for(ll a=1;a*a<=N;a++) if(N%a==0) {
		ret=min(ret,dodo(a));
		ret=min(ret,dodo(N/a));
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
