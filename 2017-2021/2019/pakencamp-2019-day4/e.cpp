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
vector<vector<int>> E[201010];
ll D[202020][2][2];
vector<int> V[2];
ll dp[202020][3];
ll mo=1000000007;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>j>>k;
		E[x-1].push_back({y-1,j,k});
		E[y-1].push_back({x-1,j,k});
	}
	
	FOR(i,N) FOR(x,2) FOR(y,2) D[i][x][y]=1LL<<60;
	priority_queue<pair<ll,int>> Q;
	D[0][0][0]=D[0][0][1]=D[N-1][1][0]=D[N-1][1][1]=0;
	Q.push({0,0});
	Q.push({0,1});
	Q.push({0,(N-1)*4+2+0});
	Q.push({0,(N-1)*4+2+1});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second/4;
		int id=Q.top().second/2%2;
		int season=Q.top().second%2;
		Q.pop();
		if(D[cur][id][season]!=co) continue;
		if(id==0) {
			V[season].push_back(cur);
		}
		FORR(e,E[cur]) if(D[e[0]][id][season]>co+e[season+1]) {
			D[e[0]][id][season]=co+e[season+1];
			Q.push({-D[e[0]][id][season],e[0]*4+id*2+season});
		}
	}
	FOR(i,3) dp[0][i]=1;
	FOR(i,2) {
		FORR(v,V[i]) {
			FORR(e,E[v]) {
				if(D[v][1][i]==D[e[0]][1][i]+e[1+i]) {
					(dp[e[0]][i]+=dp[v][i])%=mo;
					if(i==0 && D[v][1][1]==D[e[0]][1][1]+e[2]) {
						(dp[e[0]][2]+=dp[v][2])%=mo;
					}
				}
			}
		}
	}
	cout<<(dp[N-1][0]+dp[N-1][1]+mo-dp[N-1][2])%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
