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

const int I=0;
const int O=1;
const int T=2;
const int J=3;
const int L=4;
const int S=5;
const int Z=6;
ll A[7];
ll ret;

void solve() {
	int i,j,k,l,r,y; string s;

	FOR(i,7) cin>>A[i];
	
	ll x=min(min(A[J],A[L]),A[I]);
	for(ll v=max(x-10,0LL);v<=x;v++) {
		ll r=v*3;
		r += (A[J]-v)/2*2;
		r += (A[L]-v)/2*2;
		r += (A[I]-v)/2*2;
		ret=max(ret,A[O]+r);
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
