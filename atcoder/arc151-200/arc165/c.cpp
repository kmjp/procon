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

int N,M;
vector<pair<int,int>> E[202020];

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
	void dump(int num=um) { //�O���[�v���������z������
		int i;
		FOR(i,num) G[i].clear();
		FOR(i,num) G[operator[](i)].push_back(i);
	}
};

UF<402020> uf;
int ok(ll v) {
	int i;
	uf.reinit(2*N);
	FOR(i,N) {
		FORR2(e,c,E[i]) if(c<v) {
			uf(i*2,e*2+1);
			uf(i*2+1,e*2);
		}
	}
	
	FOR(i,N) {
		vector<ll> V;
		FORR2(e,c,E[i]) V.push_back(c);
		if(V.size()>=2) {
			sort(ALL(V));
			if(V[0]+V[1]<v) return 0;
		}
	}
	FOR(i,N) {
		if(uf[i*2]==uf[i*2+1]) return 0;
		FORR2(e,c,E[i]) if(c<v) {
			if(uf[i*2]==uf[e*2]) return 0;
		}
	}
	
	
	return 1;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>k;
		E[x-1].push_back({y-1,k});
		E[y-1].push_back({x-1,k});
	}
	ll ret=0;
	for(i=40;i>=0;i--) if(ok(ret+(1LL<<i))) ret+=1LL<<i;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
