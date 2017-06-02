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

int H,W;
string S[1010];
int ok[1<<16];
ll mo=1000000007;
int from[1<<16];
ll dpdp[1<<16];
ll dp[20];

inline int mulmod(int a,int b,int mo) {
	int d,r;
	if(a==0 || b==0) return 0;
	if(a==1 || b==1) return max(a,b);
	__asm__("mull %4;"
	        "divl %2"
		: "=d" (r), "=a" (d)
		: "r" (mo), "a" (a), "d" (b));
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	FOR(x,1<<H) from[x]=1;
	int mask;
	FOR(x,W) {
		ZERO(ok);
		int m[26]={};
		FOR(y,H) if(S[y][x]!='.') m[S[y][x]-'a'] |= 1<<y;
		FOR(y,26) for(i=m[y];i>=0;i--) i&=m[y], ok[i]=1;
		FOR(y,H) {
			mask=1<<y;
			for(i=mask;i<1<<H;i=(i+1)|mask) ok[i] += ok[i^mask];
		}
		FOR(mask,1<<H) from[mask]=mulmod(from[mask],ok[mask],(int)mo);
	}
	
	FOR(i,1<<H) {
		ll ret=from[i];
		for(j=i-1; j>=0; j--) j&=i, ret-=from[j];
		from[i]=(ret%mo+mo)%mo;
		(dp[H-__builtin_popcount(i)]+=from[i])%=mo;
	}
	FOR(x,H+1) _P("%lld%c",dp[x],(x==H)?'\n':' ');
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
