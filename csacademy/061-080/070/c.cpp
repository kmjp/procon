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
int mat[101][101];
int A[10101],B[10101],W[10101];

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N>>M;
	FOR(x,N) FOR(y,N) {
		if(x==y) mat[x][y]=0;
		else mat[x][y]=1000000;
	}
	FOR(i,M) {
		cin>>A[i]>>B[i]>>W[i];
		mat[A[i]-1][B[i]-1]=mat[B[i]-1][A[i]-1]=W[i];
	}
	FOR(z,N) FOR(x,N) FOR(y,N) mat[x][y]=min(mat[x][y],mat[x][z]+mat[z][y]);
	FOR(i,M) if(mat[A[i]-1][B[i]-1]!=W[i]) return _P("-1\n");
	_P("%d\n",N*(N-1)/2);
	FOR(y,N) FOR(x,y) _P("%d %d %d\n",x+1,y+1,mat[x][y]);
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
