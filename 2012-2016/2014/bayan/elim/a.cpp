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

int T,N;
int C[4],S[102];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	FOR(i,T) {
		cin>>N;
		cin>>s;
		
		ZERO(C);
		ITR(it,s) if(*it=='R') C[0]++;
		ITR(it,s) if(*it=='P') C[1]++;
		ITR(it,s) if(*it=='S') C[2]++;
		
		ZERO(S);
		S[C[2]]+=C[0];
		S[C[1]]+=C[2];
		S[C[0]]+=C[1];
		for(x=100;x>=0;x--) if(S[x]) {
			_P("Case #%d:\n%d\n",i+1,S[x]);
			break;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
