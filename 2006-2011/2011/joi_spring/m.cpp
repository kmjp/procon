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

int N,M;
ll D[1010][1010];
int C[1010];
vector<pair<int,int>> E[1010];

ll dp[1010][1010];
ll in[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>C[i];
	C[0]=C[N-1]=1;
	FOR(i,M) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		in[y-1]++;
	}
	FOR(x,N) {
		FOR(y,N) D[x][y]=dp[x][y]=1LL<<40;
		priority_queue<pair<int,int>> Q;
		D[x][x]=0;
		Q.push({0,x});
		while(Q.size()) {
			int co=-Q.top().first;
			int cur=Q.top().second;
			Q.pop();
			if(D[x][cur]!=co) continue;
			FORR(e,E[cur]) if(D[x][e.first]>co+e.second) {
				D[x][e.first]=co+e.second;
				Q.push({-D[x][e.first],e.first});
			}
		}
	}
	
	vector<int> V;
	vector<int> cand;
	cand.push_back(0);
	while(cand.size()) {
		x=cand.back();
		cand.pop_back();
		if(C[x]) V.push_back(x);
		FORR(e,E[x]) {
			in[e.first]--;
			if(in[e.first]==0) cand.push_back(e.first);
		}
	}
	
	dp[0][0]=0;
	for(i=1;i<V.size();i++) {
		int pre=V[i-1];
		int cur=V[i];
		FOR(x,i) {
			int op=V[x];
			dp[op][cur]=min(dp[op][cur],dp[op][pre]+D[pre][cur]);
			dp[pre][cur]=min(dp[pre][cur],dp[op][pre]+D[op][cur]);
			dp[cur][cur]=min(dp[cur][cur],dp[op][pre]+D[op][cur]+D[pre][cur]);
		}
	}
	
	cout<<dp[N-1][N-1]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
