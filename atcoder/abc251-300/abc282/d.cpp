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

vector<pair<int,int>> E[201010];
int C[2];
ll ret;
int vis[202020];
set<int> S;

void dfs(int cur,int c) {
	if(vis[cur]!=-1) {
		if(c!=vis[cur]) {
			cout<<0<<endl;
			exit(0);
		}
		return;
	}
	vis[cur]=c;
	C[c]++;
	FORR2(e,i,E[cur]) S.insert(i), dfs(e,c^1);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back({y-1,i});
		E[y-1].push_back({x-1,i});
	}
	ret=1LL*N*(N-1)/2;
	MINUS(vis);
	FOR(i,N) if(vis[i]==-1) {
		C[0]=C[1]=0;
		S.clear();
		dfs(i,0);
		ret-=1LL*C[0]*(C[0]-1)/2+1LL*C[1]*(C[1]-1)/2+S.size();
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
