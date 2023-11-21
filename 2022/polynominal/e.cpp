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


int N,SD;
vector<int> E[200005];
int P[21][200005],D[200005];

int A[2][202020];

void dfs(int cur) {
	FORR(e,E[cur]) if(e!=P[0][cur]) D[e]=D[cur]+1, P[0][e]=cur, dfs(e);
}
int getpar(int cur,int up) {
	int i;
	FOR(i,20) if(up&(1<<i)) cur=P[i][cur];
	return cur;
}

int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}
void dfs2(int cur) {
	FORR(e,E[cur]) if(e!=P[0][cur]) D[e]=D[cur]+1, P[0][e]=cur, dfs2(e);
	if(A[0][cur]) A[0][P[0][cur]]=1;
	if(A[1][cur]) A[1][P[0][cur]]=1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>SD;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}

	//0ˆÈŠO‚ðª‚É‚·‚é‚È‚çP[0][root]=root‚ª•K—v
	dfs(0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	
	FOR(j,2) {
		cin>>x;
		FOR(i,x) {
			cin>>y;
			y--;
			A[j][y]=1;
			A[j^1][getpar(y,SD)]=1;
		}
	}
	dfs2(0);
	int ret=0;
	FOR(i,N) if(i) {
		if(A[0][i]) ret+=2;
		if(A[1][i]) ret+=2;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
