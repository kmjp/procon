#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int A[1<<18];
ll SA[1<<18],E[1<<18];
ll S;
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,1<<N) {
		cin>>A[i];
		S+=A[i];
	}
	FOR(i,1<<N) {
		SA[i]=A[i]*modpow(S)%mo;
	}
	FOR(i,N) {
		FOR(j,1<<N) if(j&(1<<i)) (SA[j]+=SA[j^(1<<i)])%=mo;
	}
	ll ret=0;
	for(i=1;i<1<<N;i++) {
		E[i]=modpow(1+mo-SA[((1<<N)-1)^i]);
		if(__builtin_popcount(i)%2==0) {
			ret-=E[i];
		}
		else {
			ret+=E[i];
		}
	}
	
	cout<<(ret%mo+mo)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
