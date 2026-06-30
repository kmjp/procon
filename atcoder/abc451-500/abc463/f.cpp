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
int A[404040],V[404040];
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

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

int C[3][3];

map<pair<int,int>,ll> memo;
ll hoge(int R,int M) {
	if(memo.count({R,M})) return memo[{R,M}];
	
	ll ret=0;
	int i;
	FOR(i,M+1) {
		(ret+=comb(M,i)*modpow(1+R+i))%=mo;
	}
	
	return memo[{R,M}]=ret*modpow(modpow(2),M)%mo;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	int ma=0;
	FOR(i,2*N) {
		cin>>A[i];
		ma=max(ma,A[i]);
	}
	
	FOR(i,N) {
		x=0;
		if(A[2*i]==ma-1) x=1;
		if(A[2*i]==ma) x=2;
		y=0;
		if(A[2*i+1]==ma-1) y=1;
		if(A[2*i+1]==ma) y=2;
		V[2*i]=x;
		V[2*i+1]=y;
		
		if(x<y) swap(x,y);
		C[x][y]++;
	}
	
	FOR(i,2*N) {
		C[max(V[i],V[i^1])][min(V[i],V[i^1])]--;
		
		ll ret=0;
		if(A[i]==ma) {
			//Ž©•ª‚ª•‰‚¯‚½ê‡A
			if(V[i^1]!=2) {
				ll lose=modpow(2);
				if(C[2][2]) lose=0;
				int rival=2*C[2][1]+C[2][0]+C[1][1]+(V[i^1]==1);
				(lose*=modpow(modpow(2),C[2][1]+C[2][0]))%=mo;
				(ret+=lose*hoge(rival,C[1][0]))%=mo;
			}
			
			//Ž©•ª‚ªŸ‚Á‚½ê‡
			int rival=C[2][2];
			(ret+=modpow(2)*hoge(rival,C[2][0]+C[2][1]))%=mo;
			
			
		}
		else if(A[i]==ma-1&&C[2][2]==0) {
			//Ž©•ª‚Í‚©‚Â
			ret=modpow(2);
			//ma,ma-1‚ÍŒãŽÒ‘OÍ
			ret=ret*modpow(modpow(2),C[2][1]+C[2][0])%mo;
			//ma-1,ma-1‚Í‚Ç‚Á‚¿‚Å‚à‚æ‚¢
			int rival=2*C[2][1]+C[2][0]+C[1][1]+(V[i^1]==2);
			
			ret=ret*hoge(rival,C[1][0])%mo;
			
		}
		
		cout<<ret<<" ";
		
		
		C[max(V[i],V[i^1])][min(V[i],V[i^1])]++;
		
	}
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
