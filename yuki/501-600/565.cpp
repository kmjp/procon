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

int R,K;
int H,W;
char C[15][15];
char D[15][15];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>R>>K>>H>>W;
	FOR(y,H) cin>>C[y];
	
	FOR(i,R/90) {
		FOR(y,15) FOR(x,15) D[y][x]=C[y][x];
		swap(H,W);
		FOR(y,H) FOR(x,W) C[y][x]=D[W-1-x][y];
	}
	
	FOR(y,H) {
		FOR(i,K) {
			FOR(x,W) FOR(j,K) cout<<C[y][x];
			cout<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
