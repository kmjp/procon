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

string S;
int K,N;
int E[3030];
ll dp[3030][3030];
ll mo=1000000007;

void dpdp(int L,int R) {
	int i,j;
	if(L+1==R) {
		dp[L][1515]=2;
		if(K>=1) dp[L][1515-1]=dp[L][1515+1]=1;
	}
	else if(E[L]==R) {
		dpdp(L+1,R-1);
		int lw=(R-L-1)/2;
		for(i=-lw;i<=lw;i++) {
			if(i>=-K && i<=K) (dp[L][1515+i] += 2*dp[L+1][1515+i])%=mo;
			if(i-1>=-K && i-1<=K) (dp[L][1515+i-1] += dp[L+1][1515+i])%=mo;
			if(i+1>=-K && i+1<=K) (dp[L][1515+i+1] += dp[L+1][1515+i])%=mo;
		}
	}
	else {
		dpdp(L,E[L]);
		dpdp(E[L]+1,R);
		ll from[3030];
		for(i=-1500;i<=1500;i++) from[1515+i]=dp[L][1515+i], dp[L][1515+i]=0;
		int lw=(E[L]-L+1)/2;
		int rw=(R-E[L])/2;
		
		for(i=-lw;i<=lw;i++) if(from[1515+i]) {
			for(j=-rw;j<=rw;j++) (dp[L][1515+i+j]+=from[1515+i]*dp[E[L]+1][1515+j])%=mo;
		}
	}
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>K;
	K/=2;
	N=S.size();
	stack<int> ST;
	FOR(i,N) {
		if(S[i]=='(') ST.push(i);
		else E[ST.top()]=i,ST.pop();
	}
	
	dpdp(0,N-1);
	ll ret=0;
	for(i=-1500;i<=1500;i++) ret+=dp[0][1515+i];
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
