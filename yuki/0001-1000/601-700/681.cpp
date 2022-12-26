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

ll N,B,D;
ll H[35],num[35];
ll mo=1000000007;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll hoge(ll B,ll N) {
	if(N==0) return 0;
	ll ret=0;
	if(N>H[B-1]) {
		ret+=(N/(H[B-1]+1))*(B+num[B-1]);
		N%=(H[B-1]+1);
	}
	return (ret+hoge(B-1,N))%mo;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>B>>D;
	
	ll tot=((modpow(D+1,B+1)+mo-1)*modpow(D)%mo+mo-(B+1))%mo;
	
	for(B=1;B<=32;B++) {
		if(H[B-1]>1<<30) break;
		H[B]=H[B-1]*(D+1)+D;
		num[B]=(B*D+num[B-1]*(D+1))%mo;
	}
	
	cout<<(tot+mo-hoge(B,N))%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
