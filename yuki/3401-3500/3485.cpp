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

const int prime_max = 10101010;
vector<ll> prime;
int NP,divp[prime_max];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

ll modpow(__int128_t a, ll n, ll mo) {
	__int128_t r=1;
	a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

bool MillerRabin(ll v,int loop=10) {
	ll d=v-1;
	int s=0,i,j;
	if(v<=1) return false;
	if(v==2) return true;
	if(v%2==0) return false;
	while(d%2==0) d/=2,s++;
	
	FOR(i,loop) {
		ll a=abs(rand()*rand()+rand())%(v-2)+1;
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

ll L,R;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	cin>>L>>R;
	for(i=1;i<NP;i++) {
		ll x=prime[i];
		if(x*x*x*x>R) break;
		for(j=i+1;j<NP;j++) {
			ll y=prime[j];
			if(x*x*y*y>R) break;
			ll L2=max((L+(x*x*y-1))/(x*x*y),prime[j+1]);
			ll R2=R/(x*x*y);
			for(ll v=L2;v<=R2;v++) {
				if(MillerRabin(v,10)) {
					cout<<x*x*y*v<<endl;
					return;
				}
			}
		}
	}
	cout<<-1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
