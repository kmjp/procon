#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int A,B;
char ho[10];
void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>A>>B;
	FOR(i,10) ho[i]='x';
	FOR(i,A) cin>>x, ho[x]='.';
	FOR(i,B) cin>>x, ho[x]='o';	
	
	_P("%c %c %c %c\n",ho[7],ho[8],ho[9],ho[0]);
	_P(" %c %c %c\n",ho[4],ho[5],ho[6]);
	_P("  %c %c\n",ho[2],ho[3]);
	_P("   %c\n",ho[1]);
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


