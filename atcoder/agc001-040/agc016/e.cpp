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
int ok[404][404];
int A[101010],B[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(y,N) FOR(x,N) ok[y][x]=(y!=x);
	
	while(M--) {
		cin>>x>>y;
		x--;y--;
		if(ok[x][y]) {
			ok[x][y]=ok[y][x]=0;
			FOR(i,N) if(ok[x][i]==0) ok[y][i]=ok[i][y]=0;
			FOR(i,N) if(ok[y][i]==0) ok[x][i]=ok[i][x]=0;
		}
		else {
			FOR(j,N) ok[x][j]=ok[j][x]=ok[y][j]=ok[j][y]=0;
		}
	}
	
	int ret=0;
	FOR(y,N) FOR(x,y) ret+=ok[y][x];
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
