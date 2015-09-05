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

int V,E,K;
int mat[21][21];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>V>>E>>K;
	FOR(i,E) {
		cin>>x>>y;
		mat[x][y]=mat[y][x]=1;
	}
	
	for(int mask=0;mask<1<<V;mask++) if(__builtin_popcount(mask)==K) {
		int ng=0;
		FOR(y,V) FOR(x,y) if(mat[x][y] && (mask&(1<<x))&&(mask&(1<<y))) ng++;
		if(ng) continue;
		FOR(x,V) if(mask&(1<<x)) _P("%d\n",x);
		return;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
