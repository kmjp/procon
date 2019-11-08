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
string S;
ll dp[202020][2][2];
ll mo=1000000007;

ll dp2[202020];
ll dps[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S;
	if(S[0]=='B') {
		FORR(c,S) c='R'+'B'-c;
	}
	if(count(ALL(S),'B')==0) {
		dp[0][0][0]=dp[0][1][1]=1;
		for(i=1;i<N;i++) {
			(dp[i][0][0]=dp[i-1][0][0]+dp[i-1][0][1])%=mo;
			(dp[i][0][1]=dp[i-1][0][0])%=mo;
			(dp[i][1][0]=dp[i-1][1][0]+dp[i-1][1][1])%=mo;
			(dp[i][1][1]=dp[i-1][1][0])%=mo;
		}
		cout<<(dp[N-1][0][0]+dp[N-1][0][1]+dp[N-1][1][0])%mo<<endl;
		return;
	}
	
	vector<int> V;
	V.push_back(0);
	FORR(c,S) {
		if(c=='R') V.back()++;
		else V.push_back(0);
	}
	V.pop_back();
	
	int L=1<<20;
	if(V[0]%2==0) V[0]++;
	FORR(v,V) if(v%2) L=min(L,v);
	
	
	dp2[0]=dps[0]=1;
	for(i=2;i<=N;i+=2) {
		dp2[i]=dps[i-2];
		if(i-(L+1)>0) (dp2[i]+=mo-dps[i-(L+1)-2])%=mo;
		dps[i]=(dps[i-2]+dp2[i])%mo;
		//cout<<i<<" "<<dp2[i]<<endl;
	}
	
	ll ret=0;
	for(i=1;i<=min(L,N-1);i+=2) {
		//cout<<i<<" "<<(i+1)<<"*"<<dp2[N-(i+1)]<<endl;
		(ret+=(i+1)*dp2[N-(i+1)])%=mo;
	}
	cout<<ret%mo<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
