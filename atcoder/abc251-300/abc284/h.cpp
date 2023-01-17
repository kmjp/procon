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

int N,K;
ll mo;
const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}
ll comb(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}


ll dfs(vector<int>& V,int lef,int nex) {
	if(lef==0) {
		ll a=0;
		
		for(int i=1;i<=K;i++) {
			if((K-i)%2==0) {
				a+=comb(K,i)*modpow(i,V.size())%mo;
			}
			else {
				a-=comb(K,i)*modpow(i,V.size())%mo;
			}
		}
		map<int,int> M;
		FORR(v,V) M[v]++;
		ll pat=1;
		FORR2(a,b,M) pat=pat*factr[b]%mo;
		
		ll sum=0;
		int x,y;
		
		int lef=N;
		FOR(x,V.size()) {
			pat=pat*comb(lef,V[x])%mo*fact[V[x]-1]%mo;
			lef-=V[x];
		}
		
		FOR(x,V.size()) {
			sum+=V[x]/2;
			FOR(y,x) sum+=__gcd(V[x],V[y]);
		}
		return a*modpow(2,sum)%mo*pat%mo;
	}
	ll ret=0;
	for(int i=1;i<=min(lef,nex);i++) {
		V.push_back(i);
		ret+=dfs(V,lef-i,i);
		V.pop_back();
	}
	return ret%mo;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>mo;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;

	vector<int> V;
	ll ret=dfs(V,N,N)%mo;
	ret=ret*factr[N]%mo;
	
	cout<<(ret%mo+mo)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
