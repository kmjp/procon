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

int N;
string S;
ll mo=998244353;
ll dp[4020][4020];
int NR[2020],NB[2020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	FOR(i,N) {
		NR[i+1]=NR[i]+('2'-S[i]);
		NB[i+1]=NB[i]+(S[i]-'0');
	}
	dp[0][0]=1;
	for(int r=0;r<=NR[N];r++) {
		for(int b=0;b<=NB[N];b++) if(dp[r][b]) {
			int nr=NR[min(N,r+b+1)];
			int nb=NB[min(N,r+b+1)];
			
			if(nr>r) (dp[r+1][b]+=dp[r][b])%=mo;
			if(nb>b) (dp[r][b+1]+=dp[r][b])%=mo;
		}
	}
	
	cout<<dp[NR[N]][NB[N]]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
