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

int N,M,K;
ll mat[500][500];
ll tot;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(x,N) FOR(y,N) mat[x][y]=1LL<<40;
	FOR(i,N) mat[i][i]=0;
	FOR(i,M) {
		cin>>x>>y>>r;
		mat[x-1][y-1]=mat[y-1][x-1]=min(mat[y-1][x-1],(ll)r);
	}
	FOR(i,N) FOR(x,N) FOR(y,N) mat[x][y]=min(mat[x][y],mat[x][i]+mat[i][y]);
	FOR(y,N) FOR(x,N) tot+=mat[x][y];
	
	cin>>K;
	while(K--) {
		cin>>x>>y>>r;
		x--,y--;
		if(x>y) swap(x,y);
		FOR(i,N) FOR(j,N) {
			if(mat[i][j]>mat[i][x]+r+mat[y][j]) {
				tot -=mat[i][j]-(mat[i][x]+r+mat[y][j]);
				mat[i][j]=(mat[i][x]+r+mat[y][j]);
			}
			if(mat[i][j]>mat[i][y]+r+mat[x][j]) {
				tot -=mat[i][j]-(mat[i][y]+r+mat[x][j]);
				mat[i][j]=(mat[i][y]+r+mat[x][j]);
			}
		}
		
		cout<<tot/2<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
