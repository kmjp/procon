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
vector<int> E[101010];
int dp[101010][3]; // non/part/fill

void dfs(int cur,int pre) {
	int c=0;
	
	if(E[cur].size()==1) {
		dp[cur][0]=0;
		dp[cur][1]=1<<20;
		dp[cur][2]=1;
	}
	else {
		int count=0;
		FORR(e,E[cur]) if(e!=pre) {
			dfs(e,cur);
			count++;
			if(count==1) {
				dp[cur][0]=dp[e][0];
				dp[cur][1]=dp[e][1];
				dp[cur][2]=dp[e][2];
			}
			else {
				int d[3]={dp[cur][0],dp[cur][1],dp[cur][2]};
				dp[cur][0]=1<<20;
				if(count==2) {
					dp[cur][1]=min(min(d[1],d[2])+dp[e][0],d[0]+min(dp[e][1],dp[e][2]));
					dp[cur][2]=min(d[1],d[2])+min(dp[e][1],dp[e][2]);
				}
				else {
					dp[cur][1]=min(d[2]+dp[e][0],d[1]+min(dp[e][1],dp[e][2]));
					dp[cur][2]=d[2]+min(dp[e][1],dp[e][2]);
				}
			}
		}
		
	}
	//cout<<cur<<" "<<dp[cur][0]<<"  "<<dp[cur][1]<<"  "<<dp[cur][2]<<endl;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	FOR(i,N-1) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	FOR(i,N) if(E[i].size()>2) {
		dfs(i,-1);
		cout<<min(dp[i][1],dp[i][2])<<endl;
		return;
	}
	_P("1\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
