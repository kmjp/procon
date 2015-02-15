#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


int N;
string S[60];
int V[50][50];
int dp[1<<12][50];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>s;
		FOR(j,s.size()) FOR(k,4) {
			if(s[j]=='.') S[i*4+k] += "ATGC"[k];
			else S[i*4+k]+=s[j];
		}
	}
	
	FOR(x,N*4) FOR(y,N*4) FOR(V[x][y],S[x].size()+1) {
		l = min(S[y].size(),S[x].size()-V[x][y]);
		if(S[y].substr(0,l)==S[x].substr(V[x][y],l)) break;
	}
	
	FOR(x,1<<12) FOR(y,50) dp[x][y]=1000000;
	FOR(x,N*4) dp[1<<(x/4)][x]=S[x].size();
	
	int mask;
	FOR(mask,1<<N) FOR(x,N*4) if(mask & (1<<(x/4))) {
		FOR(y,N*4) if((mask & (1<<(y/4)))==0) {
			if(V[x][y]+S[y].size()>=S[x].size()) {
				dp[mask | (1<<(y/4))][y] = min(dp[mask | (1<<(y/4))][y],dp[mask][x]-(int)S[x].size()+V[x][y]+(int)S[y].size());
			}
			else {
				dp[mask | (1<<(y/4))][x] = min(dp[mask | (1<<(y/4))][x],dp[mask][x]);
			}
			
		}
	}
	int ret=10000000;
	FOR(x,N*4) ret=min(ret,dp[(1<<N)-1][x]);
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
