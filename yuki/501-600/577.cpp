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
ll N;

const int prime_max = 1000000;
int NP,prime[1000000],divp[prime_max];

void cprime() {
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

ll modpow(__int128_t a, ll n, ll mo) {
	__int128_t r=1;
	a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}
bool MillerRabin(ll v,int loop=50) {
	ll d=v-1;
	int s=0,i,j;
	if(v<=1) return false;
	if(v==2) return true;
	if(v%2==0) return false;
	while(d%2==0) d/=2,s++;
	
	FOR(i,loop) {
		ll a=abs(1LL*rand()*rand()+rand())%(v-2)+1;
		ll r=modpow(a,d,v);
		if(r==1 || r==v-1) continue;
		FOR(j,s) {
			r=modpow(r,2,v);
			if(r==v-1) break;
		}
		if(j==s) return false;
	}
	return true;
}


bool issq(ll v) {
	for(ll a=sqrt(v)-10000;a<=sqrt(v)+10000;a++) {
		if(a*a>v) break;
		if(a*a==v && MillerRabin(a)) return 1;
	}
	return 0;
}

set<ll> S,T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	srand(time(NULL));
	cprime();
	FOR(i,NP) {
		ll a=1;
		while(a*prime[i]/prime[i]==a) {
			a*=prime[i];
			if(a>1000000000000000000LL) break;
			S.insert(a);
			if(i==0) T.insert(a);
		}
	}
	
	cin>>Q;
	while(Q--) {
		cin>>N;
		
		int ok=0;
		if(N<=1000000) {
			FORR(c,S) {
				if(ok) break;
				ll left=N-c;
				if(left<2) break;
				if(S.count(left)) ok=1;
			}
		}
		else if(N%2==0) {
			ok=1;
		}
		else {
			FORR(c,T) {
				if(ok) break;
				ll left=N-c;
				if(left<2) break;
				if(S.count(left) || (left>1000000 && MillerRabin(left)) || (left>1000000000000LL && issq(left))) ok=1;
			}
		}
		
		if(ok) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
