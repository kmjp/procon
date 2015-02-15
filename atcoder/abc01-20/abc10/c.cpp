#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
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
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int TX[2],TY[2],T,V;
int N;
int X[1001],Y[1001];

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>TX[0]>>TY[0]>>TX[1]>>TY[1]>>T>>V;
	cin>>N;
	FOR(i,N) {
		cin>>x>>y;
		if(sqrt((x-TX[0])*(x-TX[0])+(y-TY[0])*(y-TY[0]))+
		   sqrt((x-TX[1])*(x-TX[1])+(y-TY[1])*(y-TY[1]))<=T*V) return _P("YES\n");
		
	}
	return _P("NO\n");
	
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


