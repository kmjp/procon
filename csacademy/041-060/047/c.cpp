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
ll A[303][303];
ll R[303],C[303];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) cin>>A[y][x];
	FOR(y,H) {
		R[y]=A[y][0];
		for(x=1;x<W;x++) {
			R[y]*=A[y][x]/__gcd(R[y],A[y][x]);
			if(R[y]>1000000000) return _P("-1\n");
		}
	}
	FOR(x,W) {
		C[x]=A[0][x];
		for(y=1;y<H;y++) {
			C[x]*=A[y][x]/__gcd(C[x],A[y][x]);
			if(C[x]>1000000000) return _P("-1\n");
		}
	}
	
	FOR(y,H) FOR(x,W) if(__gcd(R[y],C[x])!=A[y][x]) return _P("-1\n");
	
	FOR(y,H) _P("%d%c",R[y],(y==H-1)?'\n':' ');
	FOR(x,W) _P("%d%c",C[x],(x==W-1)?'\n':' ');
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
