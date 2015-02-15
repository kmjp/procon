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

int N,M;
int mat[101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N>>M;
	FOR(x,N) FOR(y,N) mat[x][y]=1000;
	FOR(x,N) mat[x][x]=0;
	FOR(i,M) cin>>x>>y, mat[x-1][y-1]=mat[y-1][x-1]=1;
	FOR(i,N) FOR(x,N) FOR(y,N) mat[x][y]=min(mat[x][y],mat[x][i]+mat[i][y]);
	
	FOR(i,N) {
		y=0;
		FOR(x,N) if(mat[i][x]==2) y++;
		cout<<y<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
