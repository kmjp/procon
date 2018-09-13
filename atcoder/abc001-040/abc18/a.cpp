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

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>i>>j>>k;
	if(k<i && k<j && j<i) _P("1\n2\n3\n");
	if(k<i && k<j && j>i) _P("2\n1\n3\n");
	if(i<j && i<k && j<k) _P("3\n2\n1\n");
	if(i<j && i<k && j>k) _P("3\n1\n2\n");
	if(j<i && j<k && i<k) _P("2\n3\n1\n");
	if(j<i && j<k && i>k) _P("1\n3\n2\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
