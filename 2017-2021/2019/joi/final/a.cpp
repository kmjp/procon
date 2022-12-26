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
string S[3030];
int R[3030][3030];
int D[3030][3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	ll ret=0;
	FOR(y,H) cin>>S[y];
	for(y=H-1;y>=0;y--) {
		FOR(x,W) D[y][x]=D[y+1][x]+(S[y][x]=='I');
		for(x=W-1;x>=0;x--) R[y][x]=R[y][x+1]+(S[y][x]=='O');
		FOR(x,W) if(S[y][x]=='J') ret+=R[y][x]*D[y][x];
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
