#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N;
int A[402020];
ll mo=3;

ll modpow(ll a, ll n=mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


ll comb(ll N_, ll C_) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factmo[NUM_+1];
	if (fact[0]==0) {
		fact[0]=1;
		for (int i=1;i<=NUM_;++i) {
			int x=i;
			factmo[i]=factmo[i-1];
			while(x%mo==0) factmo[i]++, x/=mo;
			fact[i]=fact[i-1]*x%mo;
		}
	}
	if(C_<0 || C_>N_ || factmo[N_]>factmo[C_]+factmo[N_-C_]) return 0;
	return fact[N_]*modpow(fact[C_]*fact[N_-C_])%mo;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	cin>>s;
	ll ret=0;
	FOR(i,N) {
		if(s[i]=='B') A[i]=0;
		if(s[i]=='W') A[i]=1;
		if(s[i]=='R') A[i]=2;
		
		if(N%2==1) {
			ret+=comb(N-1,i)*A[i];
		}
		else {
			ret-=comb(N-1,i)*A[i];
		}
	
	}
	ret=(ret%3+3)%3;
	cout<<"BWR"[ret]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
