#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};

UF<500000> uf;

int N,M;
ll X[201010];
int A[101010],B[101010];
ll Y[101010];
pair<ll,int> P[101010];
int top[202020];
vector<int> E[201010];
int num[202020];
int ok[202020];

void dfs2(int cur) {
	if(cur<N) return;
	ok[E[cur][0]]=1;
	dfs2(E[cur][1]);
	dfs2(E[cur][2]);
}

void dfs(int cur) {
	if(cur<N) return;
	
	if(Y[E[cur][0]]<=X[cur]) {
		dfs2(cur);
	}
	else {
		ok[E[cur][0]]=-1;
		dfs(E[cur][1]);
		dfs(E[cur][2]);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>X[i];
		top[i]=i;
	}
	FOR(i,M) {
		cin>>A[i]>>B[i]>>Y[i];
		A[i]--;
		B[i]--;
		P[i]={Y[i],i};
	}
	
	sort(P,P+M);
	int cur=N;
	FOR(i,M) {
		x=P[i].second;
		int a=top[uf[A[x]]];
		int b=top[uf[B[x]]];
		if(a!=b) {
			E[cur]={x,a,b};
			X[cur]=X[a]+X[b];
			uf(A[x],B[x]);
			top[uf[A[x]]]=cur;
			cur++;
		}
	}
	
	dfs(cur-1);
	uf.reinit();
	
	int ret=0;
	FOR(i,M) {
		x=P[i].second;
		int a=uf[A[x]];
		int b=uf[B[x]];
		if(ok[x]==1) {
			X[a]=X[b]=X[a]+X[b];
			uf(a,b);
		}
		else if(ok[x]==-1) {
			ret++;
		}
	}
	FOR(i,M) {
		x=P[i].second;
		int a=uf[A[x]];
		if(ok[x]==0 && Y[x]>X[a]) {
			ret++;
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
