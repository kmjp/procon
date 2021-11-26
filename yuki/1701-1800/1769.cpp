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
vector<pair<int,int>> E[202020];
int X[202020];
int L[202020],R[202020];
int id;
map<int,vector<int>> V;

int P[21][200005],D[200005];

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
UF<202020> uf;

void dfs(int cur,int x) {
	X[cur]=x;
	V[x].push_back(cur);
	L[cur]=id++;
	FORR2(e,o,E[cur]) if(e!=P[0][cur]) D[e]=D[cur]+1, P[0][e]=cur, dfs(e,x^o);
	R[cur]=id;
}

int getpar(int cur,int up) {
	int i;
	FOR(i,20) if(up&(1<<i)) cur=P[i][cur];
	return cur;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y>>k;
		E[x-1].push_back({y-1,k});
		E[y-1].push_back({x-1,k});
	}
	dfs(0,0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];

	ll ret=1LL*N*(N-1);
	
	FORR2(a,W,V) {
		if(W.size()<=500) {
			FORR(x,W) {
				vector<pair<int,int>> V;
				FORR(y,W) if(x!=y) {
					if(L[x]>L[y]&&L[x]<R[y]) {
						k=getpar(x,D[x]-D[y]-1);
						V.push_back({0,L[k]});
						V.push_back({R[k],N});
					}
					else {
						V.push_back({L[y],R[y]});
					}
				}
				sort(ALL(V));
				int r=0;
				FORR2(v1,v2,V) {
					if(v1<=r) {
						if(v2>r) {
							ret-=v2-r;
							r=v2;
						}
					}
					else {
						ret-=v2-v1;
						r=v2;
					}
				}
			}
		}
		else {
			uf.reinit();
			FOR(i,N) if(X[i]!=a) FORR2(e,c,E[i]) if(X[e]!=a) uf(i,e);
			FORR(x,W) {
				ret-=N-1;
				FORR2(e,c,E[x]) if(X[e]!=a) ret+=uf.count(e);
			}
		}
		
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
