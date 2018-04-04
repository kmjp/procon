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

int T,N;
ll mo=1000000007;
ll C[111010];
ll CS[111010];
ll fact[111010];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll Q1(int T,ll N) {
	return N*N;
}
ll Q2(int T,ll N) {
	return N*N*N+N*N-N;
}
ll Q3(int T,ll N) {
	return T;
}
ll Q4(int T,ll N) {
	return 4*N*N+17;
}
ll Q5(int T,ll N) {
	return modpow(N,N*N*N);
}
ll Q6(int T,ll N) {
	return N;
}
ll Q7(int T,ll N) {
	return fact[N]*CS[N]%mo;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	ll S=0;
	fact[0]=fact[1]=1;
	for(i=2;i<=110000;i++) {
		C[i]=(S*modpow(i-1)+1)%mo;
		(S+=C[i])%=mo;
		(CS[i]=CS[i-1]+C[i])%=mo;
		fact[i]=fact[i-1]*i%mo;
	}
	
	cin>>T;
	for(i=1;i<=T;i++) {
		cin>>N;
		cout<<Q1(T,N)<<endl;
		cout<<Q2(T,N)<<endl;
		cout<<Q3(T,N)<<endl;
		cout<<Q4(T,N)<<endl;
		cout<<Q5(T,N)<<endl;
		cout<<Q6(T,N)<<endl;
		cout<<Q7(T,N)<<endl;
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
