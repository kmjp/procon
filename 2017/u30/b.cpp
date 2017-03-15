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

string S[9];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(y,9) {
		cin>>S[y];
		int mask=0;
		FORR(r,S[y]) r-='1', mask |= 1<<r;
		if(mask!=511) return _P("No\n");
	}
	FOR(x,9) {
		int mask=0;
		FOR(y,9) mask |= 1<<S[y][x];
		if(mask!=511) return _P("No\n");
	}
	FOR(y,9) FOR(x,9) {
		int dx[8]={-2,-1,1,2,2,1,-1,-2};
		int dy[8]={1,2,2,1,-1,-2,-2,-1};
		FOR(i,8) {
			if(x+dx[i]<0 || x+dx[i]>=9) continue;
			if(y+dy[i]<0 || y+dy[i]>=9) continue;
			if(S[y][x]==S[y+dy[i]][x+dx[i]]) return _P("No\n");
		}
		
	}
	
	_P("Yes\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
