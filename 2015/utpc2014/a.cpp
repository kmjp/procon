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

char SS[5050];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	gets(SS);
	l=strlen(SS);
	if(SS[l-1]=='\n') SS[--l]=0;
	for(x=l;x>=0;x--) {
		if(x&&SS[x-1]!=' ') continue;
		if(memcmp(SS+x,"not not not ",12)==0) continue;
		if(memcmp(SS+x,"not not not",11)==0 && SS[x+11]==0) continue;
		if(memcmp(SS+x,"not not ",8)==0) {
			for(y=x+8;y<l+10;y++) SS[y-8]=SS[y];
			l-=8;
			x--;
		}
	}
	_P("%s\n",SS);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
