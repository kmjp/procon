#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

set<string> S;
char hoge[1000];

void solve() {
	int i,j,k,l,r,x,y; string s,t;
	
	x=0;
	gets(hoge);
	FOR(i,strlen(hoge)) {
		char c=hoge[i];
		if(c==' ') {
			S.insert(t);
			t="";
			x=0;
		}
		else if(c=='@') {
			S.insert(t);
			t="";
			x=1;
		}
		else if(x) t+=c;
	}
	S.insert(t);
	ITR(it,S) if(it->size()) cout<<*it<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
