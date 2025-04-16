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
int N,M;
ll B[101010];
const ll mo=998244353;
int U[202020],V[202020];
int used[202020];
vector<int> E[202020];

map<pair<int,int>,int> Es;
int parity[202020];
int P[202020];

ll ret[202020];

void dfs(int cur,int pre,int p) {
	parity[cur]=p;
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,p^1);
}
void dfs2(int cur,int pre) {
	P[cur]=pre;
	FORR(e,E[cur]) if(e!=pre) {
		dfs2(e,cur);
		ll a=mo-B[e];
		(B[e]+=a)%=mo;
		(B[cur]+=a)%=mo;
		ret[Es[{e,cur}]]+=a;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>B[i];
		B[i]=(mo-B[i])%mo;
	}
	FOR(i,M) {
		cin>>U[i]>>V[i];
		U[i]--,V[i]--;
		Es[{U[i],V[i]}]=i;
		Es[{V[i],U[i]}]=i;
		if(uf[U[i]]!=uf[V[i]]) {
			used[i]=1;
			uf(U[i],V[i]);
			E[U[i]].push_back(V[i]);
			E[V[i]].push_back(U[i]);
		}
	}
	dfs(0,0,0);
	int root=0,par=-1;
	FOR(i,M) if(parity[U[i]]==parity[V[i]]) root=U[i],par=V[i];
	dfs2(root,root);
	
	if(B[root]) {
		if(par==-1) {
			cout<<-1<<endl;
			return;
		}
		ll a=mo-(B[root]*(mo+1)/2)%mo;
		(B[root]+=a)%=mo;
		(B[par]+=a)%=mo;
		(ret[Es[{root,par}]]+=a)%=mo;
		while(root!=par) {
			x=P[par];
			ll a=mo-B[par];
			(B[par]+=a)%=mo;
			(B[x]+=a)%=mo;
			ret[Es[{par,x}]]+=a;
			par=x;
		}
	}
	FOR(i,N) assert(B[i]==0);
	FOR(i,M) cout<<(ret[i]%mo+mo)%mo<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
