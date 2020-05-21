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
ll W[4040];
ll dp[4040][4040];
int cut[4040][4040];
ll S[4040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>W[i];
		S[i+1]=S[i]+W[i];
		dp[i][i+1]=0;
	}
	FOR(i,N-1) {
		dp[i][i+2]=(W[i]+W[i+1]);
		cut[i][i+2]=i+1;
	}
	for(int len=3;len<=N;len++) {
		for(i=0;i+len<=N;i++) {
			dp[i][i+len]=1LL<<60;
			for(x=cut[i][i+len-1];x<=cut[i+1][i+len];x++) {
				ll sc=S[i+len]-S[i]+dp[i][x]+dp[x][i+len];
				if(sc<dp[i][i+len]) {
					dp[i][i+len]=sc;
					cut[i][i+len]=x;
				}
			}
		}
	}
	cout<<dp[0][N]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
