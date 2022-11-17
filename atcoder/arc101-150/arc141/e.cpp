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


int N,Q;
int A[202020],B[202020],C[202020],D[202020];
int H[202020];
vector<pair<int,int>> E[202020];

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
int G[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,Q) {
		cin>>A[i]>>B[i]>>C[i]>>D[i];
		A[i]=(A[i]-B[i]+N)%N;
		C[i]=(C[i]-D[i]+N)%N;
		B[i]=(D[i]-B[i]+N)%N;
		swap(B[i],C[i]);
		
		if(uf[A[i]]==uf[B[i]]) {
			D[i]=1;
		}
		else {
			E[A[i]].push_back({B[i],N-C[i]});
			E[B[i]].push_back({A[i],C[i]});
			uf(A[i],B[i]);
			D[i]=0;
		}
	}
	
	MINUS(H);
	FOR(i,N) if(H[i]==-1) {
		H[i]=0;
		queue<int> Q;
		Q.push(i);
		while(Q.size()) {
			int cur=Q.front();
			Q.pop();
			FORR2(e,d,E[cur]) if(H[e]==-1) {
				H[e]=(H[cur]+d)%N;
				Q.push(e);
			}
		}
	}
	
	uf.reinit(N);
	ll ret=1LL*N*N;
	FOR(i,N) G[i]=N;
	
	FOR(i,Q) {
		if(D[i]==0) {
			x=uf[A[i]];
			y=uf[B[i]];
			ret-=G[x];
			ret-=G[y];
			G[x]=G[y]=__gcd(G[x],G[y]);
			uf(x,y);
			ret+=G[x];
			
		}
		else {
			x=uf[A[i]];
			y=uf.count(A[i]);
			ret-=G[x];
			k=(H[B[i]]-H[A[i]]+C[i]+N)%N;
			G[x]=__gcd(__gcd(G[x],k),N);
			ret+=G[x];
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
