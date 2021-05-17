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
vector<int> E[200005];
int P[21][200005],D[200005];
int id;
int L[202020],R[202020];
int Q;
void dfs(int cur) {
	L[cur]=id++;
	FORR(e,E[cur]) if(e!=P[0][cur]) D[e]=D[cur]+1, P[0][e]=cur, dfs(e);
	R[cur]=id;
}

int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}

	dfs(0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	
	cin>>Q;
	while(Q--) {
		vector<pair<int,int>> V;
		cin>>x;
		FOR(i,x) {
			cin>>y;
			V.push_back({L[y-1],y-1});
		}
		sort(ALL(V));
		int ret=0;
		int X=V[0].second,Y=V[0].second;
		for(i=1;i<V.size();i++) {
			int u=V[i].second;
			
			int v=lca(u,Y);
			
			if(u==v) {
				ret+=D[u]-D[Y];
			}
			else if(D[v]>=D[X]) {
				ret+=D[u]-D[v];
			}
			else {
				ret+=D[X]+D[u]-D[v]*2;
				X=v;
			}
			Y=u;
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
