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

int N,M,X;
ll dp[31][202];
ll F[202],G[202];
const ll mo=998244353;
ll odd[303][303],even[303][303],H[202][202];

const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll comb(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

ll hoge(int N) {
	ZERO(dp);
	dp[30][N]=1;
	int x,y,x2,i;
	
	for(int d=29;d>=0;d--) {
		int xb=(X>>d)&1;
		FOR(x,N+1) {
			ll pat[2]={};
			FOR(y,N-x+1) (pat[y&1]+=comb(N-x,y))%=mo;
			(pat[0]*=dp[d+1][x])%=mo;
			(pat[1]*=dp[d+1][x])%=mo;
			
			if((M>>d)&1) {
				FOR(x2,x+1) (dp[d][x-x2]+=pat[((x-x2)&1)^xb]*comb(x,x2))%=mo;
			}
			else {
				dp[d][x]=pat[xb];
			}
			
		}
	}
	
	ll ret=0;
	FOR(i,N+1) ret+=dp[0][i];
	ret%=mo;
	return ret;
}
ll modpow(ll a, ll n=mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll combs(ll P_,ll Q_) {
	if(P_<0 || Q_<0 || Q_>P_) return 0;
	ll p=1,q=1;
	Q_=min(Q_,P_-Q_);
	for(int i=1;i<=Q_;i++) p=p*P_%mo, q=q*i%mo,P_--;
	
	return p*modpow(q,mo-2)%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;

	cin>>N>>M>>X;
	FOR(i,N+1) F[i]=hoge(i);
	
	odd[0][0]=even[0][0]=1;
	for(i=1;i<=200;i++) for(j=1;j<=i;j++) {
		for(k=1;k<=i;k++) {
			if(k%2) (odd[i][j]+=comb(i-1,k-1)*odd[i-k][j-1])%=mo;
			else (even[i][j]+=comb(i-1,k-1)*even[i-k][j-1])%=mo;
		}
	}
	FOR(x,202) FOR(y,202) {
		ll a=1,b=0;
		FOR(k,x+1) {
			b+=a*even[x][k]%mo;
			a=a*(M+1-y-k)%mo;
		}
		H[x][y]=b%mo;
	}
	
	FOR(x,N+1) {
		G[x]=F[x];
		FOR(i,x+1) {
			ll a=0;
			FOR(j,min(x,i+1)) (a+=odd[i][j]*G[j]%mo*H[x-i][j])%=mo;
			G[x]-=a*comb(x,i)%mo;
		}
		G[x]=(G[x]%mo+mo)%mo;
	}
	
	ll ret=0;
	for(i=0;i*2<=N;i++) {
		ret+=G[N-2*i]*factr[N-2*i]%mo*combs(M+i,i)%mo;
	}
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
