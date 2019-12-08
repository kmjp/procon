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
int A[80][80];

bitset<160*176> B[80][80];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) cin>>A[y][x];
	FOR(y,H) FOR(x,W) {
		cin>>r;
		A[y][x]=abs(A[y][x]-r);
	}
	B[0][0][80*165+A[0][0]]=1;
	FOR(y,H) FOR(x,W) {
		if(y+1<H) {
			B[y+1][x] |= B[y][x]<<A[y+1][x];
			B[y+1][x] |= B[y][x]>>A[y+1][x];
		}
		if(x+1<W) {
			B[y][x+1] |= B[y][x]<<A[y][x+1];
			B[y][x+1] |= B[y][x]>>A[y][x+1];
		}
	}
	
	int mi=101010;
	FOR(i,160*176) if(B[H-1][W-1][i]) mi=min(mi,abs(i-80*165));
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
