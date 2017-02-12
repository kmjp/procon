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
string S[404040];
map<string,int> SS;
int nei[404040];
int mi[404040];
int sc[404040];
vector<int> E[404040];

ll dp[2][404040];

void dfs(int cur,int pre) {
	dp[1][cur]=sc[cur];
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		dp[0][cur] += max(dp[0][e],dp[1][e]);
		dp[1][cur] += dp[0][e];
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	N++;
	FOR(i,N) {
		if(i) cin>>S[i];
		SS[S[i]]=i;
		FORR(c,S[i]) sc[i]+=c;
	}
	
	FOR(i,N) {
		nei[i]=-1;
		if(i==0) continue;
		s=S[i];
		while(s.size()) {
			s.pop_back();
			if(SS.count(s)) {
				nei[i]=SS[s];
				E[nei[i]].push_back(i);
				break;
			}
		}
	}
	
	dfs(0,-1);
	cout<<max(dp[0][0],dp[1][0])<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
