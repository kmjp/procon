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
	int R=0,C=0;
	f=0;
	_P("150\n");
	FOR(y,13) {
		FOR(x,150) {
			if(x>=y*13 && x<y*13+13) _P("O"),f++;
			else _P(".");
		}
		_P("\n");
	}
	R=13;
	FOR(l,13) {
		FOR(y,13) {
			if(++R>150) break;
			C=0;
			FOR(x,13) {
				if(x==l)  _P("O"),f++;
				else _P(".");
			}
			C=13;
			int st=y;
			FOR(x,13) {
				//_P("|");
				FOR(i,13) {
					if(C++>=150) break;
					if(i==st) _P("O"),f++;
					else _P(".");
				}
				st+=l;
				st%=13;
			}
			_P("\n");
		}
	}
	//_P("%d\n",f);
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


