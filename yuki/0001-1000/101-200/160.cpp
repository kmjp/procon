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

int N,M,S,G;
int mat[300][300];
int mat2[300][300];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S>>G;
	FOR(x,300) FOR(y,300) mat[x][y]=1<<25;
	FOR(x,300) mat[x][x]=0;
	FOR(i,M) {
		cin>>x>>y>>r;
		mat[x][y]=mat[y][x]=r;
		mat2[x][y]=mat2[y][x]=r;
	}
	FOR(i,N) FOR(x,N) FOR(y,N) mat[x][y]=min(mat[x][y],mat[x][i]+mat[i][y]);
	
	_P("%d",S);
	while(S!=G) {
		FOR(i,N) if(mat2[S][i]+mat[i][G]==mat[S][G] && mat2[S][i]) break;
		_P(" %d",S=i);
	}
	_P("\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
