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

int N,M,E;
int U[502020],V[502020];
int tim[505050];
vector<int> ev[505050];
int Q;
int con[505050];

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
int ret[505050];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>E;
	FOR(i,M) con[N+i]=1;
	FOR(i,E) {
		cin>>U[i]>>V[i];
		U[i]--;
		V[i]--;
		tim[i]=505050;
	}
	cin>>Q;
	FOR(i,E) tim[i]=Q;
	FOR(i,Q) {
		cin>>x;
		tim[x-1]=i;
	}
	FOR(i,E) ev[tim[i]].push_back(i);
	
	ll sum=E;
	for(i=Q;i>=1;i--) {
		FORR(e,ev[i]) {
			x=uf[U[e]];
			y=uf[V[e]];
			if(x!=y) {
				if(con[x]==0&&con[y]) {
					sum+=uf.count(x);
					con[x]=con[y]=uf.count(x)+uf.count(y);
				}
				if(con[y]==0&&con[x]) {
					sum+=uf.count(y);
					con[x]=con[y]=uf.count(x)+uf.count(y);
				}
				uf(x,y);
			}
		}
		ret[i-1]=sum-E;
		
	}
	FOR(i,Q) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
