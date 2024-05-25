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

int T,N,K,C;
vector<int> E[202020];

void dfs(int cur,int pre,vector<int>& D) {
	FORR(e,E[cur]) if(e!=pre) {
		D[e]=D[cur]+1;
		dfs(e,cur,D);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K>>C;
		FOR(i,N) E[i].clear();
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		vector<int> D[3];
		D[0].resize(N);
		D[1].resize(N);
		D[2].resize(N);
		dfs(0,0,D[0]);
		x=0;
		FOR(i,N) if(D[0][i]>D[0][x]) x=i;
		dfs(x,x,D[1]);
		y=x;
		FOR(i,N) if(D[1][i]>D[1][y]) y=i;
		dfs(y,y,D[2]);
		
		ll ret=-1LL<<60;
		FOR(i,N) {
			ll a=1LL*max(D[1][i],D[2][i])*K-1LL*D[0][i]*C;
			ret=max(ret,a);
			
		}
		cout<<ret<<endl;
		
		
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
