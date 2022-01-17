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
int A[505050],B[505050],C[505050];

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
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
UF<505050> uf;
vector<ll> dp[101010];
const ll mo=998244353;
int num[505050];

vector<ll> MultPoly(vector<ll> P,vector<ll> Q) {
	int a=P.size()-1;
	int b=Q.size()-1;
	int c=min(K,a+b);
	vector<ll> R(c+1);
	
	for(a=0;a<P.size();a++) {
		for(b=0;b<Q.size()&&a+b<R.size();b++) {
			(R[a+b]+=P[a]*Q[b])%=mo;
		}
	}
	
	return R;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	map<int,vector<int>> Es;
	FOR(i,M) {
		cin>>A[i]>>B[i]>>C[i];
		A[i]--,B[i]--;
		Es[C[i]].push_back(i);
	}
	FOR(i,N) dp[i]={1,1};
	
	FORR2(c,E,Es) {
		set<int> Ts;
		FORR(i,E) {
			x=uf[A[i]];
			y=uf[B[i]];
			if(x!=y) {
				num[x]=num[y]=1;
				Ts.insert(x);
				Ts.insert(y);
				uf(x,y);
			}
		}
		FORR(e,Ts) if(uf[e]!=e) {
			x=uf[e];
			num[x]++;
			dp[x]=MultPoly(dp[x],dp[e]);
		}
		FORR(e,Ts) if(uf[e]==e) {
			if(num[e]<dp[e].size()) (dp[e][num[e]]+=mo-1)%=mo;
			dp[e][1]++;
		}
	}

	vector<ll> ret={1};
	FOR(i,N) if(uf[i]==i) ret=MultPoly(ret,dp[i]);
	ll pat=0;
	FORR(k,ret) pat+=k;
	cout<<pat%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
