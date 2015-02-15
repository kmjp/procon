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

int N,S[1001];
int M;
int mat[51][51];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(x,N) FOR(y,N) mat[x][y]=1<<27;
	FOR(x,N) mat[x][x]=0;
	FOR(x,N) cin>>S[x];
	cin>>M;
	FOR(i,M) {
		cin>>x>>y>>j;
		mat[x][y]=mat[y][x]=j;
	}
	FOR(i,N) FOR(j,N) FOR(k,N) mat[j][k]=min(mat[j][k],mat[j][i]+mat[i][k]);
	
	int mi=1<<27;
	for(x=1;x<N-1;x++) for(y=1;y<N-1;y++) if(x!=y)
		mi=min(mi,S[x]+S[y]+mat[0][x]+mat[x][y]+mat[y][N-1]);
	cout << mi << endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
