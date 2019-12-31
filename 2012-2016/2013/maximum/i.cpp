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

int L,H,W;
string M[10];

int can(int cx,int cy,ll mask,int dir,int step) {
	
	if(mask == (1LL<<((H-2)*(W-2)))-1) return 1;
	int i,j,r;
	int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
	
	FOR(i,4) {
		int ty=cy+dy[i],tx=cx+dx[i],ng=0;
		if(tx<=0 || ty<=0 || tx>=W-1 || ty>=H-1 || i==(dir^1)) continue;
		if(mask&(1LL<<((ty-1)*(W-2)+(tx-1)))) ng=1;
		if(M[ty][tx]>='2' && M[ty][tx]<='9' && (L-(M[ty][tx]-'0'))>step) ng=1;
		if(ng) continue;
		if(can(tx,ty,mask | (1LL<<((ty-1)*(W-2)+(tx-1))),i,step+1)) return 1;
	}
	return 0;
}


void solve() {
	int f,i,j,k,l,x,y,sx,sy,px,py;
	
	while(1) {
		cin>>L>>H>>W;
		if(L==0) return;
		ll lm=0;
		string path("*",L);
		FOR(y,H) {
			cin>>M[y];
			for(x=1;x<W-1;x++) {
				if(y!=0 && y!=H-1) {
					if((M[y][x]=='#' || M[y][x]=='1')) lm |= 1LL<<((y-1)*(W-2)+(x-1));
					if(M[y][x]=='1') sx=x,sy=y;
					if(M[y][x]=='2') px=x,py=y;
				}
			}
		}
		int pdir=0;
		if(sx<px) pdir=0;
		if(sx>px) pdir=1;
		if(sy<py) pdir=2;
		if(sy>py) pdir=3;
		
		if(can(sx,sy,lm,pdir,0)) _P("Yes\n");
		else _P("No\n");
	}
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}


