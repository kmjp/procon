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

int N,Q;
string S[20];
int B[20];
int cnt[20][10];

int dp[1<<19][19];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>B[i];
	FOR(i,N) {
		cin>>S[i];
		FORR(c,S[i]) cnt[i][c-'0']++;
	}
	FOR(i,1<<N) FOR(j,N) dp[i][j]=-1<<30;
	dp[0][0]=0;
	
	int ma=0;
	for(int mask=1;mask<1<<N;mask++) {
		int C[10]={};
		FOR(i,N) if(mask&(1<<i)) {
			FOR(j,10) C[j]+=cnt[i][j];
		}
		FOR(j,10) if(C[j]>Q) break;
		if(j<10) continue;
		
		if(__builtin_popcount(mask)==1) {
			FOR(i,N) if(mask&(1<<i)) {
				dp[mask][i]=B[i];
				ma=max(ma,dp[mask][i]);
			}
		}
		else {
			FOR(i,N) if(mask&(1<<i)) {
				FOR(j,N) if(i!=j && (mask&(1<<j))) dp[mask][i]=max(dp[mask][i],dp[mask^(1<<i)][j] + (B[j]^B[i]));
				ma=max(ma,dp[mask][i]);
			}
		}
		
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
