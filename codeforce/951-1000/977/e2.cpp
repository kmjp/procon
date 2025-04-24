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

template<int um> class UF {
	public:
	vector<int> par,rank,cnt,G[um];
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit(int num=um) {int i; FOR(i,num) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<202020> uf;

int T,N,M,P;
ll S[202020];
ll C[202020];
vector<ll> R;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>P;
		FOR(i,N) S[i]=C[i]=0;
		uf.reinit(N);
		R={};
		vector<vector<int>> E;
		FOR(i,P) {
			cin>>x;
			S[x-1]=1;
		}
		FOR(i,M) {
			cin>>x>>y>>k;
			E.push_back({k,x-1,y-1});
		}
		sort(ALL(E));
		FORR(e,E) {
			x=uf[e[1]], y=uf[e[2]];
			if(x!=y) {
				ll a1=1LL*e[0]*S[x]-C[x];
				ll a2=1LL*e[0]*S[y]-C[y];
				if(a1>a2) swap(a1,a2), swap(x,y);
				if(S[x]&&S[y]) R.push_back(a1);
				C[x]=C[y]=C[y]+e[0]*S[x];
				S[x]=S[y]=S[x]+S[y];
				uf(x,y);
			}
		}
		while(R.size()<N) R.push_back(0);
		sort(ALL(R));
		for(i=1;i<N;i++) R[i]+=R[i-1];
		reverse(ALL(R));
		FORR(a,R) cout<<a<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
