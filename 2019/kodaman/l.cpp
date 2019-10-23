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

int N,K;
int T,C;

int dp[81][81][81];

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N>>K;
	FOR(i,81) FOR(j,81) FOR(k,81) dp[i][j][k]=1<<30;
	dp[0][0][0]=0;
	
	FOR(i,N) {
		cin>>T>>C;
		for(int tot=min(i,K);tot>=0;tot--) {
			for(x=0;x<=tot;x++) for(y=0;y<=x;y++) {
				z=tot-x-y;
				if(z>y || z<0) continue;
				if(dp[x][y][z]==1<<30) continue;
				if(T==1) dp[x+1][y][z]=min(dp[x+1][y][z],dp[x][y][z]+C);
				if(T==2 && y+1<=x) dp[x][y+1][z]=min(dp[x][y+1][z],dp[x][y][z]+C);
				if(T==3 && z+1<=y) dp[x][y][z+1]=min(dp[x][y][z+1],dp[x][y][z]+C);
				
				
			}
		}
	}
	int mi=1<<30;
	FOR(x,K+1) FOR(y,K+1) FOR(z,K+1) if(x+y+z==K) mi=min(mi,dp[x][y][z]);
	if(mi==1<<30) {
		cout<<"Let's Shoot!"<<endl;
	}
	else {
		cout<<mi<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
