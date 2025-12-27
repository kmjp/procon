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

int T,N,S[2];
int M[2];
vector<int> E[2][1010];
ll dp[1010][1010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S[0]>>S[1];
		S[0]--,S[1]--;
		FOR(i,N) {
			E[0][i].clear();
			E[1][i].clear();
		}
		FOR(i,2) {
			cin>>M[i];
			FOR(j,M[i]) {
				cin>>x>>y;
				E[i][x-1].push_back(y-1);
				E[i][y-1].push_back(x-1);
			}
		}
		FOR(x,N) FOR(y,N) dp[x][y]=1LL<<60;
		dp[S[0]][S[1]]=0;
		priority_queue<pair<ll,int>> Q;
		Q.push({0,S[0]*N+S[1]});
		while(Q.size()) {
			ll co=-Q.top().first;
			int cur1=Q.top().second/N;
			int cur2=Q.top().second%N;
			Q.pop();
			if(dp[cur1][cur2]!=co) continue;
			FORR(e1,E[0][cur1]) FORR(e2,E[1][cur2]) if(chmin(dp[e1][e2],co+abs(e2-e1))) Q.push({-dp[e1][e2],e1*N+e2});
		}
		ll ret=1LL<<60;
		FOR(x,N) {
			FORR(e,E[0][x]) FORR(e2,E[1][x]) if(e==e2) ret=min(ret,dp[x][x]);
		}
		
		
		if(ret==1LL<<60) ret=-1;
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
