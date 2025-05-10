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

int N,Q;
int A[252525];
const ll mo=998244353;

const int NUM_=2000003;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];



ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

const int DI=520;
vector<pair<int,int>> ev[DI];

int L[252525],R[252525],X[252525];
ll ret[252525];

int C[252525];
ll BC[DI];
ll BF[DI];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	cin>>N>>Q;
	FOR(i,N) cin>>A[i];
	
	FOR(i,Q) {
		cin>>L[i]>>R[i]>>X[i];
		L[i]--;
		ev[L[i]/DI].push_back({R[i],i});
	}
	
	FOR(i,DI) {
		FOR(j,N+1) C[j]=0;
		FOR(j,DI) {
			BC[j]=0;
			BF[j]=1;
		}
		
		int CL=DI*i,CR=DI*i;
		sort(ALL(ev[i]));
		FORR2(r,e,ev[i]) {
			int l=L[e];
			while(CR<r) {
				x=A[CR++];
				(BF[x/DI]*=inv[++C[x]])%=mo;
				BC[x/DI]++;
			}
			while(l<CL) {
				x=A[--CL];
				(BF[x/DI]*=inv[++C[x]])%=mo;
				BC[x/DI]++;
			}
			while(CL<l) {
				x=A[CL++];
				(BF[x/DI]*=C[x]--)%=mo;
				BC[x/DI]--;
			}
			
			ret[e]=1;
			x=0;
			y=0;
			while(x+DI<X[e]) {
				y+=BC[x/DI];
				(ret[e]*=BF[x/DI])%=mo;
				x+=DI;
			}
			while(x<X[e]) {
				y+=C[x];
				(ret[e]*=factr[C[x]])%=mo;
				x++;
			}
			(ret[e]*=fact[y])%=mo;
			
		}
		
		
	}
	
	FOR(i,Q) cout<<ret[i]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
