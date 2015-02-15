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

int N,M,Q;
int A[1500],B[1500],C[1500];
int QA,QB,QC;
int pat[300][300];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>A[i]>>B[i]>>C[i];
		A[i]--,B[i]--;
		FOR(x,C[i]) FOR(y,x+1) pat[A[i]+x][B[i]+y]=1;
	}
	
	cin>>Q;
	while(Q--) {
		ll ret=0;
		cin>>QA>>QB>>QC;
		QA--,QB--;
		FOR(x,QC) FOR(y,x+1) ret+=pat[QA+x][QB+y]==0;
		cout<<ret<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
