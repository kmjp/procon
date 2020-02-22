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

const int MAT=402;
int mat[MAT][MAT];


int gf2_rank(int A[MAT][MAT],int n) { /* input */
	int i,j,k;
	FOR(i,n) {
		int be=i,mi=n+1;
		for(j=i;j<n;j++) {
			FOR(k,n) if(A[j][k]) break;
			if(k<mi) be=j,mi=k;
		}
		if(mi>=n) break;
		FOR(j,n) swap(A[i][j],A[be][j]);
		
		FOR(j,n) if(i!=j&&A[j][mi]) {
			FOR(k,n) A[j][k] ^= A[i][k];
		}
	}
	return i;
}

int N;
string S[303];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) {
		cin>>S[y];
		FOR(x,N) mat[y][x]=S[y][x]=='1';
	}
	if(gf2_rank(mat,N)<N) cout<<"Even"<<endl;
	else cout<<"Odd"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
