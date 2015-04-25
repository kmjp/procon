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

int N,M;
ll mat[301][301];
ll dist[301];


void solve() {
	int i,j,k,l,r,x,y; string s;
	ll mi=1LL<<60;
	
	cin>>N>>M;
	FOR(x,N) FOR(y,N) mat[x][y] = mi;
	FOR(x,N) mat[x][x]=0;
	
	FOR(i,M) {
		cin>>x>>y>>r;
		mat[x-1][y-1]=mat[y-1][x-1]=r;
	}
	
	for(i=1;i<N;i++) for(x=1;x<N;x++) for(y=1;y<N;y++) mat[x][y]=min(mat[x][y],mat[x][i]+mat[i][y]);
	for(x=1;x<N;x++) for(y=x+1;y<N;y++) mi=min(mi,mat[0][x]+mat[x][y]+mat[y][0]);
	
	if(mi>=1LL<<60) mi=-1;
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
