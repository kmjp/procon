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

int N,T;
string S;
int dp[30303][250];
int same[30303][250];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		S.clear();
		S.push_back(0);
		FOR(i,N) {
			cin>>x;
			S.push_back(x);
		}
		N++;
		FOR(i,N) FOR(j,250) dp[i][j]=1<<20;
		for(j=1;j<=min(N,249);j++) {
			same[N-j][j]=0;
			for(i=N-j-1;i>=0;i--) {
				if(S[i]==S[i+j]) same[i][j]=same[i+1][j]+1;
				else same[i][j]=0;
				
			}
		}
		
		int mi=N-1;
		
		dp[0][1]=0;
		FOR(i,N) {
			for(j=1;j<=249&&i+j<=N;j++) {
				if(i+j<N) dp[i][j+1]=min(dp[i][j+1],dp[i][j]+1);
				int cand=dp[i][j]+(N-i-j);
				mi=min(mi,cand);
				if(i+2*j<=N) {
					if(same[i][j]>=j || S[i+same[i][j]]<S[i+j+same[i][j]]) {
						dp[i+j][j]=min(dp[i+j][j],dp[i][j]+j-1);
					}
					else if(i+2*j+1<=N) {
						dp[i+j][j+1]=min(dp[i+j][j+1],dp[i][j]+j);
					}
				}
			}
		}
		
		
		
		cout<<mi<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
