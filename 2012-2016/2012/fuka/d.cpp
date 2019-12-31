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

int N,A,B;
int X[20];
int wei[1<<13];
ll dp[1<<13];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	while(1) {
		cin>>N>>A>>B;
		if(N==0) return;
		FOR(i,N) cin>>X[i];
		
		for(int mask=0;mask<1<<N;mask++) {
			wei[mask]=0;
			FOR(i,N) if(mask&(1<<i)) wei[mask]+=X[i];
		}
		
		for(int mask=0;mask<1<<N;mask++) {
			if(__builtin_popcount(mask)<=1) {
				dp[mask]=1;
				continue;
			}
			dp[mask]=0;
			FOR(i,N) if(mask&(1<<i)) {
				int mask2=mask^(1<<i);
				for(int mask3=mask2;mask3>=0;mask3--) {
					mask3 &= mask2;
					int mask4=mask2^mask3;
					if(abs(wei[mask3]-wei[mask4])<A) continue;
					if(abs(wei[mask3]-wei[mask4])>B) continue;
					dp[mask] += dp[mask3]*dp[mask4];
				}
			}
			
		}
		
		cout<<dp[(1<<N)-1]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
