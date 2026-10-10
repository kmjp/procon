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
int P[202020],C[202020];
int rev[202020];
const ll mo=998244353;

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
int cnt[202020];

const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		set<int> alive={-1,N};
		
		FOR(i,N) {
			cin>>P[i];
			cnt[i]=1;
			rev[P[i]-1]=i;
			alive.insert(i);
		}
		uf.reinit(N);
		FOR(i,N) {
			cin>>C[i];
			if(i&&C[i]==C[i-1]) {
				cnt[uf[i]]=cnt[uf[i-1]]=cnt[uf[i]]+cnt[uf[i-1]];
				uf(i,i-1);
			}
		}
		
		ll ret=1;
		FOR(i,N) {
			x=rev[i];
			ret=ret*cnt[uf[x]]%mo;
			cnt[uf[x]]--;
			auto it=alive.find(x);
			int a=*prev(it);
			int b=*next(it);
			alive.erase(it);
			if(a>=0&&b<N&&C[a]==C[b]&&uf[a]!=uf[b]) {
				a=uf[a];
				b=uf[b];
				cnt[a]=cnt[b]=cnt[a]+cnt[b];
				uf(a,b);
			}
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
