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

int S[2],Q;
vector<int> E[2][101010];
int dp[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S[0]>>S[1]>>Q;
	FOR(i,Q) {
		cin>>j>>x>>y;
		E[x][j].push_back(y-1);
	}
	
	ll tot=0;
	FOR(j,2) {
		ZERO(dp);
		
		FOR(i,100100) if(E[j][i].size()) {
			sort(ALL(E[j][i]));
			if(E[j][i].size()==S[j]) return _P("-1\n");
			
			FORR(x,E[j][i]) {
				if(x) dp[x-1]=min(dp[x-1],dp[x]+1);
				if(x<S[j]-1) dp[x+1]=min(dp[x+1],dp[x]+1);
			}
			reverse(ALL(E[j][i]));
			FORR(x,E[j][i]) {
				if(x) dp[x-1]=min(dp[x-1],dp[x]+1);
				if(x<S[j]-1) dp[x+1]=min(dp[x+1],dp[x]+1);
			}
			FORR(r,E[j][i]) dp[r]=1<<30;
		}
		
		tot+=*min_element(dp,dp+S[j]);
	}
	
	cout<<tot<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
