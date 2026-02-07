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


int N;
vector<pair<int,int>> E[202020];
ll ret;
pair<int,vector<int>>  dfs(int cur,int pre) {
	int cnt=1;
	int i;
	vector<int> C(30);
	
	FORR2(e,c,E[cur]) if(e!=pre) {
		auto p=dfs(e,cur);
		
		FOR(i,30) {
			if(c&(1<<i)) {
				p.second[i]=p.first-p.second[i];
			}
			ll v=1LL*C[i]*(p.first-p.second[i])+1LL*(cnt-C[i])*p.second[i];
			if(v%2) ret^=1<<i;
			C[i]+=p.second[i];
		}
		cnt+=p.first;
		
	}
	return {cnt,C};
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y>>k;
		E[x-1].push_back({y-1,k});
		E[y-1].push_back({x-1,k});
	}
	dfs(0,0);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
