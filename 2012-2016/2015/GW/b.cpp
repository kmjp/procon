#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

const int d=1000;
int hoge[d*2][d*2];
ll N;
int pat[21000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	x=y=0;
	j=0;
	FOR(i,20000) {
		int dy[4]={1,0,-1,0};
		int dx[4]={0,1,0,-1};
		
		if(hoge[y+d][x+d]) j=(j+3)%4;
		else j=(j+1)%4;
		
		hoge[y+d][x+d]^=1;
		x+=dx[j];
		y+=dy[j];
		
		pat[i+1]=hoge[y+d][x+d];
	}
	
	if(N<=20000) _P("%d\n",pat[N]);
	else _P("%d\n",pat[18960 + (N-18960)%104]);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
