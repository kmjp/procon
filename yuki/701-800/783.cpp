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

int N,C;
int W[51];
int A[51],B[51];
int dp[51][51][51];

int ma;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>C;
	FOR(i,51) W[i]=51;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	FOR(i,N) W[A[i]]=min(W[A[i]],B[i]);
	
	FOR(x,51) FOR(y,51) FOR(r,51) dp[x][y][r]=-1<<30;
	dp[0][0][C]=0;
	int ma=0;
	for(i=C;i>=0;i--) {
		for(x=0;x<=50;x++) for(y=0;y<=50;y++) {
			for(r=1;r<=50;r++) if(W[r]<=i) {
				if(x==r || y==r) continue;
				if(x&&y&&x<y&&y<r) continue;
				if(x&&y&&x>y&&y>r) continue;
				dp[y][r][i-W[r]]=max(dp[y][r][i-W[r]],dp[x][y][i]+r);
				if(x&&y) {
					
					ma=max(ma,dp[x][y][i]+r);
				}
			}
		}
	}
	
	
	
	
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
