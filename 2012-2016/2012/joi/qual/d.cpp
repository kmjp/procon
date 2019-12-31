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
int mask[101];
ll dp[101][3][3];
ll mo=10000;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) mask[i]=7;
	FOR(i,K) {
		cin>>x>>y;
		mask[x-1]=1<<(y-1);
	}
	
	FOR(x,3) FOR(y,3) dp[2][x][y]=(mask[0]&(1<<x))&&(mask[1]&(1<<y));
	for(i=2;i<N;i++) {
		FOR(j,3) if(mask[i]&(1<<j)) {
			FOR(x,3) FOR(y,3) {
				if(x==y && y==j) continue;
				(dp[i+1][y][j]+=dp[i][x][y])%=mo;
			}
		}
	}
	ll ret=0;
	FOR(x,3) FOR(y,3) ret+=dp[N][x][y];
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
