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

int N,M;
string S[300];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(y,N) cin>>S[y];
	FOR(y,N) FOR(x,N) if(S[y][x]=='Q') {
		int dy[3]={-1,0,1};
		int dx[3]={-1,0,1};
		FOR(i,3) FOR(j,3) if(i!=1 || j!=1) {
			int ty=y+dy[i];
			int tx=x+dx[j];
			if(ty>=0 && ty<N && tx>=0 && tx<N && S[ty][tx]=='.') S[ty][tx]='#';
			
		}
	}
	FOR(y,N) cout<<S[y]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
