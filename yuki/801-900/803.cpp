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

int N,M,X;
int A[303];
const int MAT=402;
int mat1[402][402];
int mat2[402][402];
ll mo=1000000007;

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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>X;
	FOR(i,N) cin>>A[i];
	FOR(i,30) {
		FOR(j,N) if(A[j]&(1<<i)) mat1[i][j]=mat2[i][j]=1;
		if(X&(1<<i)) mat2[i][N]=1;
	}
	FOR(i,M) {
		cin>>r>>x>>y;
		x--,y--;
		for(j=x;j<=y;j++) mat1[30+i][j]=mat2[30+i][j]=1;
		mat2[30+i][N]=r;
	}
	
	int r1=gf2_rank(mat1,402);
	int r2=gf2_rank(mat2,402);
	if(r1!=r2) return _P("0\n");
	ll ret=1;
	FOR(i,N-r1) ret=ret*2%mo;
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
