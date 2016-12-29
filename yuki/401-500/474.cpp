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



int T;
int num2[(1<<22)+100000];
int A,B,C;

ll mo=1<<21;
ll fact[(1<<22)+500000];
ll modpow(ll a, ll n, ll mo) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


ll combi(int N_, int C_) {
	
	int x = num2[N_]-num2[N_-C_]-num2[C_];
	if(x>=21) return 1LL<<21;
	ll ret=1LL<<x;
	ret = ret * fact[N_] % mo;
	ret = ret * modpow(fact[C_],mo/2-1,mo) % mo;
	ret = ret * modpow(fact[N_-C_],mo/2-1,mo) % mo;
	return ret;
}
ll hcomb(int P_,int Q_) { return (P_==0&&Q_==0)?1:combi(P_+Q_-1,Q_);}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	fact[0]=1;
	FOR(i,(1<<22)+50000) {
		fact[i+1]=fact[i]*(i+1);
		num2[i+1]=num2[i];
		while(fact[i+1]%2==0) num2[i+1]++, fact[i+1]/=2;
		fact[i+1]%=(1<<21);
	}
	
	cin>>T;
	FOR(i,T) {
		cin>>A>>B>>C;
		auto k=hcomb(C,B);
		if(C%2==0 || k%(1<<21)==0) {
			_P("0\n");
			continue;
		}
		_P("%lld\n",(hcomb(C*k % (1<<21),A)%2));
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
