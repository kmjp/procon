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


int N,M;
int U[555],V[555];
const ll mo=998244353;

ll T[1<<14];
ll P[15][1<<14];
const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];


ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


ll mat[14][14];
ll det_mo(int N) {
	int x,y,z;
	ll ret=1;
	FOR(y,N) FOR(z,N) mat[y][z]=((mat[y][z]%mo)+mo)%mo;
	FOR(x,N) {
		if(mat[x][x]==0) {
			for(y=x+1;y<N;y++) if(mat[y][x]) break;
			if(y==N) return 0;
			FOR(z,N) swap(mat[x][z],mat[y][z]);
		}
		ret=ret*mat[x][x]%mo;
		ll rev=modpow(mat[x][x],mo-2);
		FOR(z,N) mat[x][z]=rev*mat[x][z]%mo;
		for(y=x+1;y<N;y++) if(mat[y][x]) {
			rev=mat[y][x];
			for(z=x;z<N;z++) mat[y][z]=((mat[y][z]-mat[x][z]*rev)%mo+mo)%mo;
		}
	}
	return ret;
}


void solve() {
	int i,j,k,l,r,x,y; string s;

		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>U[i]>>V[i];
		U[i]--,V[i]--;
	}
	
	FOR(i,N) T[1<<i]=1;
	int mask;
	FOR(mask,1<<N) if(__builtin_popcount(mask)>=2) {
		vector<int> cand;
		int rev[14]={};
		x=0;
		FOR(i,N) {
			rev[i]=-1;
			if(mask&(1<<i)) rev[i]=x++;
		}
		ZERO(mat);
		FOR(i,M) {
			if(rev[U[i]]==-1||rev[V[i]]==-1) continue;
			mat[rev[U[i]]][rev[V[i]]]--;
			mat[rev[V[i]]][rev[U[i]]]--;
			mat[rev[U[i]]][rev[U[i]]]++;
			mat[rev[V[i]]][rev[V[i]]]++;
		}
		T[mask]=(det_mo(x-1)%mo+mo)%mo;
	}
	
	P[0][0]=1;
	FOR(i,N) FOR(mask,1<<N) if(P[i][mask]) {
		x=-1;
		FOR(j,N) if((mask&(1<<j))==0) {
			x=j;
			break;
		}
		if(x==-1) continue;
		int cand=((1<<N)-1)^mask^(1<<x);
		for(int sm=cand;sm>=0;sm--) {
			sm&=cand;
			
			int ce=__builtin_popcount(mask)-i;
			int ne=__builtin_popcount(sm);
			
			(P[i+1][mask^(1<<x)^sm]+=P[i][mask]*T[(1<<x)^sm])%=mo;
		}
	}
	
	for(i=1;i<=N-1;i++) {
		ll pat=P[N-i][(1<<N)-1]*fact[i]%mo;
		pat=pat*modpow(modpow(M,i))%mo;
		cout<<pat<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
