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
int L[5050],R[5050];
pair<ll,int> P[5050];

ll dp[3030][3030][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>L[i]>>R[i];
		P[i]={R[i]+L[i],i};
	}
	if(N%2==0) {
		P[N]={0,N};
		N++;
	}
	
	FOR(x,3000) FOR(y,3000) dp[x][y][0]=dp[x][y][1]=1LL<<60;
	dp[0][0][0]=0;
	
	sort(P,P+N);
	FOR(i,N) {
		j=P[i].second;
		for(l=0;l<=N/2;l++) {
			for(k=0;k<=1;k++) {
				r=i-l-k;
				if(r<0 || r>N/2) continue;
				
				if(l+1<=N/2) dp[l+1][r][k]=min(dp[l+1][r][k],dp[l][r][k]+R[j]+(N/2-(l+1))*P[i].first);
				if(r+1<=N/2) dp[l][r+1][k]=min(dp[l][r+1][k],dp[l][r][k]+L[j]+(N/2-(r+1))*P[i].first);
				if(k==0)     dp[l][r][k+1]=min(dp[l][r][k+1],dp[l][r][k]+(N-1)/2*P[i].first);
			}
		}
	}
	
	cout<<dp[N/2][N/2][1]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
