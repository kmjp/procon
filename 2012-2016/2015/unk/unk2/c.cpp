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

int H,W;
string S[51];
string T[51];

int num() {
	int x,y,ret=0;
	FOR(y,H) {
		int ok=1;
		FOR(x,W-1) if(T[y][x]!=T[y][x+1]) ok=0;
		ret+=ok;
	}
	FOR(x,W) {
		int ok=1;
		FOR(y,H-1) if(T[y][x]!=T[y+1][x]) ok=0;
		ret+=ok;
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y,ret=0;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	
	// all zero
	FOR(y,H) {
		T[y]=S[y];
		FOR(x,W) if(T[y][x]=='?') T[y][x]='0';
	}
	ret=max(ret,num());
	
	// all one
	FOR(y,H) {
		T[y]=S[y];
		FOR(x,W) if(T[y][x]=='?') T[y][x]='1';
	}
	ret=max(ret,num());
	// col
	FOR(y,H) T[y]=S[y];
	FOR(x,W) {
		char hoge='0';
		FOR(y,H) if(T[y][x]!='?') hoge=T[y][x];
		FOR(y,H) if(T[y][x]=='?') T[y][x]=hoge;
	}
	ret=max(ret,num());
	// row
	FOR(y,H) {
		T[y]=S[y];
		char hoge='0';
		FOR(x,W) if(T[y][x]!='?') hoge=T[y][x];
		FOR(x,W) if(T[y][x]=='?') T[y][x]=hoge;
	}
	ret=max(ret,num());
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
