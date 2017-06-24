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
int E[15];
ll dp[1<<15];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	while(M--) {
		cin>>x>>y;
		x--,y--;
		E[x] |= 1<<y;
	}
	
	dp[0]=1;
	for(int ST=1;ST<1<<N;ST++) {
		int U=((1<<N)-1)^ST;
		for(int S=ST-1; S>=0; S--) {
			S&=ST;
			int T=ST^S;
			if((T&3)==3) continue;
			
			ll mul=1;
			FOR(i,N) {
				if(T&(1<<i)) (mul *= 1<<__builtin_popcount(E[i]&U))%=mo;
				if(U&(1<<i)) (mul *= (1<<__builtin_popcount(E[i]&T))-1)%=mo;
			}
			(dp[ST] += mul*dp[S])%=mo;
		}
	}
	cout<<dp[(1<<N)-1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
