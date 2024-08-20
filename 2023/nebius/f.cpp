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

int N,M,Q;
int U[202020],V[202020];
int ret[202020];
int D[202020];
vector<int> E[202020];
int hoge(int v) {
	int i;
	FOR(i,N) {
		E[i].clear();
		D[i]=1LL<<20;
	}
	FOR(i,M+v) {
		E[U[i]].push_back(V[i]);
		E[V[i]].push_back(U[i]);
	}
	D[0]=0;
	queue<int> Q;
	Q.push(0);
	int ma=0;
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		ma=max(ma,D[cur]);
		FORR(e,E[cur]) if(D[e]>1LL<<19) {
			D[e]=D[cur]+1;
			Q.push(e);
		}
	}
	return ma;
}

void dfs(int L,int R) {
	if(L+1>=R) return;
	if(ret[R]*2>=ret[L]) {
		int i;
		for(i=L+1;i<R;i++) ret[i]=ret[L];
		return;
	}
	int M=(L+R)/2;
	ret[M]=hoge(M);
	dfs(L,M);
	dfs(M,R);
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	FOR(i,M+Q) {
		cin>>U[i]>>V[i];
		U[i]--;
		V[i]--;
	}
	
	ret[0]=hoge(0);
	ret[Q]=hoge(Q);
	dfs(0,Q);
	
	FOR(i,Q+1) cout<<ret[i]<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
