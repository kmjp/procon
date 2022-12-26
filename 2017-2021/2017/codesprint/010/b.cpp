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
int pat[102][102];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(pat);
	cin>>N;
	FOR(i,N) {
		cin>>j;
		pat[0][j]=pat[101][j]=1;
		FOR(x,102) FOR(y,102) {
			if(x>y&&y<j) pat[y][j]=max(pat[y][j],pat[x][y]+1);
			if(x<y&&y>j) pat[y][j]=max(pat[y][j],pat[x][y]+1);
		}
	}
	int ret=N;
	FOR(x,102) FOR(y,102) ret=min(ret,N-pat[x][y]);
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
