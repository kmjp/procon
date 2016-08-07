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

int N,M;
ll X[1010],S[1010];
ll tot[1010][1010];
ll dp[1010][1010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N>>M;
	if(M>=N) return _P("0\n");
	FOR(i,N) cin>>X[i];
	sort(X,X+N);
	FOR(i,N) S[i+1]=S[i]+X[i];
	
	FOR(x,N) for(y=x;y<N;y++) {
		int m=(y+x)/2;
		if((y-x)%2==0) tot[x][y]=(S[y+1]-S[m+1]) - (S[m]-S[x]);
		else tot[x][y]=(S[y+1]-S[m+1]) - (S[m+1]-S[x]);
	}
	
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(i=1;i<=M;i++) {
		int first=0;
		for(x=1;x<=N;x++) {
			for(y=first;y<x;y++) {
				if(dp[i][x] > dp[i-1][y] + tot[y][x-1]) {
					first = y;
					dp[i][x] = dp[i-1][y] + tot[y][x-1];
				}
			}
		}
	}
	cout<<dp[M][N]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
