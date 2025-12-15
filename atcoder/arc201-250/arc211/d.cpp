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

int N,M;
int U[302020],V[302020];
vector<int> E[202020];

int Y[202020],B[202020];

void dfs(int cur,int pre) {
	if(B[cur]!=-1) return;
	B[cur]=pre;
	FORR(e,E[cur]) dfs(e,cur);
}
void dfs2(int cur,int pre) {
	if(Y[cur]!=-1) return;
	Y[cur]=pre;
	FORR(e,E[cur]) dfs2(e,cur);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>U[i]>>V[i];
		U[i]--;
		V[i]--;
		E[U[i]].push_back(V[i]);
		E[V[i]].push_back(U[i]);
	}
	
	MINUS(B);
	MINUS(Y);
	dfs(0,0);
	FOR(i,N) E[i].clear();
	FOR(i,M) {
		if(U[i]==0||B[U[i]]!=V[i]) E[V[i]].push_back(U[i]);
		if(V[i]==0||B[V[i]]!=U[i]) E[U[i]].push_back(V[i]);
	}
	dfs2(1,1);
	FOR(i,N) if(Y[i]==-1) {
		cout<<"No"<<endl;
		return;
	}
	cout<<"Yes"<<endl;
	cout<<Y[0]+1<<endl;
	cout<<B[1]+1<<endl;
	for(i=2;i<N;i++) {
		cout<<B[i]+1<<" "<<Y[i]+1<<endl;
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
