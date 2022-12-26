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

int nex[26][26];
int is[26];
int N,M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>s;
		FORR(c,s) c-='A', is[c]=1;
		FOR(j,s.size()-1) nex[s[j]][s[j+1]]=1;
	}
	
	cin>>M;
	FOR(i,M) {
		cin>>s;
		FORR(c,s) c-='A', is[c]=1;
		FOR(j,s.size()-1) nex[s[j]][s[j+1]]=1;
	}
	
	int first=-1;
	FOR(i,26) if(is[i]) {
		x=0;
		FOR(j,26) if(nex[j][i]) x++;
		if(x>1) return _P("-1\n");
		if(x==0) {
			if(first>=0) return _P("-1\n");
			first=i;
		}
	}
	
	while(1) {
		_P("%c",first+'A');
		x=-1;
		FOR(j,26) if(nex[first][j]) x=j;
		first=x;
		if(first==-1) break;
	}
	_P("\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
