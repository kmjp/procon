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

int H,W,Q;
int A[501][501];
int S[501][501];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) cin>>A[y][x];
	cin>>Q;
	FOR(i,2*Q) {
		int y1,x1,y2,x2;
		cin>>y1>>y2>>x1>>x2;
		y1--;
		x1--;
		S[y1][x1]^=1;
		S[y1][x2]^=1;
		S[y2][x1]^=1;
		S[y2][x2]^=1;
	}
	ll sum=0;
	FOR(y,H) FOR(x,W) {
		if(y) S[y][x]^=S[y-1][x];
		if(x) S[y][x]^=S[y][x-1];
		if(y&&x) S[y][x]^=S[y-1][x-1];
		if(S[y][x]) sum+=A[y][x];
	}
	cout<<sum<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
