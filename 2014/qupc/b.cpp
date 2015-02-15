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
	cin>>x;
	string s;
	
	if(x/100==0) s+="Nil";
	if(x/100==1) s+="Un";
	if(x/100==2) s+="Bi";
	if(x/100==3) s+="Tri";
	if(x/100==4) s+="Quad";
	if(x/100==5) s+="Pent";
	if(x/100==6) s+="Hex";
	if(x/100==7) s+="Sept";
	if(x/100==8) s+="Oct";
	if(x/100==9) s+="Enn";
	if(x/10%10==0) s+="nil";
	if(x/10%10==1) s+="un";
	if(x/10%10==2) s+="bi";
	if(x/10%10==3) s+="tri";
	if(x/10%10==4) s+="quad";
	if(x/10%10==5) s+="pent";
	if(x/10%10==6) s+="hex";
	if(x/10%10==7) s+="sept";
	if(x/10%10==8) s+="oct";
	if(x/10%10==9) s+="enn";
	if(x%10==0) s+="nilium";
	if(x%10==1) s+="unium";
	if(x%10==2) s+="bium";
	if(x%10==3) s+="trium";
	if(x%10==4) s+="quadium";
	if(x%10==5) s+="pentium";
	if(x%10==6) s+="hexium";
	if(x%10==7) s+="septium";
	if(x%10==8) s+="octium";
	if(x%10==9) s+="ennium";
	
	FOR(i,s.size()) {
		if(i<s.size()-2 && s[i]=='n' && s[i+1]=='n' && s[i+2]=='n') continue;
		_P("%c",s[i]);
	}
	_P("\n");
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


