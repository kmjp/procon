#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll D[101010];
ll dp[101010][4];
ll sum[101010][4];

ll mo=1000000007;
ll ret;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>D[i];
	D[N]=0;
	N++;
	sort(D,D+N);
	
	for(i=1;i<N;i++) {
		x=lower_bound(D,D+i+1,D[i]/2+1)-D;
		while(D[x]*2>D[i]) x--;
		dp[i][0]=1;
		dp[i][1]=sum[x][0];
		dp[i][2]=sum[x][1];
		dp[i][3]=sum[x][2];
		FOR(j,3) sum[i][j]=(sum[i-1][j]+dp[i][j])%mo;
		ret += dp[i][3];
	}
	
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
