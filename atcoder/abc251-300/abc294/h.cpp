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

int N,M,K;
vector<pair<int,int>> E;
const ll mo=998244353;

vector<pair<int,int>> goswap(vector<pair<int,int>> E,int a,int b) {
	FORR2(x,y,E) {
		if(x==a) x=b;
		else if(x==b) x=a;
		if(y==a) y=b;
		else if(y==b) y=a;
		
	}
	return E;
}


vector<ll> FPS_pow(vector<ll> F,int K) {
	const int NUM_=40001;
	static ll inv[NUM_+1];
	if(inv[1]==0) {
		inv[1]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	}

	int N=F.size();
	vector<ll> G(N);
	assert(F[0]==1);
	G[0]=1;
	int i,j;
	for(i=1;i<N;i++) {
		ll co=K+1-i;
		for(j=1;j<=i;j++) {
			(G[i]+=F[j]*G[i-j]%mo*co)%=mo;
			co=(co+K+1)%mo;
		}
		G[i]=G[i]*inv[i]%mo;
	}
	
	return G;
}

ll subset(int N,vector<ll> F) {
	int M=1<<N;
	vector<vector<ll>> G;
	G.resize(M);
	FORR(g,G) g.resize(N+1);
	int mask;
	FOR(mask,M) G[mask][__builtin_popcount(mask)]=F[mask];
	int i,j,x,y;
	//èÙÇ›çûÇ›
	FOR(i,N) {
		int len=1<<i;
		for(x=0;x<M;x+=2*len) {
			FOR(j,len) {
				FOR(y,N+1) {
					G[x+j+len][y]=(G[x+j+len][y]+G[x+j][y])%mo;
				}
			}
		}
	}
	FOR(mask,M) {
		G[mask]=FPS_pow(G[mask],K);
	}
	
	//ñﬂÇ∑
	FOR(i,N) {
		int len=1<<i;
		for(x=0;x<M;x+=2*len) {
			FOR(j,len) {
				FOR(y,N+1) {
					G[x+j+len][y]=(G[x+j+len][y]-G[x+j][y]+mo)%mo;
				}
			}
		}
	}
	return G.back()[N];
}

ll go(int N,vector<pair<int,int>> E) {
	vector<ll> F(1<<N);
	int mask;
	FOR(mask,1<<N) {
		int x,y;
		F[mask]=1;
		FORR2(a,b,E) {
			if((mask&(1<<a))&&(mask&(1<<b))) F[mask]=0;
		}
	}
	return subset(N,F);
}

ll dfs(int N,vector<pair<int,int>> E) {
	
	FORR2(a,b,E) if(a==b) return 0;
	if(N==0) return 1;
	vector<pair<int,int>> E2;
	FORR2(a,b,E) {
		if(a>b) swap(a,b);
		if(b<N) E2.push_back({a,b});
	}
	sort(ALL(E2));
	E2.erase(unique(ALL(E2)),E2.end());
	E=E2;
	
	int C[30]={};
	FORR2(a,b,E) if(a<N&&b<N) C[a]++, C[b]++;
	int ma=0;
	int i;
	FOR(i,N) if(C[i]<C[ma]) ma=i;
	
	E=goswap(E,ma,N-1);
	if(C[ma]==0||C[ma]==1) {
		
		vector<pair<int,int>> E2;
		FORR2(a,b,E) {
			if(a>=N-1||b>=N-1) continue;
			E2.push_back({a,b});
		}
		return (K-C[ma])*dfs(N-1,E2)%mo;
	}
	else if(C[ma]==2) {
		
		vector<int> T;
		FORR2(a,b,E) {
			if(a==N-1&&b<a) T.push_back(b);
			if(b==N-1&&a<b) T.push_back(a);
		}
		
		int x=T[0],y=T[1];
		ll ret=(K-2+mo)*dfs(N-1,E)%mo;
		vector<pair<int,int>> E2;
		if(x==N-2) {
			swap(x,y);
		}
		else {
			E=goswap(E,y,N-2);
		}
		y=N-2;
		FORR2(a,b,E) {
			if(a>=N-1||b>=N-1) continue;
			if(a==y) E2.push_back({x,b});
			else if(b==y) E2.push_back({a,x});
			else E2.push_back({a,b});
		}
		return (ret+dfs(N-2,E2))%mo;
	}
	else {
		return go(N,E);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>x>>y;
		E.push_back({x-1,y-1});
	}
	cout<<dfs(N,E)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
