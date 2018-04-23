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
ll dp[51][51][101];
ll mo=1000000007;

static const int N_=1020;
static ll C_[N_][N_];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,N_) C_[i][0]=C_[i][i]=1;
	for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j])%mo;
	
	cin>>N;
	dp[1][1][50]=dp[1][1][49]=N;
	ll ret=0;
	for(i=1;i<N;i++) {
		ret+=dp[i][N][50];
		for(j=1;j<N;j++) {
			for(k=0;k<=100;k++) if(dp[i][j][k]) {
				FOR(x,N) FOR(y,N) if(j+x+y<=N) {
					if(x+y<max(1,abs(k-50))) continue;
					int nex=((k-50)+x-y);
					if(nex%2) continue;
					nex=nex/2+50;
					if(nex<0||nex>100) continue;
					(dp[i+1][j+x+y][nex] += dp[i][j][k]*C_[x+y][x]%mo*C_[N-j][x+y])%=mo;
				}
			}
		}
	}
	ret+=dp[N][N][50];
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
