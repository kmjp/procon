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

int N,M;
int A[1010];

string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N>>M;
	FOR(i,N) S+=' ';
	FOR(i,N) S[i]=i+1;
	FOR(i,M) {
		cin>>x;
		if(x==N) S=S.substr(x-1,1) + S.substr(0,x-1);
		else S=S.substr(x-1,1) + S.substr(0,x-1) + S.substr(x);
	}
	_P("%d\n",S[0]);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
