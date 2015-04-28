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

int H,W;
string S[100];

void solve() {
	int i,j,k,l,r,x,y; string s;

	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	FOR(y,H) {
		FOR(x,W) if(S[y][x]=='.') {
			S[y][x]='0';
			for(int tx=x-1;tx<=x+1;tx++) for(int ty=y-1;ty<=y+1;ty++)
				if(tx>=0 && tx<W && ty>=0 && ty<H && S[ty][tx]=='#') S[y][x]++;
			if(S[y][x]=='0') S[y][x]='.';
		}
	}
	FOR(y,H) cout << S[y]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
