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
const ll mo=998244353;
vector<int> E[3030];
int C[3030];

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

ll dp[3050][3050];


void dfs(int cur,int pre) {
	ll from[3030]={};
	from[0]=1;
	C[cur]=1;
	int i,x,y;
	
	FORR(e,E[cur]) if(e!=pre) {
		ll to[3030]={};
		dfs(e,cur);
		ll DS[3030]={};
		
		FOR(x,N+1) {
			DS[x+1]=(DS[x]+dp[e][x])%mo;
		}
		FOR(x,C[cur]) FOR(y,C[e]) {
			(to[x+y]+=comb(x+y,x)*comb(C[cur]+C[e]-(1+x+y),C[cur]-(1+x))%mo*from[x]%mo*(mo+DS[N]-DS[y]))%=mo;
		}
		
		C[cur]+=C[e];
		swap(from,to);
	}
	
	FOR(i,C[cur]) dp[cur][i]=from[C[cur]-1-i];
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,0);
	ll sum=0;
	FOR(i,N) sum+=dp[0][i];
	cout<<sum*2%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
