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

int T;
int N;
int P[202020];
const ll mo=998244353;
int A[202020];
int C[202020];
ll S[202020];

int tail[202020];
int nex[202020];

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
		if(x<y) return par[y]=x;
		else return par[x]=y;
	}
};
UF<202020> uf;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


struct Edge {
	ll S,C;
	int id;
	bool operator<(const Edge &y) const {
		return (S*y.C > y.S*C)||((S*y.C == y.S*C&&id<y.id));
	}
};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		N++;
		for(i=1;i<N;i++) {
			cin>>P[i];
		}
		ll sum=0;
		uf.reinit(N);
		set<Edge> Q;
		
		for(i=0;i<N;i++) {
			if(i) cin>>A[i];
			sum+=A[i];
			S[i]=A[i];
			C[i]=1;
			tail[i]=i;
			if(i) Q.insert({S[i],C[i],i});
		}
		
		ll ret=0;
		while(Q.size()) {
			x=Q.begin()->id;
			Q.erase(Q.begin());
			
			y=uf[P[x]];
			(ret+=1LL*C[y]*S[x])%=mo;
			Q.erase({S[y],C[y],y});
			S[y]+=S[x];
			C[y]+=C[x];
			if(y) {
				Q.insert({S[y],C[y],y});
			}
			
			uf(x,y);
		}
		
		ret=ret%mo*modpow(sum)%mo;
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
