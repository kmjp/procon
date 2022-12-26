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

int Q;
ll X[3],Y[3],K;
ll mo=998244353;

ll AP,AQ;
ll BP,BQ;

ll modpow(ll a, ll n=mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll hoge(ll v) {
	if(v<0) return 0;
	return (v+3)*(v+2)%mo*(v+1)%mo*modpow(6)%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		FOR(i,3) cin>>X[i]>>Y[i];
		cin>>K;
		
		AP=X[2]*Y[1]-Y[2]*X[1];
		AQ=X[0]*Y[1]-Y[0]*X[1];
		BP=X[2]*Y[0]-Y[2]*X[0];
		BQ=X[1]*Y[0]-Y[1]*X[0];
		
		if(AQ<0) AP=-AP, AQ=-AQ;
		if(BQ<0) BP=-BP, BQ=-BQ;
		
		ll g=__gcd(abs(AP),abs(AQ));
		AP/=g;
		AQ/=g;
		g=__gcd(abs(BP),abs(BQ));
		BP/=g;
		BQ/=g;
		
		ll AA,BB,CC,G;
		AA=AP*BQ;
		BB=BP*AQ;
		CC=-AQ*BQ;
		
		G=__gcd(abs(AA),__gcd(abs(BB),abs(CC)));
		AA/=G;
		BB/=G;
		CC/=G;
		
		ll ret=hoge(K);
		if(abs(CC)<=K && abs(AA)<=K && abs(BB)<=K) {
			ll C[2]={};
			C[AA>0]+=abs(AA);
			C[BB>0]+=abs(BB);
			C[CC>0]+=abs(CC);
			ret-=hoge(K-max(C[0],C[1]));
		}
		cout<<(ret+mo)%mo<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
