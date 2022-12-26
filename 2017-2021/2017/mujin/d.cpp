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
vector<vector<int>> E;
vector<int> D;
ll dp[1020][1020];
ll mo=1000000007;

pair<int,int> farthest(vector<vector<int>>& E, int cur,int pre,int d,vector<int>& D) {
	D[cur]=d;
	pair<int,int> r={d,cur};
	FORR(e,E[cur]) if(e!=pre) r=max(r, farthest(E,e,cur,d+1,D));
	return r;
}

pair<int,vector<int>> diameter(vector<vector<int>>& E) { // diameter,center
	vector<int> D[2];
	D[0].resize(E.size());
	D[1].resize(E.size());
	auto v1=farthest(E,0,0,0,D[0]);
	auto v2=farthest(E,v1.second,v1.second,0,D[0]);
	farthest(E,v2.second,v2.second,0,D[1]);
	pair<int,vector<int>> R;
	R.first = v2.first;
	for(int i=E.size()-1;i>=0;i--) if(D[0][i]+D[1][i]==R.first && abs(D[0][i]-D[1][i])<=1) R.second.push_back(i);
	return R;
}

void dfs(int cur,int pre,int d,int md) {
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,d+1,md);
	for(int x=-503;x<=503;x++) if(abs(x) <= md-d){
		dp[cur][505+x]=1;
		FORR(e,E[cur]) if(e!=pre) (dp[cur][505+x] *= (dp[e][505+x+1]+dp[e][505+x-1]))%=mo;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	E.resize(N);
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	auto dia = diameter(E);
	if(dia.first%2==0) {
		dfs(dia.second[0],-1,0,dia.first/2,0);
		cout<< accumulate(dp[dia.second[0]],dp[dia.second[0]]+1010,0LL)%mo<<endl;
	}
	else {
		ll ret=0;
		dfs(dia.second[0],dia.second[1],0,dia.first/2);
		dfs(dia.second[1],dia.second[0],0,dia.first/2+1);
		for(x=3;x<=1008;x++) (ret += dp[dia.second[0]][x]*(dp[dia.second[1]][x+1]+dp[dia.second[1]][x-1]))%=mo;
		
		ZERO(dp);
		dfs(dia.second[0],dia.second[1],0,dia.first/2+1);
		dfs(dia.second[1],dia.second[0],0,dia.first/2);
		for(x=3;x<=1008;x++) (ret += dp[dia.second[0]][x]*(dp[dia.second[1]][x+1]+dp[dia.second[1]][x-1]))%=mo;
		
		ZERO(dp);
		dfs(dia.second[0],dia.second[1],0,dia.first/2);
		dfs(dia.second[1],dia.second[0],0,dia.first/2);
		for(i=3;i<=1008;i++) ret -= 2*dp[dia.second[0]][i]*dp[dia.second[1]][i]%mo;
		for(i=3;i<=1008;i++) ret -= dp[dia.second[0]][i]*dp[dia.second[1]][i+2]%mo;
		for(i=3;i<=1008;i++) ret -= dp[dia.second[0]][i]*dp[dia.second[1]][i-2]%mo;
		cout<<(ret%mo+mo)%mo<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
