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
int ret[101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	if(N==2) return _P("-1\n");
	if(N%2==1) {
		FOR(y,N) FOR(x,N-1) _P("%d%c",(x+y+1)%N+1,(x==N-2)?'\n':' ');
	}
	else {
		FOR(y,N) FOR(x,N-1) {
			if(y>=N/2 && x==N/2-1) _P("%d%c",(x+y+2)%N+1,(x==N-2)?'\n':' ');
			else if(y>=N/2 && x==N/2) _P("%d%c",(x+y)%N+1,(x==N-2)?'\n':' ');
			else _P("%d%c",(x+y+1)%N+1,(x==N-2)?'\n':' ');
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
