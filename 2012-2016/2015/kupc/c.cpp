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

int T;
int N;
int A[50][50];
int B[50][50];

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>T;
	while(T--) {
		int ok=1;
		cin>>N;
		FOR(y,N) FOR(x,N) {
			cin>>A[x][y];
			if(A[x][y]==-1) A[x][y]=10000000;
			B[x][y]=A[x][y];
		}
		FOR(z,N) FOR(x,N) FOR(y,N) A[x][y]=min(A[x][y],A[x][z]+A[z][y]);
		FOR(y,N) if(A[y][y]!=0) ok=0;
		FOR(y,N) FOR(x,N) if(A[x][y]!=B[x][y]) ok=0;
		
		out:
		cout<<(ok?"YES":"NO")<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
