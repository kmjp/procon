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

int V[202][202];
int N,M;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S;
	FOR(y,N+1) FOR(x,N+1) V[y][x]=1;
	x=y=0;
	V[0][0]=0;
	FORR(s,S) {
		if(s=='U') y++;
		if(s=='D') y--;
		if(s=='R') x++;
		if(s=='L') x--;
		if(0<=x&&x<=N&&0<=y&&y<=N) V[y][x]=0;
	}
	
	for(y=N;y>=0;y--) {
		FOR(x,N+1) cout<<V[y][x]<<" ";
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
