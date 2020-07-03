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

ll N,M;

ll dp(ll a,ll b) {
	if(b==1) return a-1;
	if(a>b) {
		return a/b+1+dp(b,a%b);
	}
	else {
		return 1+dp(b,a);
	}
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M>>N;
	ll g=__gcd(N,M);
	N/=g;
	M/=g;
	
	cout<<dp(M,N)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
