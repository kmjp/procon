#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int C[101010];
vector<pair<int,int>> E[101010];
int num[101010][2],T[2];
ll ret;

void dfs(int cur,int pre) {
	int w=0;
	
	FORR(e,E[cur]) {
		int x=e.first;
		if(x==pre) w=e.second;
		else {
			dfs(x,cur);
			num[cur][0]+=num[x][0];
			num[cur][1]+=num[x][1];
		}
	}
	
	if(w) {
		ret += 1LL*num[cur][0]*(T[1]-num[cur][1])*w;
		ret += 1LL*num[cur][1]*(T[0]-num[cur][0])*w;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>C[i];
		num[i][C[i]]++;
		T[C[i]]++;
	}
	FOR(i,N-1) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	dfs(0,-1);
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
