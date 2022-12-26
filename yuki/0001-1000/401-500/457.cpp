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

string S;
int L;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	L=S.size();
	
	int ret[2]={};
	
	FOR(x,L) if(S[x]=='(') {
		int A[3]={};
		for(y=x+1;y<L;y++) {
			if(S[y]=='^') A[1] |= A[0], A[0] = 1;
			if(S[y]=='*') A[2] |= A[1];
			if(S[y]==')') ret[0]+=A[2];
		}
	}
	
	for(x=L-1;x>=0;x--) if(S[x]==')') {
		int A[3]={};
		for(y=x-1;y>=0;y--) {
			if(S[y]=='^') A[1] |= A[0], A[0] = 1;
			if(S[y]=='*') A[2] |= A[1];
			if(S[y]=='(') ret[1]+=A[2];
		}
	}
	_P("%d %d\n",ret[0],ret[1]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
