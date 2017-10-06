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

ll N,M;

map<ll,int> enumpr(ll n) {
	map<ll,int> V;
	for(ll i=2;i*i<=n;i++) while(n%i==0) V[i]++,n/=i;
	if(n>1) V[n]++;
	return V;
}

ll numdiv(ll a,ll B) {
	ll ret=0;
	while(B>=a) {
		ret+=B/a;
		B/=a;
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	auto A=enumpr(M);
	ll ma=1LL<<60;
	FORR(a,A) {
		ma=min(ma,numdiv(a.first,N)/a.second);
	}
	
	double a=0;
	if(N>100000) {
		a=N*(log(N)-1)+log(sqrt(2*N*atan(1)*4));
	}
	else {
		for(i=N;i>=1;i--) a+=log(i);
	}
	a -= ma*log(M);
	
	double c=a/log(10);
	double P=c-floor(c);
	double Q=floor(c)+0.5;
	_P("%.12lfe%lld\n",exp(P*log(10)),(ll)Q);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
