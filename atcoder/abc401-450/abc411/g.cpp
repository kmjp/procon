#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N,M;
int E[22][22];
const ll mo=998244353;
ll dp[1<<20][20];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		E[x][y]++;
		E[y][x]++;
	}
	int mask;
	ll ret=0;
	FOR(y,N) FOR(x,y) (ret+=1LL*E[x][y]*(E[x][y]-1))%=mo;
	
	while(N>=3) {
		ZERO(dp);
		dp[1<<(N-1)][N-1]=1;
		FOR(mask,1<<N) FOR(i,N) if(dp[mask][i]) {
			if(__builtin_popcount(mask)>=3) (ret+=dp[mask][i]*E[i][N-1])%=mo;
			FOR(j,N) if((mask&(1<<j))==0) (dp[mask|(1<<j)][j]+=dp[mask][i]*E[i][j])%=mo;
		}
		N--;
	}
	cout<<ret*(mo+1)/2%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
