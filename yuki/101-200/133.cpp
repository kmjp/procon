#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int A[10],B[10],C[10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	
	double ret=0,tot=1;
	FOR(i,N) C[i]=i,tot*=i+1;
	
	do {
		int wa=0,wb=0;
		FOR(i,N) if(A[i]>B[C[i]]) wa++;
		FOR(i,N) if(A[i]<B[C[i]]) wb++;
		if(wa>wb) ret++;
	} while(next_permutation(C,C+N));
	
	_P("%.12lf\n",ret/tot);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
