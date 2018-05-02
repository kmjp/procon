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

int T,testcase;

int N,L,ON;
int C[101010];
int num[101010];
int pat[102];

int nex(int cur) {
	int n=num[cur]+1;
	while(pat[n]>=1<<20 && n<100) n++;
	return pat[n];
}

int dp[251][251];

void solve(int TC) {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L;
	ON=N;
	FOR(i,101) pat[i]=1<<20;
	for(i=0;i<=N;i++) {
		x = (int)(i*100.0/N+0.5+1e-9);
		num[i]=x;
		pat[x]=min(pat[x],i);
	}
	num[N+1]=pat[101]=1<<30;
	
	int ret=0;
	set<pair<int,int>> M;
	
	if(N>250) {
		FOR(i,ON) {
			if(i<L) cin>>C[i];
			else C[i]=0;
			N-=C[i];
			ret+=num[C[i]];
			M.insert({nex(C[i])-C[i],i});
		}
		
		while(N>0) {
			auto a=*M.begin();
			M.erase(M.begin());
			if(N<a.first) break;
			N-=a.first;
			x=a.second;
			ret+=num[nex(C[x])]-num[C[x]];
			C[x]=nex(C[x]);
			M.insert({nex(C[x])-C[x],i});
		}
	}
	else {
		FOR(i,ON) {
			if(i<L) cin>>C[i];
			else C[i]=0;
		}
		
		ZERO(dp);
		FOR(i,ON+1) FOR(j,ON+1) dp[i][j]=-1<<30;
		dp[0][0]=0;
		FOR(i,ON) {
			for(j=C[i];j<=ON;j++) for(k=0;k+j<=ON;k++) {
				dp[i+1][j+k]=max(dp[i+1][j+k],dp[i][k]+num[j]);
			}
		}
		
		ret=dp[ON][ON];
		
	}
	
	_P("Case #%d: %d\n",TC, ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0);
	
	cin>>T;
	for(testcase=1;testcase<=T;testcase++) solve(testcase);
	return 0;
}
