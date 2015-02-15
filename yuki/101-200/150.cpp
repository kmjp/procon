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

int T;
string S[500];

int dodo(string S) {
	int mi=1000000;
	int x,y;
	FOR(x,S.size()-2) FOR(y,S.size()-6) if(x+3<y) {
		int hoge=0;
		hoge+=S[x]!='g';
		hoge+=S[x+1]!='o';
		hoge+=S[x+2]!='o';
		hoge+=S[x+3]!='d';
		hoge+=S[y]!='p';
		hoge+=S[y+1]!='r';
		hoge+=S[y+2]!='o';
		hoge+=S[y+3]!='b';
		hoge+=S[y+4]!='l';
		hoge+=S[y+5]!='e';
		hoge+=S[y+6]!='m';
		mi=min(mi,hoge);
	}
	
	
	return mi;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>s;
		cout<<dodo(s)<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
