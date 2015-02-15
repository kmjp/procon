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
#include <assert.h>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

#define DEBUG
#ifdef DEBUG
#define DBG(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define DV(...) cerr << __VA_ARGS__ << endl
#define _D(fmt, ...) printf("%10s %3d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
#define _DE(fmt, ...) fprintf(stderr, "%10s %3d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
#else
#define DBG(...)
#define DV(...)
#define _D(fmt, ...)
#define _DE(fmt, ...)
#endif

typedef signed long long s64;
typedef unsigned long long u64;

#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
#undef _P
#define _P(...) printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define GETs(x) scanf("%s",x);
int GETi() { int i;scanf("%d",&i); return i;}
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);
#define SIGN(n) (n==0?0:(n>0 ? 1 : -1))
#define ABS(n) ((n)<0?(-(n)):(n))

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int K;
char S[5005];
char mm[]="48cd3f9h1jklmn0pqr57uvwxyz";
int nm[52][52];
char strm[]="abcdefghijklmnopqrstuvwxyz48cd3f9h1jklmn0pqr57uvwxyz";

int nlist;
struct li {
	int n;
	int f,e;
	char list[36*36];
};
li lists[10000];

void dfs(li* tli) {
	int i,j,x;
	x=tli->list[tli->n-1];
	FOR(i,52) {
		if(nm[x][i]) {
			nm[x][i]=0;
			tli->list[tli->n++]=i;
			dfs(tli);
			return;
		}
	}
	return;
}


void split() {
	int i,j,candi,candj;
	li tli;
	
	nlist=0;
	ZERO(lists);
	
	while(1){
		candi=-1;
		FOR(i,52) {
			FOR(j,52) {
				if(nm[i][j]) {
					candi=i;
					candj=j;
					goto out;
				}
			}
		}
		if(candi==-1) break;
		out:
		nm[i][j]=0;
		tli.n=2;
		tli.list[0]=i;
		tli.list[1]=j;
		dfs(&tli);
		lists[nlist++]=tli;
		//_P("\n");
		
	}
	
	
}

int merge(int s,int t) {
	char mem[36*36];
	int i,j,k,tt;
	tt=0;
	//æ“ª
	if(lists[s].f==lists[t].e) {
		FOR(i,lists[t].n) {
			mem[i]=lists[t].list[i];
		}
		FOR(i,lists[s].n-1) {
			mem[lists[t].n+i]=lists[s].list[i+1];
		}
		memmove(lists[s].list,mem,lists[s].n+lists[t].n-1);
		lists[s].n += lists[t].n-1;
		tt=1;
		goto okok;
	}
	//––”ö
	if(lists[s].e==lists[t].f) {
		FOR(i,lists[t].n-1) {
			lists[s].list[lists[s].n+i]=lists[t].list[i+1];
		}
		lists[s].n += lists[t].n-1;
		tt=2;
		goto okok;
	}
	//’†‚P•¶Žš
	if(lists[t].f==lists[t].e) {
		j=-1;
		FOR(i,lists[s].n) {
			if(lists[s].list[i]==lists[t].f){
				j=i;
				break;
			}
		}
		if(j>=0) {
			FOR(i,j) {
				mem[i]=lists[s].list[i];
			}
			FOR(i,lists[t].n) {
				mem[j+i]=lists[t].list[i];
			}
			for(i=j+1;i<lists[s].n;i++) {
				mem[j-1+lists[t].n+i]=lists[s].list[i];
			}
			memmove(lists[s].list,mem,lists[s].n+lists[t].n-1);
			lists[s].n += lists[t].n-1;
			tt=3;
			goto okok;
		}
	}
	//’†‚Q•¶Žš
	FOR(i,lists[s].n-1) {
		if(lists[s].list[i]!=lists[t].f) break;
		if(lists[s].list[i+1]==lists[t].e){
			int k,l;
			FOR(k,i) {
				mem[k]=lists[s].list[k];
			}
			FOR(k,lists[t].n) {
				mem[k+i]=lists[t].list[k];
			}
			for(k=i+1;k<lists[s].n;k++) {
				mem[k-2+lists[t].n+i]=lists[s].list[k];
			}
			memmove(lists[s].list,mem,lists[s].n+lists[t].n-2);
			lists[s].n += lists[t].n-2;
			tt=4;
			goto okok;
		}
	}
	
	
	return 0;
	okok:
	lists[s].f=lists[s].list[0];
	lists[s].e=lists[s].list[lists[s].n-1];
	return tt;
	
	
}

void solve(int _loop) {
	int i,j,k,result,dir,ok,state,fstate,up,x,y,sp,dist1,dist2;
	int wid,hei;
	double res,tres;
	
	K=GETi();
	GETs(S);
	ZERO(nm);
	FOR(i,strlen(S)-1) {
		nm[S[i]-'a'][S[i+1]-'a']++;
		if(mm[S[i]-'a']==2) {
			nm[26+S[i]-'a'][S[i+1]-'a']++;
		}
		if(mm[S[i+1]-'a']==2) {
			nm[S[i]-'a'][26+S[i+1]-'a']++;
		}
		if(mm[S[i]-'a']==2 && mm[S[i+1]-'a']==2) {
			nm[26+S[i]-'a'][26+S[i+1]-'a']++;
		}
	}
	
	split();
	
	while(1){
		ret:
		FOR(i,nlist) {
			lists[i].f = lists[i].list[0];
			lists[i].e = lists[i].list[lists[i].n-1];
			_P("%d %d %c %c %d :",i,nlist,strm[lists[i].f],strm[lists[i].e],lists[i].n);
			FOR(j,lists[i].n) {_P("%c",strm[lists[i].list[j]]);}
			_P("\n");
		}
		FOR(i,nlist) {
			FOR(j,nlist) {
				if(i==j) continue;
				int t=merge(i,j);
				if(t) {
					_P("merge(%d)! %d %d\n",t,i,j);
					lists[j]=lists[nlist-1];
					nlist--;
					goto ret;
				}
			}
		}
		break;
	}
	FOR(i,nlist) {
		lists[i].f = lists[i].list[0];
		lists[i].e = lists[i].list[lists[i].n-1];
		_P("%d %c %c %d :",i,strm[lists[i].f],strm[lists[i].e],lists[i].n);
		FOR(j,lists[i].n) _P("%c",strm[lists[i].list[j]]);
		_P("\n");
	}
	int r=0;
	FOR(i,nlist) {
		r+=lists[i].n;
	}
	
	//connect();
	
	
	
	_PE("Case #%d: %d\n",_loop,r);
	
	
	
}

void init() {
	int i;
	FOR(i,strlen(mm)) {
		mm[i]=(mm[i]>='0' && mm[i]<='9') ? 2 :1 ;
	}
}

int main(int argc,char** argv){
	int loop,loops;
	long long span;
	char tmpline[1000];
	struct timeval start,end,ts;
	
	if(argc>1) {
		freopen(argv[1], "r", stdin);
	}
	
	gettimeofday(&ts,NULL);
	
	GET1(&loops);
	gets(tmpline);
	init();
	
	if(loops>1000) {
		_E("loops is over 1000\n");
		return 0;
	}
	
	for(loop=1;loop<=loops;loop++) {
		gettimeofday(&start,NULL);
		solve(loop);
		gettimeofday(&end,NULL);
		span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
		_E("                                     time: %lld ms\n",span/1000);
	}
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	_E("**Total time: %lld ms\n",span/1000);
	
	return 0;
	
}



