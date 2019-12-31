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

int W,H,X,Y,R;
char hoge[51][60];

int ins(int x,int y) {
	if((X-x)*(X-x)+(Y-y)*(Y-y)<R*R) return 1;
	return 0;
}
int bor(int x,int y) {
	if((X-x)*(X-x)+(Y-y)*(Y-y)==R*R) return 1;
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W>>H>>X>>Y>>R;
	FOR(y,H) {
		FOR(x,W) {
			i = ins(x,y)+ins(x,y+1)+ins(x+1,y)+ins(x+1,y+1);
			j = bor(x,y)+bor(x,y+1)+bor(x+1,y)+bor(x+1,y+1);
			if(i!=0 && 4-i-j!=0) hoge[y][x]='#';
			else hoge[y][x]='.';
		}
		_P("%s\n",hoge[y]);
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
