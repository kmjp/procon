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
string S[50];
int A[51],B[51],C[51];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FORR(c,S[y]) {
			if(c=='W') A[y]++;
			if(c=='B') B[y]++;
			if(c=='R') C[y]++;
		}
	}
	int mi=101010;
	for(x=1;x<=H;x++) for(y=1;x+y<H;y++) {
		int z=H-x-y;
		int fix=0;
		FOR(i,H) {
			if(i<x) fix+=B[i]+C[i];
			else if(i<x+y) fix+=A[i]+C[i];
			else fix+=A[i]+B[i];
		}
		mi=min(mi,fix);
	}
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
