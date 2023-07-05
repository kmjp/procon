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

int T,N,A[202020],B[202020];
vector<int> E[202020];
int vis[202020];
int ret;

void dfs(int cur) {
	if(vis[cur]==2) {
		ret=1;
		return;
	}
	if(vis[cur]==1) return;
	vis[cur]=2;
	FORR(e,E[cur]) dfs(e);
	vis[cur]=1;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		
		FOR(i,N+1) vis[i]=0,E[i].clear();
		int ma=0;
		FOR(i,N) {
			cin>>A[i];
		}
		FOR(i,N) {
			cin>>B[i];
			E[A[i]].push_back(B[i]);
			if(E[A[i]].size()>E[ma].size()) ma=A[i];
		}
		
		vis[ma]=1;
		ret=0;
		FOR(i,N+1) if(vis[i]==0) dfs(i);
		if(ret) {
			cout<<"WA"<<endl;
		}
		else {
			cout<<"AC"<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
