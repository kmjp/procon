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

int N,NN[3];
int A[101];

double memo[101][101][101];

double dpdp(int n3,int n2,int n1) {
	if(memo[n3][n2][n1]>=0) return memo[n3][n2][n1];
	
	memo[n3][n2][n1]=N*1.0/(n1+n2+n3);
	if(n1>0) memo[n3][n2][n1]+=dpdp(n3,n2,n1-1)*n1/(n1+n2+n3);
	if(n2>0) memo[n3][n2][n1]+=dpdp(n3,n2-1,n1+1)*n2/(n1+n2+n3);
	if(n3>0) memo[n3][n2][n1]+=dpdp(n3-1,n2+1,n1)*n3/(n1+n2+n3);
	return memo[n3][n2][n1];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N;
	
	FOR(i,N) {
		cin>>A[i];
		if(A[i]==0) NN[2]++;
		if(A[i]==1) NN[1]++;
		if(A[i]==2) NN[0]++;
	}
	FOR(x,101) FOR(y,101) FOR(i,101) memo[x][y][i]=-1;
	memo[0][0][0]=0;
	_P("%.12lf\n",dpdp(NN[2],NN[1],NN[0]));
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
