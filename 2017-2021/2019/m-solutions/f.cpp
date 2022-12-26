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
bitset<2020> A[2020];
bitset<2020> winL[2020],winR[2020],winRL[2020],winRR[2020];
bitset<2020> dp[2020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(j=1;j<N;j++) {
		cin>>s;
		FOR(i,j) {
			A[j][i]=s[i]=='1';
			A[i][j]=s[i]=='0';
		}
	}
	
	FOR(x,N) winL[x][x]=winR[x][x]=winRL[x][x]=winRR[x][x]=1;
	for(l=2;l<=N;l++) {
		for(x=0;x+l<=N;x++) {
			y=x+l-1;
			auto bs=winL[x] & (winR[y]>>1);
			if(bs.count()) dp[x][y]=dp[y][x]=1;
			bs=A[x] & dp[x] & winRL[y];
			if(bs.count()) winL[x][y]=winRL[y][x]=1;
			bs=A[y] & dp[y] & winRR[x];
			if(bs.count()) winR[y][x]=winRR[x][y]=1;
		}
	}
	int ret=0;
	FOR(i,N) ret+=winR[i][0]&winL[i][N-1];
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
