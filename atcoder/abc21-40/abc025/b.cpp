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

int N,A,B,X;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B;
	while(N--) {
		cin>>s>>x;
		x=min(B,max(A,x));
		if(s[0]=='E') X+=x;
		else X-=x;
	}
	
	if(X==0) _P("0\n");
	if(X>0) _P("East %d\n",X);
	if(X<0) _P("West %d\n",-X);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
