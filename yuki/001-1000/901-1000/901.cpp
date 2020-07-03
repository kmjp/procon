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

int N,Q;
vector<pair<int,int>> E[200005];
int P[21][200005],D[200005];
ll TD[200005];
int L[202020],R[202020],id;

void dfs(int cur,int pre,ll tot) {
	TD[cur]=tot;
	P[0][cur]=pre;
	L[cur]=id++;
	FORR(e,E[cur]) if(e.first!=pre) D[e.first]=D[cur]+1, dfs(e.first,cur,tot+e.second);
	R[cur]=id;
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
int dist(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return D[a]+D[b]-2*D[(aa==bb)?aa:P[0][aa]];  // dist
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y>>r;
		E[x].push_back({y,r});
		E[y].push_back({x,r});
	}
	dfs(0,0,0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	
	cin>>Q;
	while(Q--) {
		vector<pair<int,int>> V;
		cin>>x;
		FOR(i,x) {
			cin>>y;
			V.push_back({L[y],y});
		}
		sort(ALL(V));
		
		ll tot=0;
		int a=V[0].second, b=V[0].second;
		for(i=1;i<V.size();i++) {
			int c=V[i].second;
			int lc=lca(b,c);
			
			if(D[lc]<D[a]) {
				tot+=TD[a]-TD[lc]+TD[c]-TD[lc];
				a=lc;
			}
			else {
				tot+=TD[c]-TD[lc];
			}
			b=c;
		}
		
		cout<<tot<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
