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
int A[1010],B[1010],R[1010];
int mat[101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(x,N) FOR(y,N) mat[x][y]=(x==y)?0:1<<25;
	FOR(i,M) {
		cin>>A[i]>>B[i]>>R[i];
		A[i]--;
		B[i]--;
		mat[A[i]][B[i]]=mat[B[i]][A[i]]=R[i];
	}
	FOR(k,N) FOR(i,N) FOR(j,N) mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
	
	int ng=0;
	FOR(i,M) {
		int ok=0;
		FOR(x,N) FOR(y,N) {
			if(mat[x][y]==mat[x][A[i]]+mat[B[i]][y]+R[i]) ok=1;
			if(mat[x][y]==mat[x][B[i]]+mat[A[i]][y]+R[i]) ok=1;
		}
		if(ok==0) ng++;
	}
	cout<<ng<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
