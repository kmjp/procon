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


int N;
string A[303],B[303],C[303];

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		FORR(c,A[i]) c-='0';
		C[i].resize(N,0);
	}
	FOR(i,N) {
		cin>>B[i];
		FORR(c,B[i]) c-='0';
	}
	FOR(y,N) FOR(z,N) {
		int ok=1;
		FOR(x,N) if(A[x][y]==1 && B[x][z]==0) ok=0;
		C[y][z]=ok;
	}
	
	FOR(x,N) FOR(z,N) {
		int ok=0;
		FOR(y,N) if(A[x][y]&&C[y][z]) ok=1;
		if(B[x][z]!=ok) return _P("-1\n");
	}
	FOR(x,N) {
		FORR(c,C[x]) c+='0';
		cout<<C[x]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
