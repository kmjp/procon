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

int H,W;

string S[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	
	y=x=0;
	while(1) {
		S[y][x]='.';
		if(y==H-1 && x==W-1) break;
		if(x<W-1 && S[y][x+1]=='#') {
			x++;
		}
		else if(y<H-1 && S[y+1][x]=='#') {
			y++;
		}
		else {
			return _P("Impossible\n");
		}
	}
	FOR(y,H) FOR(x,W) if(S[y][x]=='#') return _P("Impossible\n");
	
	_P("Possible\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
