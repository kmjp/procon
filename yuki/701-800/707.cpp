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
int A[55][55];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	for(y=1;y<=H;y++) {
		cin>>s;
		for(x=1;x<=W;x++) if(s[x-1]=='1') A[y][x]=1;
	}
	
	long double mi=1e9;
	FOR(y,H+2) FOR(x,W+2) {
		if(y!=0 && y!=H+1 && x!=0 && x!=W+1) continue;
		long double tot=0;
		int ty,tx;
		FOR(ty,H+2) FOR(tx,W+2) if(A[ty][tx]) tot+=hypot(ty-y,tx-x);
		mi=min(mi,tot);
	}
	_P("%.12lf\n",(double)mi);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
