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
int A[10],B[10],C[10],D[10];
string R[10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i]>>B[i]>>C[i]>>D[i]>>R[i];
	FOR(x,10) {
		int ok=1;
		FOR(i,N) {
			int inc=(A[i]==x) || (B[i]==x) || (C[i]==x) || (D[i]==x);
			if(inc && R[i]=="NO") ok=0;
			if(!inc && R[i]=="YES") ok=0;
		}
		
		if(ok) return _P("%d\n",x);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
