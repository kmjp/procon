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


int P;
int A[3030];
ll from[3030],to[3030],B[3030];
ll mo;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>P;
	mo=P;
	
	FOR(i,P) cin>>A[i];
	
	from[0]=1;
	FOR(i,P) {
		ZERO(to);
		FOR(j,3000) to[j+1]=from[j];
		FOR(j,3000) to[j]=(to[j]+P-i*from[j]%P)%P;
		swap(from,to);
	}
	
	
	for(i=0;i<P;i++) if(A[i]) {
		ll Q=1;
		for(j=0;j<P;j++) if(j!=i) Q=Q*(i-j)%mo;
		Q=modpow((Q%mo+mo)%mo);
		
		memmove(to,from,sizeof(from));
		for(j=3000;j>=1;j--) {
			(B[j-1]+=to[j]*Q)%=mo;
			to[j-1]=(to[j-1]+to[j]*i)%mo;
		}
		
	}
	FOR(i,P) cout<<B[i]%P<<" ";
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
