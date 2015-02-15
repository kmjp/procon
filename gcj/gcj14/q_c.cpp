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
#include <sys/time.h>
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


void solve(int _loop) {
	int f,i,j,k,l,x,y;
	char hoge[51][51];
	int R,C,M,L;
	
	cin>>R>>C>>M;
	L=R*C-M;
	
	ZERO(hoge);
	FOR(y,R) FOR(x,C) hoge[y][x]='*';
	
	_P("Case #%d:\n",_loop);
	
	if(L==1) {
		hoge[0][0]='c';
		FOR(y,R) _P("%s\n",hoge[y]);
		return;
	}
	else if(R==1) {
		if(M>=C-1) _P("Impossible\n");
		else {
			FOR(i,M) _P("*");
			FOR(i,C-1-M) _P(".");
			_P("c\n");
		}
	}
	else if(C==1) {
		if(M>=R-1) _P("Impossible\n");
		else {
			FOR(i,M) _P("*\n");
			FOR(i,R-1-M) _P(".\n");
			_P("c\n");
		}
	}
	else {
		if(L<=3) _P("Impossible\n");
		else {
			
			int CC,RR,ok=0;;
			for(RR=2;RR<=R;RR++) for(CC=2;CC<=C;CC++) {
				if(RR*CC==L) {
					FOR(y,RR) FOR(x,CC) hoge[y][x]='.';
					ok=1;
				}
				else if(RR*CC<=L && RR<R && (RR+1)*CC>L && L%CC>1 && RR>1) {
					FOR(y,RR) FOR(x,CC) hoge[y][x]='.';
					FOR(x,L%CC) hoge[RR][x]='.';
					ok=1;
				}
				else if(RR*CC<=L && RR<R && (RR+1)*CC>L && L%CC==1 && RR>2 && CC>2) {
					FOR(y,RR) FOR(x,CC) hoge[y][x]='.';
					hoge[RR-1][CC-1]='*';
					hoge[RR][0]=hoge[RR][1]='.';
					ok=1;
				}
				else if(RR*CC<=L && CC<C && (CC+1)*RR>L && L%RR>1 && CC>1) {
					FOR(y,RR) FOR(x,CC) hoge[y][x]='.';
					FOR(y,L%RR) hoge[y][CC]='.';
					ok=1;
				}
				else if(RR*CC<=L && CC<C && (CC+1)*RR>L && L%RR==1 && CC>2 && RR>2) {
					FOR(y,RR) FOR(x,CC) hoge[y][x]='.';
					hoge[RR-1][CC-1]='*';
					hoge[0][CC]=hoge[1][CC]='.';
					ok=1;
				}
				if(ok) {
					hoge[0][0]='c';
					FOR(y,R) _P("%s\n",hoge[y]);
					return;
				}
			}
			_P("Impossible\n");
		}
	}
	
	
}

void init() {
}

int main(int argc,char** argv){
	int loop,loops;
	long long span;
	char tmpline[1000];
	struct timeval start,end,ts;
	
	if(argc>1) freopen(argv[1], "r", stdin);
	gettimeofday(&ts,NULL);
	cin>>loops;
	init();
	
	for(loop=1;loop<=loops;loop++) {
		gettimeofday(&start,NULL); solve(loop); gettimeofday(&end,NULL);
		span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
		fprintf(stderr,"Case : %d                                     time: %lld ms\n",loop,span/1000);
	}
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	fprintf(stderr,"**Total time: %lld ms\n",span/1000);
	
	return 0;
}


