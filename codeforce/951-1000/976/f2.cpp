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

int T,N,K,D;
const ll mo=1000000007;

const int prime_max = 1010101;
vector<int> prime;
int NP,divp[prime_max];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

template<class V> V numprime(V N) {
	if(N<=3) return max((V)0,N-1);
	if(N<=prime_max-100) {
		int x=lower_bound(ALL(prime),N+1)-prime.begin();
		return x;
	}
	
	V sq=sqrt(N)+1;
	static vector<V> small, large;
	small.resize(1+sq,0);
	large.resize(1+sq,0);
	V i,j,p;
	for(i=1;i<=sq;i++) large[i]=N/i-1, small[i]=i-1;
	for(p=2;p<=sq;p++) {
		if(small[p]<=small[p-1]) continue;
		V pc=small[p-1];
		ll q=p*p;
		for(i=1;i<=sq&&N/i>=q;i++) {
			ll ip=1LL*i*p;
			ll cur=(ip<=sq?large[ip]:small[N/ip])-pc;
			(i<=sq?large[i]:small[N/i])-=cur;
		}
		for(i=sq;i>=q;i--) small[i]-=small[i/p]-pc;
	}
	return large[1];
}



ll comb(ll N_, ll C_) {
	const int NUM_=30*200001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}
ll hcomb(ll P_,ll Q_) { return (P_==0&&Q_==0)?1:comb(P_+Q_-1,Q_);}

ll hoge(int N,int cur) {
	if(N<=0) return 0;
	if(prime[cur]>N) return 1;
	
	if(1LL*prime[cur]*prime[cur]>N) {
		ll ret=1+comb(K+D,D)*(numprime(N)-cur);
		return ret%mo;
	}
	
	ll ret=0;
	ll p=1;
	ll c=D;
	while(p<=N) {
		(ret+=hoge(N/(int)p,cur+1)*comb(c,D))%=mo;
		p*=prime[cur];
		c+=K;
	}
	return ret;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	
	cin>>T;
	while(T--) {
		cin>>N>>K>>D;
		cout<<hoge(N,0)<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
