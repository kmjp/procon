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

int V[4];
int A,B,C;

int memo[51];

int dodo(int D) {
	if(D==0) return 0;
	if(D<0) return 1000;
	if(memo[D]>=0) return memo[D];
	return memo[D]=1+min(min(dodo(D-A),dodo(D-B)),dodo(D-C));
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>V[0]>>V[1]>>V[2]>>V[3];
	int mi=V[0]+V[1]+V[2]+V[3];
	
	for(A=1;A<=30;A++) for(B=A+1;B<=30;B++) for(C=B+1;C<=30;C++) {
		MINUS(memo);
		mi=min(mi,dodo(V[0])+dodo(V[1])+dodo(V[2])+dodo(V[3]));
	}
	cout << mi << endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
