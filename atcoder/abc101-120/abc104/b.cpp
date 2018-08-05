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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	string S;
	cin>>S;
	int N=S.size();
	
	if(S[0]!='A') return _P("WA\n");
	S[0]='a';
	int C=0;
	for(i=2;i<N-1;i++) if(S[i]=='C') C++, S[i]='c';
	if(C!=1) return _P("WA\n");
	FORR(c,S) {
		if(c>='A' && c<='Z') return _P("WA\n");
	}
	_P("AC\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
