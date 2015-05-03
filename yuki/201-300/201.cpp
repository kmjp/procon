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

string S[2],A[2],X[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,2) cin>>S[i]>>A[i]>>X[i];
	if(A[0].size()>A[1].size()) return _P("%s\n",S[0].c_str());
	if(A[1].size()>A[0].size()) return _P("%s\n",S[1].c_str());
	if(A[0]>A[1]) return _P("%s\n",S[0].c_str());
	if(A[1]>A[0]) return _P("%s\n",S[1].c_str());
	_P("-1\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
