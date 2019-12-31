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
int ok2[5002][5002];
set<int> cand[2][5002];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T;
	LS=S.size();
	LT=T.size();
	for(x=LT-1;x>=0;x--) {
		ok[x][x]=1;
		for(y=x+1;y<LT;y++) if(ok[x][y-1] && T[x]!=T[y]) {
			ok[x][y]=1;
			int y2;
			for(y2=y+1;y2<LT;y2++) {
				if(ok[y][y2]) ok[x][y2]=1;
				else break;
			}
			y=y2-1;
		}
	}
	if(S[0]!=T[0]) return _P("No\n");
	ok2[0][0]=1;
	cand[1][0].insert(0);
	
	FOR(x,LS) {
		if(x==LS-1) cand[0][x+1].insert(LT);
		else {
			for(y=x+1;y<=LT-(LS-1-x);y++) {
				if(S[x+1]==T[y]) cand[0][x+1].insert(y);
			}
		}
		ITR(it,cand[1][x]) {
			set<int>::iterator it2=cand[0][x+1].lower_bound(*it);
			while(it2!=cand[0][x+1].end()) {
				if(ok[*it][*it2-1]) {
					ok2[x+1][*it2] = 1;
					cand[1][x+1].insert(*it2);
					it2=cand[0][x+1].erase(it2);
				}
				else {
					it2++;
				}
			}
		}
	}
	
	if(ok2[LS][LT]) _P("Yes\n");
	else _P("No\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
