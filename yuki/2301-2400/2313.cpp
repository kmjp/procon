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
ll K;
vector<ll> D;
const int mo=998244353;
ll from[1515],to[1515];
int num[1515];
int nex[1515][1515];

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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	for(j=1;j*j<=K;j++) if(K%j==0) {
		D.push_back(j);
		if(j*j!=K) D.push_back(K/j);
	}
	
	sort(ALL(D));
	map<int,int> M;
	FOR(i,D.size()) M[D[i]]=i;
	
	FOR(i,D.size()) FOR(j,D.size()) nex[i][j]=M[__gcd(K,D[i]*D[j])];
	
	FOR(i,N) {
		ll a;
		cin>>a;
		num[M[__gcd((ll)K,a)]]++;
		
	}
	
	from[0]=1;
	FOR(i,D.size()) {
		ZERO(to);
		ll pat=1;
		FOR(j,num[i]) pat=pat*2%mo;
		ll a=1;
		for(j=0;j<=min(num[i],30);j++) {
			int b=M[a];
			ll p=comb(num[i],j);
			pat+=mo-p;
			FOR(x,D.size()) (to[nex[x][b]]+=p*from[x])%=mo;
			a=__gcd(K,a*D[i]);
		}
		a=__gcd(K,a*D[i]);
		int b=M[a];
		pat%=mo;
		FOR(x,D.size()) (to[nex[x][b]]+=pat*from[x])%=mo;
		swap(from,to);
	}
	
	cout<<from[D.size()-1]-(K==1)<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
