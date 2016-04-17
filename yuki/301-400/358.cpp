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

int A[3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A[0]>>A[1]>>A[2];
	int ret=0;
	for(i=1;i<=100101;i++) {
		int a=A[0]%i;
		int b=A[1]%i;
		int c=A[2]%i;
		if(a<b && c<b & a!=c) ret++;
		if(a>b && c>b & a!=c) ret++;
	}
	if(ret>40000) _P("INF\n");
	else _P("%d\n",ret);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
