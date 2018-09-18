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
int nex[101010][2];
int F[101010];
int tmp[3];
ll dp[101010];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	FOR(i,N-1) if(S[i]==S[i+1]) break;
	if(i==N-1) return _P("1\n");
	
	FOR(i,N) {
		S[i]-='a'-1;
		F[i+1]=(F[i]+S[i])%3;
	}
	nex[N][0]=nex[N][1]=N+1;
	tmp[0]=tmp[1]=tmp[2]=N+1;
	int pn=N;
	for(i=N-1;i>=0;i--) {
		if(i<N-1 && S[i]==S[i+1]) {
			while(pn>i) tmp[F[pn]]=pn, pn--;
		}
		if(S[i]==1) {
			nex[i][0]=i+1;
			nex[i][1]=tmp[(F[i]+2)%3];
		}
		else {
			nex[i][1]=i+1;
			nex[i][0]=tmp[(F[i]+1)%3];
		}
	}
	dp[0]=1;
	FOR(i,N) {
		if(nex[i][0]<=N) (dp[nex[i][0]]+=dp[i])%=mo;
		if(nex[i][1]<=N) (dp[nex[i][1]]+=dp[i])%=mo;
	}
	ll ret=0;
	for(i=1;i<=N;i++) if(F[i]==F[N]) ret+=dp[i];
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
