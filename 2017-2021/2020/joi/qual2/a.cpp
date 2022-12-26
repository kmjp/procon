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


int N;
string S[4][500];
string T[500];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) cin>>S[0][y];
	FOR(y,N) cin>>T[y];
	FOR(i,3) {
		FOR(y,N) S[i+1][y].resize(N);
		FOR(y,N) FOR(x,N) S[i+1][y][x]=S[i][N-1-x][y];
	}
	int mi=1010100;
	FOR(i,4) {
		int add=min(i,4-i);
		FOR(y,N) FOR(x,N) if(T[y][x]!=S[i][y][x]) add++;
		mi=min(mi,add);
	}
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
