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
ll P[1002],L[1002];
ll dp[1002][2006],S[1002][2006];
ll mo=1000000007;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	P[0]=-1LL<<40;
	FOR(i,N) cin>>P[i+1]>>L[i+1];
	x=0;
	
	dp[0][1003]=1;
	for(i=1003;i<=2005;i++) S[0][i]=1;
	for(i=1;i<=N;i++) {
		for(x=-L[i];x<=L[i];x++) {
			ll p=x+(P[i]-P[i-1]);
			dp[i][1003+x]=S[i-1][min(2005LL,1003+p-1)];
			S[i][1003+x]=(((1003+x>0)?S[i][1003+x-1]:0)+dp[i][1003+x])%mo;
		}
		for(x=L[i]+1;x<=1003;x++) S[i][1003+x]=S[i][1003+x-1];
	}
	cout << S[N][2005] << endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
