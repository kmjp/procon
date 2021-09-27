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
int P[2020];
vector<int> E[2020];
int C[2020],D[2020];
const ll mo=998244353;
ll dp[2020][2020];

const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll pat[2020][2020];

ll comb(ll N_, ll C_) {
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}
ll hcomb(int P_,int Q_) { return (P_==0&&Q_==0)?1:comb(P_+Q_-1,Q_);}

int dfs(int cur,int d) {
	C[cur]=1;
	
	ll from[2020]={};
	from[0]=1;
	// ok
	FORR(e,E[cur]) {
		dfs(e,d+1);
		
		int x,y,z,a,b;
		ll to[2020]={};
		FOR(x,C[cur]+1) FOR(y,C[e]+1) {
			(to[x+y]+=from[x]*dp[e][y])%=mo;
		}
		
		swap(from,to);
		C[cur]+=C[e];
	}
	
	int x;
	FOR(x,C[cur]) {
		(dp[cur][x]+=from[x])%=mo; //safe
		(dp[cur][x+1]+=(C[cur]-(x+1))*from[x])%=mo; // ng
	}
	
	
	return C[cur];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	comb(0,0);
	
	cin>>N;
	FOR(i,N-1) {
		cin>>P[i+1];
		P[i+1]--;
		E[P[i+1]].push_back(i+1);
	}
	
	dfs(0,1);
	
	ll ret=0;
	FOR(i,N) {
		if(i%2==0) (ret+=dp[0][i]*fact[N-i])%=mo;
		else (ret-=dp[0][i]*fact[N-i])%=mo;
	}
	
	cout<<(ret+mo)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
