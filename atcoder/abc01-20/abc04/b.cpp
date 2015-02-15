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

void solve() {
	int f,i,j,k,l,x,y;
	string S[16];
	
	FOR(i,16) cin>>S[i];
	
	_P("%s %s %s %s\n",S[15].c_str(),S[14].c_str(),S[13].c_str(),S[12].c_str());
	_P("%s %s %s %s\n",S[11].c_str(),S[10].c_str(),S[9].c_str(),S[8].c_str());
	_P("%s %s %s %s\n",S[7].c_str(),S[6].c_str(),S[5].c_str(),S[4].c_str());
	_P("%s %s %s %s\n",S[3].c_str(),S[2].c_str(),S[1].c_str(),S[0].c_str());
	
	
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


