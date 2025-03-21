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
int U[202020],V[202020];
vector<int> E[202020];

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
map<pair<int,int>,int> Es;
int ret[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(ret);
	cin>>N>>M;
	FOR(i,M) {
		cin>>U[i]>>V[i];
		U[i]--,V[i]--;
		E[U[i]].push_back(V[i]);
		E[V[i]].push_back(U[i]);
		if(U[i]==0&&V[i]==N-1||U[i]==N-1&&V[i]==0) {
			cout<<-1<<endl;
			return;
		}
		assert(Es.count({U[i],V[i]})==0);
		Es[{U[i],V[i]}]=i;
		Es[{V[i],U[i]}]=i;
	}
	if(M%2) {
		cout<<-1<<endl;
		return;
	}
	int NR=M/2,NB=M/2;
	
	if(E[0].size()<=M/2&&E[N-1].size()<=M/2) {
		FORR(e,E[0]) {
			ret[Es[{0,e}]]=0;
			NR--;
		}
		FORR(e,E[N-1]) {
			ret[Es[{N-1,e}]]=1;
			NB--;
		}
	}
	else if(E[0].size()<=M/2) {
		FORR(e,E[0]) {
			ret[Es[{0,e}]]=0;
			NR--;
			uf(0,e);
		}
		FORR(e,E[N-1]) if(NR&&uf[e]!=uf[0]) {
			ret[Es[{N-1,e}]]=0;
			NR--;
			uf(N-1,e);
		}
		assert(NR==0);
	}
	else {
		FORR(e,E[N-1]) {
			ret[Es[{N-1,e}]]=0;
			NR--;
			uf(N-1,e);
		}
		FORR(e,E[0]) if(NR&&uf[e]!=uf[N-1]) {
			ret[Es[{0,e}]]=0;
			NR--;
			uf(0,e);
		}
		assert(NR==0);
	}
	FOR(i,M) {
		if(ret[i]==-1) {
			if(NR) {
				ret[i]=0;
				NR--;
			}
			else {
				ret[i]=1;
				NB--;
			}
		}
	}
	
	FOR(i,M) cout<<"RB"[ret[i]];
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
