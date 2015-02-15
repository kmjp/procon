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

int N[3],P[3];
double prob[3];
double memo[101][101][101][4];

double dpdp(int n1,int n2,int n3,int tr) {
	if(memo[n1][n2][n3][tr]>=0) return memo[n1][n2][n3][tr];
	memo[n1][n2][n3][tr]=1e10;
	
	if(tr==0) {
		if(n1>0) memo[n1][n2][n3][tr]=min(memo[n1][n2][n3][tr], 1/prob[0]+dpdp(n1-1,n2,n3,1));
		if(n2>0) memo[n1][n2][n3][tr]=min(memo[n1][n2][n3][tr], 1/prob[1]+dpdp(n1,n2-1,n3,1));
		if(n3>0) memo[n1][n2][n3][tr]=min(memo[n1][n2][n3][tr], 1/prob[2]+dpdp(n1,n2,n3-1,1));
	}
	if(tr==1) {
		if(n1>0) memo[n1][n2][n3][tr]=min(memo[n1][n2][n3][tr], prob[0]*dpdp(n1-1,n2,n3,2)+(1-prob[0])*dpdp(n1,n2,n3,0));
		if(n2>0) memo[n1][n2][n3][tr]=min(memo[n1][n2][n3][tr], prob[1]*dpdp(n1,n2-1,n3,2)+(1-prob[1])*dpdp(n1,n2,n3,0));
		if(n3>0) memo[n1][n2][n3][tr]=min(memo[n1][n2][n3][tr], prob[2]*dpdp(n1,n2,n3-1,2)+(1-prob[2])*dpdp(n1,n2,n3,0));
	}
	if(tr==2) {
		if(n1>0) memo[n1][n2][n3][tr]=min(memo[n1][n2][n3][tr], prob[0]*dpdp(n1-1,n2,n3,0)+(1-prob[0])*dpdp(n1,n2,n3,0));
		if(n2>0) memo[n1][n2][n3][tr]=min(memo[n1][n2][n3][tr], prob[1]*dpdp(n1,n2-1,n3,3)+(1-prob[1])*dpdp(n1,n2,n3,0));
		if(n3>0) memo[n1][n2][n3][tr]=min(memo[n1][n2][n3][tr], prob[2]*dpdp(n1,n2,n3-1,3)+(1-prob[2])*dpdp(n1,n2,n3,0));
	}
	if(tr==3) {
		if(n1>0) memo[n1][n2][n3][tr]=min(memo[n1][n2][n3][tr], prob[0]*dpdp(n1-1,n2,n3,0)+(1-prob[0])*dpdp(n1,n2,n3,0));
		if(n2>0) memo[n1][n2][n3][tr]=min(memo[n1][n2][n3][tr], prob[1]*dpdp(n1,n2-1,n3,0)+(1-prob[1])*dpdp(n1,n2,n3,0));
		if(n3>0) memo[n1][n2][n3][tr]=min(memo[n1][n2][n3][tr], prob[2]*dpdp(n1,n2,n3-1,0)+(1-prob[2])*dpdp(n1,n2,n3,0));
	}
	return memo[n1][n2][n3][tr];
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N[0]>>N[1]>>N[2];
	cin>>P[0]>>P[1]>>P[2];
	FOR(x,3) prob[x]=P[x]/100.0;
	FOR(i,101) FOR(j,101) FOR(k,101) FOR(x,4) memo[i][j][k][x]=-1;
	FOR(x,4) memo[0][0][0][x]=0;
	
	_P("%.12lf\n",dpdp(N[0],N[1],N[2],0));
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
