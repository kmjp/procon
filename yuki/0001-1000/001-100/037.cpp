#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T,N;
int C[101],V[101],VS[101][14];
int DP[16][10010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T>>N;
	FOR(i,N) cin>>C[i];
	FOR(i,N) {
		cin>>V[i];
		FOR(j,13) {
			VS[i][j+1]=VS[i][j]+V[i];
			V[i]/=2;
		}
		FOR(j,T+1) FOR(x,11) if(j+x*C[i]<=T)
			DP[i+1][j+x*C[i]]=max(DP[i+1][j+x*C[i]],DP[i][j]+VS[i][x]);
	}
	cout << *max_element(DP[N],DP[N]+T+1) << endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
