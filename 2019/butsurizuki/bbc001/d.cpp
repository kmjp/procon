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
int NG[12][12];
int ngmask[1<<12];
ll dp[1<<12];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		NG[x-1][y-1]=NG[y-1][x-1]=1;
	}
	
	int mask;
	FOR(mask,1<<N) {
		FOR(y,N) if(mask&(1<<y)) {
			FOR(x,y) if(mask&(1<<x)) {
				if(NG[x][y]) ngmask[mask]=1;
			}
		}
	}
	
	dp[0]=1;
	FOR(mask,(1<<N)-1) if(dp[mask]) {
		FOR(x,N) if((mask&(1<<x))==0) break;
		int cand=((1<<N)-1)^mask^(1<<x);
		for(int submask=(1<<N)-1; submask>=0; submask--) {
			submask&=cand;
			if(ngmask[(1<<x)|submask]==0) {
				dp[mask | (1<<x) | submask] += dp[mask];
			}
		}
	}
	
	cout<<dp[(1<<N)-1]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
