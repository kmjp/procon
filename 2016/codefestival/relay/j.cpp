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
string S[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) {
		FOR(x,N) S[y]+="#."[(x+y)&1];
	}
	
	int ret=0;
	FOR(y,N) if(S[y][0]=='.') S[y][0]='*', ret++;
	FOR(x,N) if(S[N-1][x]=='.') S[N-1][x]='*', ret++;
	for(y=1;y<N;y+=3) {
		for(x=1;x<N;x++) if(S[y][x]=='.') S[y][x]='*', ret++;
	}
	
	_P("%d\n",ret);
	FOR(y,N) FOR(x,N) if(S[y][x]=='*') _P("%d %d\n",x,y);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
