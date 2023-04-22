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

int H,W,K;
ll F[1010][1010];
const ll mo=998244353;
ll comb(ll N_, ll C_) {
	const int NUM_=4000001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	ll ret=0;
	for(y=1;y<=H;y++) {
		for(x=1;x<=W;x++) {
			
			if(y==1) {
				if(x==K) F[y][x]=1;
				if(x>K&&K>=2) F[y][x]=comb(x-2,K-2);
			}
			else if(x==1) {
				if(y==K) F[y][x]=1;
				if(y>K&&K>=2) F[y][x]=comb(y-2,K-2);
			}
			else {
				F[y][x]=comb(y*x,K);
				F[y][x]-=2*comb((y-1)*x,K);
				F[y][x]-=2*comb(y*(x-1),K);
				F[y][x]+=comb((y-2)*x,K);
				F[y][x]+=comb(y*(x-2),K);
				F[y][x]+=4*comb((y-1)*(x-1),K);
				F[y][x]-=2*comb((y-1)*(x-2),K);
				F[y][x]-=2*comb((y-2)*(x-1),K);
				F[y][x]+=comb((y-2)*(x-2),K);
			}
			F[y][x]=(F[y][x]%mo+mo)%mo;
			(ret+=1LL*y*x*(H+1-y)*(W+1-x)%mo*F[y][x])%=mo;
		}
	}
	ret=ret*modpow(comb(H*W,K))%mo;
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
