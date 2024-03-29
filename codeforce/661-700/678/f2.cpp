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


int M;
ll F[101010];
ll V[101010];
const ll mo=998244353;
ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M;
	FOR(i,M) {
		cin>>x>>y;
		V[x]=y;
	}
	
	for(i=100000;i>=1;i--) {
		ll S1=0,S2=0,N=0;
		for(j=i;j<=100000;j+=i) {
			N+=V[j];
			(S1+=V[j]*j)%=mo;
			(S2+=V[j]*j%mo*j)%=mo;
		}
		
		if(N>=2) {
			F[i]+=S2*((N-1)%mo)%mo*modpow(2,N-2);
			ll v=(S1*S1%mo+mo-S2)%mo;
			F[i]+=v*modpow(2,N-2);
			if(N>=3) F[i]+=v*((N-2)%mo)%mo*modpow(2,N-3);
			
		}
		F[i]%=mo;
		
		
		for(j=i*2;j<=100000;j+=i) F[i]-=F[j];
		F[i]=(F[i]%mo+mo)%mo;
	}
	cout<<F[1]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
