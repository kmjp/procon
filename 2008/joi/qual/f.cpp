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

int N,K;
ll mat[101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(x,N) FOR(y,N) mat[x][y]=(x==y)?0:(1<<30);
	
	while(K--) {
		cin>>i;
		if(i==0) {
			cin>>x>>y;
			int ret=mat[x-1][y-1];
			if(ret>=1<<30) ret=-1;
			cout<<ret<<endl;
		}
		else {
			cin>>x>>y>>r;
			x--,y--;
			FOR(i,N) FOR(j,N) mat[i][j]=min({mat[i][j],mat[i][x]+r+mat[y][j],mat[i][y]+r+mat[x][j]});
		}
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
