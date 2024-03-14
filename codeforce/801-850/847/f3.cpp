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
int N,C[202020];
int F[202020];
int R[202020];
const int DI=150;

vector<int> E[200005];
int P[21][200005],D[200005];

void dfs(int cur) {
	FORR(e,E[cur]) if(e!=P[0][cur]) D[e]=D[cur]+1, P[0][e]=cur, dfs(e);
}

int dist(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=17;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=17;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return D[a]+D[b]-2*D[(aa==bb)?aa:P[0][aa]];  // dist
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			E[i].clear();
			F[i]=1LL<<20;
		}
		FOR(i,N) {
			cin>>C[i];
			C[i]--;
		}
		
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		dfs(0);
		FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
		
		int pre=1<<20;
		FOR(i,N/DI+1) {
			vector<int> cand;
			queue<int> Q;
			for(x=i*DI;x<(i+1)*DI;x++) if(x<N) {
				R[x]=min(F[C[x]],pre);
				if(pre==1) continue;
				FORR(a,cand) R[x]=min(R[x],dist(C[x],a));
				pre=R[x];
				cand.push_back(C[x]);
			}
			if(pre==1) continue;
			FORR(a,cand) {
				F[a]=0;
				Q.push(a);
			}
			while(Q.size()) {
				int cur=Q.front();
				Q.pop();
				if(F[cur]>=R[x-1]) break;
				FORR(e,E[cur]) if(F[e]>F[cur]+1) {
					F[e]=F[cur]+1;
					Q.push(e);
				}
			}
			
		}
		
		FOR(i,N) if(i) cout<<R[i]<<" ";
		cout<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
