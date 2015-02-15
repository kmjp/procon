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

int NP;
const int prime_max = 10000000;
int p[prime_max];
int cc;

void cprime() {
	int i,j;
	NP=0;
	for(i=2;i<prime_max;i++) {
		if(p[i]) continue;
		for(j=i*2;j<prime_max;j+=i) p[j]=i;
	}
}

void solve() {
	int f,i,j,k,l,x,y;
	
	cprime();
	/* check
	for(x=1;x<=100;x++) {
		int n=x;
		y=n*n-n+41+n/41*8040+n/54*239676-n/64*232386-n/76*630+n/87*224976;
		_P((p[y])?"x":"o");
	}
	_P("\n");
	*/
	for(i=1;i<=1000000;i+=2) {
		int vis[100];
		int ma=0,c=0;
		for(x=1;x<=100;x++) {
			y=x*x-x+i;
			vis[x-1]=p[y];
			if(vis[x-1]) c=0;
			else ma=max(ma,++c);
		}
		if(ma>=11) {
			_P("%8d : %d :",i,ma);
			FOR(x,100) _P((vis[x])?" ":"o");
			_P("|\n");
		}
	}
}

/*
      41 :****************************************  oo oooo oooooo oooooooo oooooooooo oooo  o oo o o oooo ooo|
    8081 :o ooooo  oo ooo oooooo  ooooooo oo oo   *************  oo oo oooo oo o  o  ooooooooo o ooo o oo o oo|
  247757 : o o  oooo ooo o oooo  ooo  oo ooo oo  oo o oo oo oo **********oo  oo ooooo ooo    o  **************|
   14741 :o oo oooooo ooo o ooo    ooo  ooo  oo ooo oo oo ooooo    o  oo o oo oo ooo ******@@@@@    ooo       |
   15371 : ooooooooo  o o o   o ooo ooo ooooooo  ooo  o  o  o oooo  ooo  ************  o  o     o   o   oo ooo|
*/
int main(int argc,char** argv){
	solve();
	
	return 0;
}


