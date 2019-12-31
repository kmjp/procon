#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int N,M,P;
int X[101],S[101];
int dp[101][101];

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>N>>M>>P;
	FOR(i,M) cin>>X[i];
	FOR(i,M) S[i+1]=S[i]+X[i];
	
	MINUS(dp);
	dp[0][N]=0;
	FOR(i,N) FOR(x,N+1) if(dp[i][x]>=0) {
		y=dp[i][x]+P;
		FOR(j,min(x,M)+1) if(S[j]<=y) {
			dp[i+1][x-j]=max(dp[i+1][x-j],y-S[j]);
			if(x-j==0) return _P("%d\n",i+1);
		}
	}
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


