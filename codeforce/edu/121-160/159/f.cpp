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
int A[202020];

vector<int> E[200005];
int P[21][200005],D[200005];
vector<int> B[20][200005];

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


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		if(A[i]) B[0][i].push_back(A[i]);
	}
	
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}

	dfs(0);
	FOR(i,19) FOR(x,N) {
		P[i+1][x]=P[i][P[i][x]];
		B[i+1][x]=B[i][x];
		FORR(v,B[i][P[i][x]]) {
			y=v;
			FORR(t,B[i+1][x]) y=min(y,t^y);
			if(y) B[i+1][x].push_back(y);
		}
	}
	
	cin>>Q;
	while(Q--) {
		int X,Y,K;
		cin>>X>>Y>>K;
		X--,Y--;
		int lc=lca(X,Y);
		
		vector<int> V;
		for(j=19;j>=0;j--) {
			if(D[X]-(1<<j)>=D[lc]) {
				FORR(v,B[j][X]) {
					y=v;
					FORR(t,V) {
						y=min(y,t^y);
						if(y==0) break;
					}
					if(y) V.push_back(y);
				}
				X=P[j][X];
			}
			if(D[Y]-(1<<j)>=D[lc]) {
				FORR(v,B[j][Y]) {
					y=v;
					FORR(t,V) {
						y=min(y,t^y);
						if(y==0) break;
					}
					if(y) V.push_back(y);
				}
				Y=P[j][Y];
			}
		}
		FORR(v,B[0][lc]) {
			y=v;
			FORR(t,V) {
				y=min(y,t^y);
				if(y==0) break;
			}
			if(y) V.push_back(y);
		}
		FORR(v,V) K=min(K,v^K);
		if(K==0) {
			cout<<"YES"<<"\n";
		}
		else {
			cout<<"NO"<<"\n";
		}
		
		
	}
	

}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
