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

ll mo=1000000007;
int A[25];
int fix[26];
int dp[1<<25];
vector<int> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(fix);
	FOR(i,25) {
		cin>>A[i];
		if(A[i]==0) V.push_back(i);
		else fix[A[i]]=i;
	}
	
	dp[0]=1;
	for(int mask=0;mask<(1<<25)-1;mask++) if(dp[mask]) {
		int b=__builtin_popcount(mask)+1;
		if(fix[b]>=0) {
			r=fix[b];
			y=r/5,x=r%5;
			if((mask&(1<<r))==0) {
				if(y>0 && y<4 && ((mask>>(r-5))^(mask>>(r+5)))&1) continue;
				if(x>0 && x<4 && ((mask>>(r-1))^(mask>>(r+1)))&1) continue;
				dp[mask ^ (1<<r)] += dp[mask];
				if(dp[mask ^ (1<<r)]>=mo) dp[mask ^ (1<<r)]-=mo;
			}
		}
		else {
			FORR(r,V) {
				y=r/5,x=r%5;
				if((mask&(1<<r))==0) {
					if(y>0 && y<4 && ((mask>>(r-5))^(mask>>(r+5)))&1) continue;
					if(x>0 && x<4 && ((mask>>(r-1))^(mask>>(r+1)))&1) continue;
					dp[mask ^ (1<<r)] += dp[mask];
					if(dp[mask ^ (1<<r)]>=mo) dp[mask ^ (1<<r)]-=mo;
				}
			}
		}
	}
	
	/*
	for(int mask=1;mask<1<<25;mask++) {
		int b=__builtin_popcount(mask);
		if(fix[b]>=0) {
			y=fix[b]/5,x=fix[b]%5;
			if((mask&(1<<fix[b])) && dp[mask ^ (1<<fix[b])]) {
				if(y>0 && y<4 && ((mask>>(fix[b]-5))^(mask>>(fix[b]+5)))&1) continue;
				if(x>0 && x<4 && ((mask>>(fix[b]-1))^(mask>>(fix[b]+1)))&1) continue;
				dp[mask] = dp[mask ^ (1<<fix[b])];
			}
		}
		else {
			ll ret=0;
			FORR(r,V) {
				y=r/5,x=r%5;
				if((mask&(1<<r)) && dp[mask ^ (1<<r)]) {
					if(y>0 && y<4 && ((mask>>(r-5))^(mask>>(r+5)))&1) continue;
					if(x>0 && x<4 && ((mask>>(r-1))^(mask>>(r+1)))&1) continue;
					ret += dp[mask ^ (1<<r)];
				}
			}
			dp[mask] = ret%mo;
		}
	}*/
	
	cout<<dp[(1<<25)-1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
