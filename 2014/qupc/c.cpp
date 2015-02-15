#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

int W,H;
int X[256],Y[256];
int Q;

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>H>>W>>Q;
	FOR(x,256) X[x]=Y[x]=-1;
	FOR(y,H) {
		string s;
		cin>>s;
		FOR(x,W) X[s[x]]=x,Y[s[x]]=y;
	}
	
	while(Q--) {
		string s;
		cin>>s;
		if(X[s[0]]==-1) _P("NA\n");
		else _P("%d %d\n",Y[s[0]]+1,X[s[0]]+1);
	}
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


