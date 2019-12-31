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
string S[101];
int sum[10101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W>>H;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) sum[x+1][y]=sum[x][y]+(S[y][x]=='W');
	}
	
	int id=0,mi=1010100;
	FOR(x,W+1) {
		int ret=0;
		FOR(y,H) ret += (x-sum[x][y]) + (sum[W][y]-sum[x][y]);
		if(ret<mi) id=x, mi=ret;
	}
	cout<<id<<" "<<id+1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
