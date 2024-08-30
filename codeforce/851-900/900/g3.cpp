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

int T;
int N;
int A[202020];
vector<int> E[202020];
int Q,U,V;
int P[21][200005],D[200005];
int pre[31][202020];
void dfs(int cur) {
	int i;
	FOR(i,30) {
		pre[i][cur]=pre[i][P[0][cur]];
		if(A[cur]&(1<<i)) pre[i][cur]++;
	}
	
	
	
	FORR(e,E[cur]) if(e!=P[0][cur]) D[e]=D[cur]+1, P[0][e]=cur, dfs(e);
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
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N+1) E[i].clear();
		FOR(i,N) cin>>A[i+1];
		E[0].push_back(1);
		E[1].push_back(0);
		FOR(i,N-1) {
			cin>>x>>y;
			E[x].push_back(y);
			E[y].push_back(x);
		}
		N++;

		dfs(0);
		FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
		
		cin>>Q;
		while(Q--) {
			vector<int> X;
			cin>>U>>V;
			int lc=lca(U,V);
			map<int,int> ev;
			int num=0;
			FOR(i,30) {
				X.clear();
				if(pre[i][P[0][lc]]!=pre[i][U]) {
					x=y=U;
					for(j=20;j>=0;j--) {
						if(D[x]-(1<<j)>=D[lc]&&pre[i][P[j][x]]==pre[i][U]) x=P[j][x];
						if(D[y]-(1<<j)>=D[lc]&&pre[i][P[j][y]]>pre[i][P[0][lc]]) y=P[j][y];
					}
					X.push_back(abs(D[x]-D[U]));
					X.push_back(abs(D[y]-D[U]));
				}
				if(pre[i][P[0][lc]]!=pre[i][V]) {
					x=y=V;
					for(j=20;j>=0;j--) {
						if(D[x]-(1<<j)>=D[lc]&&pre[i][P[j][x]]==pre[i][V]) x=P[j][x];
						if(D[y]-(1<<j)>=D[lc]&&pre[i][P[j][y]]>pre[i][P[0][lc]]) y=P[j][y];
					}
					X.push_back(abs(D[x]+D[U]-2*D[lc]));
					X.push_back(abs(D[y]+D[U]-2*D[lc]));
				}
				
				if(X.size()) {
					num++;
					sort(ALL(X));
					ev[X[0]]++;
					ev[X.back()+1]--;
				}
			}
			int ma=0;
			int cur=0;
			FORR2(a,b,ev) {
				cur+=b;
				ma=max(ma,cur);
			}
			cout<<num+ma<<" ";
		}
		cout<<endl;
			
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
