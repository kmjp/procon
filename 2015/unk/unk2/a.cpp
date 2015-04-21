#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
pair<int,int> P[101];
pair<int,int> Q[101];
int dp[103][103], ma;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>P[i].first>>P[i].second, P[i].first++;
	cin>>M;
	FOR(i,M) cin>>Q[i].first>>Q[i].second, Q[i].first++;
	FOR(i,102) {
		FOR(j,N) if(P[j].first==i) {
			for(x=101;x>=0;x--) FOR(y,i) {
				
				dp[max(x,P[j].second)][y]=max(dp[max(x,P[j].second)][y],dp[x][y]+1);
				ma=max(ma,dp[max(x,P[j].second)][y]);
			}
		}
		FOR(j,M) if(Q[j].first==i) {
			FOR(x,i) for(y=101;y>=0;y--) {
				dp[x][max(y,Q[j].second)]=max(dp[x][max(y,Q[j].second)],dp[x][y]+1);
				ma=max(ma,dp[x][max(y,Q[j].second)]);
			}
		}
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
