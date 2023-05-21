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
int A[202020],B[202020];
vector<int> E[202020];
int ret[202020];

template<int um> class UF_pop {
	public:
	vector<int> par,rank; vector<vector<int>> hist;
	UF_pop() {par=rank=vector<int>(um,0); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; hist.clear(); FOR(i,um) rank[i]=0,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):operator[](par[x]);}
	void pop() {
		if(hist.size()) {
			auto a=hist.back();
			hist.pop_back();
			par[a[0]]=a[1]; rank[a[0]]=a[2];
			par[a[3]]=a[4]; rank[a[3]]=a[5];
		}
	}
	void operator()(int x,int y) {
		x=operator[](x); y=operator[](y);
		hist.push_back({x,par[x],rank[x],y,par[y],rank[y]});
		if(x==y) return;
		if(rank[x]<rank[y]) par[x]=y;
		else rank[x]+=(rank[x]==rank[y]), par[y]=x;
	}
};
UF_pop<202020> uf;
int NE[202020],NV[202020];
int num;
void dfs(int cur,int pre) {
	int a=uf[A[cur]];
	int b=uf[B[cur]];
	int pn=num;
	int pa=NE[a];
	int pb=NE[b];
	int va=NV[a];
	int vb=NV[b];
	if(a==b) {
		if(NV[a]-1==NE[a]) {
			num++;
			NE[a]++;
		}
	}
	else {
		if(NE[a]>=NV[a]&&NE[b]>=NV[b]) {
			;
		}
		else {
			num++;
		}
		NE[a]=NE[b]=NE[a]+NE[b]+1;
		NV[a]=NV[b]=NV[a]+NV[b];
		uf(a,b);
	}
	ret[cur]=num;
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur);
	
	if(a!=b) uf.pop();
	num=pn;
	NE[a]=pa;
	NE[b]=pb;
	NV[a]=va;
	NV[b]=vb;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,200001) NV[i]=1;
	cin>>N;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		A[i]--,B[i]--;
	}
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	dfs(0,0);
	
	for(i=1;i<N;i++) cout<<ret[i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
