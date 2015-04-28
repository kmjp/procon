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

string S,T;
int N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>S>>N>>T;
	
	if(N==0) {
		if(S!=T) return _P("SUCCESS\n");
	}
	else if(N==1) {
		string S1=S.substr(0,1)+S.substr(2,1)+S.substr(1,1);
		string S2=S.substr(1,1)+S.substr(0,1)+S.substr(2,1);
		if(S1!=T && S2!=T) return _P("SUCCESS\n");
	}
	else {
		x=count(S.begin(),S.end(),'o');
		y=count(T.begin(),T.end(),'o');
		if(x!=y) return _P("SUCCESS\n");
	}
	return _P("FAILURE\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
