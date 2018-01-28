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

ll num[1010];
int S;
ll mo=1000000007;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	num[1]=9;
	for(i=2;i<=10;i++) num[i]=num[i-1]*10;
	
	cin>>S;
	ll L,R=1;
	ll tot=1;
	ll NL=10,NR=10,LC=1,RC=1;
	ll ret=0;
	for(L=1;L<100000000;) {
		while(tot<S) {
			R++;
			if(R==NR) NR*=10,RC++;
			tot+=RC;
		}
		if(tot==S) ret++;
		tot-=LC;
		L++;
		if(L==NL) NL*=10,LC++;
	}
	for(i=1;i<=S;i++) {
		L=S/i;
		if(L<=8) continue;
		if(S%i) {
			ret++;
		}
		else {
			(ret+=9*modpow(10,L-1)-i+1+mo)%mo;
		}
	}
	
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
