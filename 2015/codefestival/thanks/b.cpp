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

int A[2][2];
int C;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A[0][0]>>A[0][1];
	cin>>A[1][0]>>A[1][1];
	cin>>C;
	set<int> R;
	FOR(i,2) FOR(j,2) {
		if(A[0][i]==C) R.insert(A[1][j]);
		if(A[1][j]==C) R.insert(A[0][i]);
	}
	_P("%d\n",R.size());
	FORR(r,R) _P("%d\n",r);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
