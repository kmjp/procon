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
int N,t,Q;
vector<pair<int,int>> E[200005];
int P[21][200005],D[200005];
ll H[21][202020];

ll dist[202020];
ll mi1[21][202020],mi2[21][202020];
string S;
int A[202020],B[202020],lc[202020];
ll mi[202020];

void dfs(int cur) {
	int i;
	FORR2(e,c,E[cur]) if(e!=P[0][cur]) {
		D[e]=D[cur]+1;
		P[0][e]=cur;
		FOR(i,21) H[i][e]=H[i][cur]+((c+(1<<i)-1)>>i);
		dfs(e);
	}
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



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>t;
		FOR(i,N) {
			E[i].clear();
		}
		FOR(i,N-1) {
			cin>>x>>y>>k;
			E[x-1].push_back({y-1,k});
			E[y-1].push_back({x-1,k});
		}
		cin>>S;
		

		//0ˆÈŠO‚ðª‚É‚·‚é‚È‚çP[0][root]=root‚ª•K—v
		dfs(0);
		FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
		cin>>Q;
		FOR(i,Q) {
			cin>>A[i]>>B[i];
			A[i]--;
			B[i]--;
			lc[i]=lca(A[i],B[i]);
			mi[i]=H[0][A[i]]+H[0][B[i]]-2*H[0][lc[i]];
		}
		
		FOR(i,21) {
			priority_queue<pair<ll,int>> PQ;
			FOR(j,N) {
				if(S[j]=='1') {
					dist[j]=t*i;
					PQ.push({-t*i,j});
				}
				else {
					dist[j]=1LL<<60;
				}
			}
			while(PQ.size()) {
				ll co=-PQ.top().first;
				int cur=PQ.top().second;
				PQ.pop();
				if(co!=dist[cur]) continue;
				FORR2(e,c,E[cur]) if(chmin(dist[e],co+c+((c+(1<<i)-1)>>i))) PQ.push({-dist[e],e});
			}
			FOR(j,N) {
				mi1[0][j]=-H[0][j]+dist[j]+H[i][j];
				mi2[0][j]=H[0][j]+dist[j]-H[i][j];
			}
			FOR(k,20) FOR(j,N) {
				mi1[k+1][j]=min(mi1[k][j],mi1[k][P[k][j]]);
				mi2[k+1][j]=min(mi2[k][j],mi2[k][P[k][j]]);
			}
			
			FOR(k,Q) {
				mi[k]=min(mi[k],H[0][A[k]]+H[i][B[k]]-H[0][lc[k]]-H[i][lc[k]]+dist[lc[k]]);
				x=A[k];
				y=D[A[k]]-D[lc[k]];
				FOR(j,20) if(y&(1<<j)) {
					mi[k]=min(mi[k],H[0][A[k]]+H[i][B[k]]-2*H[i][lc[k]]+mi1[j][x]);
					x=P[j][x];
				}
				x=B[k];
				y=D[B[k]]-D[lc[k]];
				FOR(j,20) if(y&(1<<j)) {
					mi[k]=min(mi[k],H[0][A[k]]+H[i][B[k]]-2*H[0][lc[k]]+mi2[j][x]);
					x=P[j][x];
				}
			}
		}
		FOR(i,Q) cout<<mi[i]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
