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

int A,B;
int D,E;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&A,&B);
	E=0;
	i=scanf(" UTC%d.%d",&D,&E);
	A-=9;
	A+=D;
	if(D>=0) {
		if(E) B+=6*E;
	}
	else {
		if(E) B-=6*E;
	}
	if(B>=60) B-=60,A++;
	if(B<0) B+=60,A--;
	
	while(A>=24) A-=24;
	while(A<0) A+=24;
	_P("%02d:%02d\n",A,B);
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
