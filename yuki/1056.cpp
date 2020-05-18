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
char S[202][202][202];
int B[202][202];
int C[202][202];

int ok(int a,int b) {
	int y,x;
	FOR(y,N) FOR(x,N) B[y][x]=(S[a][y][x]=='#')^(S[b][y][x]=='#');
	FOR(y,N-1) FOR(x,N-1) C[y][x]=B[y][x]^B[y][x+1]^B[y+1][x]^B[y+1][x+1];
	for(y=1;y<N-2;y++) for(x=1;x<N-2;x++) if(C[y+1][x]^C[y][x+1]^C[y-1][x]^C[y][x-1]) return 0;
	return 1;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&M);
	FOR(i,M) FOR(y,N) scanf("%s",S[i][y]);
	
	FOR(i,M-1) {
		for(j=i+1;j<M;j++) cout<<ok(i,j);
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
