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

char hoge[30][30];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int W,H,D;
	cin>>W>>H>>D;
	FOR(y,25) FOR(x,25) hoge[y][x]=' ';
	
	hoge[0][D+1]='+';
	hoge[0][D+1+W+1]='+';
	hoge[H+1][D+1+W+1]='+';
	hoge[D+1][0]='+';
	hoge[D+1][W+1]='+';
	hoge[D+2+H][0]='+';
	hoge[D+2+H][W+1]='+';
	
	FOR(x,W) hoge[0][D+2+x]=hoge[D+1][1+x]=hoge[D+2+H][1+x]='-';
	FOR(y,H) hoge[1+y][W+D+2]=hoge[D+2+y][0]=hoge[D+2+y][W+1]='|';
	FOR(i,D) hoge[D-i][i+1]=hoge[D-i][i+1+W+1]=hoge[D-i+H+1][i+1+W+1]='/';
	
	FOR(y,3+D+H) cout<<hoge[y]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
