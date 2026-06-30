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

int T;
const ll mo=998244353;
int N[202020],X[202020];
ll ret[202020],add[202020];
const int DI=450;

vector<pair<int,int>> ev[DI];
ll p2[402020],r2[402020];

ll comb(ll N_, ll C_) {
	const int NUM_=400001;
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
	
	p2[0]=r2[0]=1;
	r2[1]=modpow(2);
	FOR(i,201010) {
		p2[i+1]=p2[i]*2%mo;
		r2[i+2]=r2[i+1]*r2[1]%mo;
	}
	
	cin>>T;
	FOR(i,T) {
		cin>>N[i]>>X[i];
		X[i]=abs(X[i]);
		if(X[i]>=N[i]) {
			ret[i]=X[i];
		}
		else {
			ev[N[i]/DI].push_back({X[i],i});
		}
	}
	
	int CN=0,CM=0;
	ll F=0,G=0;
	FOR(i,DI) {
		sort(ALL(ev[i]));
		FORR2(x,e,ev[i]) {
			int M=(N[e]+X[e]+1)/2;
			while(CM<M) {
				(F+=comb(CN,CM))%=mo;
				(G+=CM*comb(CN,CM))%=mo;
				CM++;
			}
			while(M<CM) {
				CM--;
				(F+=mo-comb(CN,CM))%=mo;
				(G+=mo-CM*comb(CN,CM)%mo)%=mo;
			}
			while(CN<N[e]) {
				G=(mo+2*G+F-M*comb(CN,CM-1)%mo)%mo;
				F=(mo+2*F-comb(CN,CM-1))%mo;
				CN++;
			}
			while(N[e]<CN) {
				CN--;
				F=(F+comb(CN,CM-1))%mo*r2[1]%mo;
				G=(mo+G-F+CM*comb(CN,CM-1)%mo)*r2[1]%mo;
			}
			
			ret[e]=mo-X[e]+(mo+(N[e]+X[e])*F-2*G)%mo*r2[N[e]-1]%mo;
			ret[e]=(ret[e]%mo+mo)%mo;
		}
		
	}
	FOR(i,T) {
		cout<<ret[i]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
