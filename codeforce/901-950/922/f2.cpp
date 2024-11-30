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

int N,K;
int P[202020];
vector<int> E[202020];
int D[202020],H[202020];
vector<int> path;
int dfs(int cur,int d) {
	D[cur]=d;
	H[cur]=0;
	vector<pair<int,int>> V;
	FORR(e,E[cur]) {
		H[cur]=max(H[cur],1+dfs(e,d+1));
		V.push_back({H[e],e});
	}
	sort(ALL(V));
	E[cur].clear();
	FORR2(a,b,V) E[cur].push_back(b);
	
	return H[cur];
}
void dfs2(int cur) {
	if(E[cur].empty()) {
		path.push_back(cur);
	}
	else {
		FORR(e,E[cur]) dfs2(e);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	for(i=1;i<N;i++) {
		cin>>x;
		P[i]=x-1;
		E[x-1].push_back(i);
	}
	dfs(0,0);
	dfs2(0);
	int ret=2*(N-1)-D[path.back()];
	vector<int> S;
	FOR(i,path.size()-1) {
		x=path[i];
		y=path[i+1];
		if(D[x]>D[y]) swap(x,y);
		while(D[y]>D[x]) y=P[y];
		while(x!=y) y=P[y],x=P[x];
		S.push_back(max(0,D[path[i]]-D[x]-(D[x])));
	}
	sort(ALL(S));
	reverse(ALL(S));
	FOR(i,min(K,(int)S.size())) ret-=S[i];
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
