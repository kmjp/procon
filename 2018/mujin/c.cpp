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
string S[2020];
int L[2020][2020];
int R[2020][2020];
int U[2020][2020];
int D[2020][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	FOR(y,H) {
		for(x=1;x<W;x++) if(S[y][x-1]=='.') L[y][x]=L[y][x-1]+1;
		for(x=W-2;x>=0;x--) if(S[y][x+1]=='.') R[y][x]=R[y][x+1]+1;
	}
	FOR(x,W) {
		for(y=1;y<H;y++) if(S[y-1][x]=='.') U[y][x]=U[y-1][x]+1;
		for(y=H-2;y>=0;y--) if(S[y+1][x]=='.') D[y][x]=D[y+1][x]+1;
	}
	
	ll ret=0;
	FOR(y,H) FOR(x,W) if(S[y][x]=='.') ret+=(L[y][x]+R[y][x])*(U[y][x]+D[y][x]);
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
