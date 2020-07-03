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

int A[4][4];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(y,4) FOR(x,4) cin>>A[y][x];
		
	int ng=0;
	FOR(i,1010) {
		FOR(y,4) FOR(x,4) if(A[y][x]==0) {
			int must=y*4+x+1;
			FOR(j,4) {
				int dd[4]={1,0,-1,0};
				int ty=y+dd[j],tx=x+dd[j^1];
				if(tx<0 || tx>3 || ty<0 || ty>3) continue;
				if(A[ty][tx]==must) {
					swap(A[y][x],A[ty][tx]);
					break;
				}
			}
			break;
		}
	}
	
	FOR(y,4) FOR(x,4) if(A[y][x]!=(y*4+x+1)%16) return _P("No\n");
	_P("Yes\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
