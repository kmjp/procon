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

string S,T;
int LS,LT;
int ok[5002][5002];

void solve() {
	int i,j,k,l,r,x,y,y2; string s;
	
	cin>>S>>T;
	LS=S.size();
	LT=T.size();
	ok[0][0]=1;
	FOR(x,LS) {
		FOR(y,LT) if(ok[x][y]&&S[x]==T[y]) {
			if(ok[x+1][y+1]) continue;
			ok[x+1][y+1]=1;
			if(y<LT-1 && T[y]!=T[y+1]) {
				for(y2=y+2;y2<=LT;y2++) ok[x+1][y2]=1;
			}
		}
	}
	
	if(ok[LS][LT]) _P("Yes\n");
	else _P("No\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
