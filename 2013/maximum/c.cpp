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

int N,NX,NY,QX,QY;

void solve() {
	int f,i,j,k,l,x,y;
	
	k=1;
	cin>>N>>NX>>NY>>QX>>QY;
	QX-=NX;
	QY-=NY;
	
	FOR(i,N-1) {
		int AX,AY,BX,BY;
		cin>>AX>>AY>>BX>>BY;
		AX-=NX;
		AY-=NY;
		BX-=NX;
		BY-=NY;
		
		if((AX*QY-AY*QX)==0 && (BX*QY-BY*QX)==0) {
			//par
			if(QX==0 && (min(AY,BY)>max(0,QY) || max(AY,BY)<min(0,QY))) continue;
			if(QX!=0 && (min(AX,BX)>max(0,QX) || max(AX,BX)<min(0,QX))) continue;
		}
		else {
			if((AX*QY-AY*QX)*(ll)(BX*QY-BY*QX)>0) continue;
			if((ll)((QX-AX)*(BY-AY)-(QY-AY)*(BX-AX))*((0-AX)*(BY-AY)-(0-AY)*(BX-AX))>0) continue;
		}
		k++;
	}
	_P("%d\n",k);
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}


