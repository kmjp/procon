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

int K,L;
void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>K>>L;
	
	if(L==1 && K==1) {
		_P("2 1\n1 2 1\n");
	}
	else if(L==2 && K<=49) {
		_P("50 97\n");
		_P("1 50 2\n");
		FOR(i,48) _P("1 %d 1\n",i+2);
		FOR(i,48) _P("%d 50 1\n",i+2);
	}
	else if(L==3 && K<=24*24) {
		_P("50 %d\n",24*26);
		FOR(i,24) _P("1 %d 1\n",i+2);
		FOR(i,24) FOR(j,24) _P("%d %d 1\n",i+2,j+26);
		FOR(i,24) _P("%d %d 1\n",i+26,50);
	}
	else if(L==4 && K<=16*16*16) {
		_P("50 %d\n",16*34);
		FOR(i,16) _P("1 %d 1\n",i+2);
		FOR(i,16) FOR(j,16) _P("%d %d 1\n",i+2,j+18);
		FOR(i,16) FOR(j,16) _P("%d %d 1\n",i+18,j+34);
		FOR(i,16) _P("%d %d 1\n",i+34,50);
	}
	else if((L==3 && K<=2402) || (L==4)){
		_P("50 %d\n",1225);
		_P("1 50 1\n",1);
		FOR(i,48) _P("1 %d 1\n",i+2);
		FOR(i,48) _P("%d 50 1\n",i+2);
		FOR(i,48) for(j=i+1;j<48;j++) _P("%d %d 1\n",i+2,j+2);
	}
	else if(L>=5) {
		_P("37 %d\n",5+5*10+100+100+10);
		FOR(i,5) {
			_P("1 %d %d\n",2+i,L-4);
			FOR(j,10) _P("%d %d 1\n",2+i,7+j);
		}
		FOR(i,10) FOR(j,10) _P("%d %d 1\n",7+i,17+j);
		FOR(i,10) FOR(j,10) _P("%d %d 1\n",17+i,27+j);
		FOR(i,10) _P("%d 37 1\n",27+i);
	}
	else {
		_P("-1\n");
	}
}


int main(int argc,char** argv){
	string s;
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


