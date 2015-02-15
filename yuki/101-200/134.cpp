#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int X[100],Y[100];
double W[100],TW;
double dp[15][1<<15];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X[0]>>Y[0];
	cin>>N;
	FOR(i,N) cin>>X[i+1]>>Y[i+1]>>W[i+1], TW+=W[i+1];
	N++;
	FOR(i,N) FOR(j,1<<N) dp[i][j]=1e15;
	dp[0][0]=0;
	
	for(int mask=0;mask<1<<N;mask++) {
		FOR(i,N) if(dp[i][mask]<1e15) {
			double lw=TW;
			FOR(j,N) if(mask&(1<<j)) lw-=W[j];
			FOR(j,N) if((mask&(1<<j))==0) {
				int lo=abs(X[j]-X[i])+abs(Y[j]-Y[i]);
				dp[j][mask | (1<<j)] = min(dp[j][mask | (1<<j)], dp[i][mask] + lo*(lw+100.0)/120 + W[j]);
			}
		}
	}
	_P("%.12lf\n",dp[0][(1<<N)-1]);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
