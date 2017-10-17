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


int N,K;
vector<pair<int,int>> E[101010];
int ret;
int C[101010];
vector<int> cand;

int dfs(int cur,int pre,int state) {
	C[cur]=1;
	FORR(e,E[cur]) if(e.first!=pre) {
		if(state==0) C[cur] += dfs(e.first,cur,state+e.second);
		else C[cur] += dfs(e.first,cur,2);
	}
	if(state==1) cand.push_back(C[cur]);
	return C[cur];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N-1) {
		cin>>x>>y>>r;
		x--,y--;
		E[x].push_back({y,r});
		E[y].push_back({x,r});
	}
	dfs(0,-1,0);
	
	sort(ALL(cand));
	reverse(ALL(cand));
	FORR(c,cand) if(N>K) {
		N-=c;
		ret++;
	}
	
	if(N>K) cout<<-1<<endl;
	else cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
