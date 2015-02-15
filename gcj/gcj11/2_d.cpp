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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

#define DEBUG
#ifdef DEBUG
#define DBG(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define DV(...) cerr << __VA_ARGS__ << endl
#else
#define DBG(...)
#define DV(...)
#endif


#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
#define _Dm(fmt) fprintf(stderr, "%s %d : " fmt,__FUNCTION__,__LINE__)
#define _D(fmt, ...) fprintf(stderr, "%s %d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
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

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------


int P,W;
int X[2001],Y[2001];
int D[401];
int mat[401][401];
int nmat[401];
int mat2[401][401];
int DV[401][401];
int T[401];


/* t‚Ì—×‚Å‚ ‚Á‚Ät‚âs‚Ì—×‚Å‚È‚¢‚à‚Ì */
int uniqn(int r,int s,int t) {
	int c = 0;
	int ri,si,ti;
	ri=si=ti=0;
	while(ti<nmat[t]) {
		while(ri<nmat[r] && mat[r][ri]<mat[t][ti]) ri++;
		while(si<nmat[s] && mat[s][si]<mat[t][ti]) si++;
		
		if((ri>=nmat[r] || mat[t][ti]!=mat[r][ri]) && (si>=nmat[s] || mat[t][ti]!=mat[s][si]) && mat[t][ti]!=r && mat[t][ti]!=s) {
			//_P("(AA %d)",mat[t][ti]);
			c++;
		}
		ti++;
	}
	//_P("(%d %d %d %d)",r,s,t,c);
	return c;
}

/* s->t‚Å‘‚¦‚é“_ */
int newt(int s,int t) {
	/* r->s->t ‚Å DV[s][t]=DV[r][s]+G[r][s][t] */
	int i,r,c,tc;
	
	if(DV[s][t]==-1) {
		
		c=0;
		if(s==0) {
			c = T[0]+uniqn(0,0,t);
		}
		else {
			FOR(i,nmat[s]) {
				r = mat[s][i];
				if(D[r]!=D[s]-1) continue;
				if(DV[r][s]==-1) _P("assert!!\n");
				
				tc = DV[r][s]+uniqn(r,s,t);
				if(c<tc) c = tc;
			}
		}
		
		DV[s][t]=c;
	}
	//_P("(%d,%d=%d)\n",s,t,DV[s][t]);
	return DV[s][t];
}

void gett(){
	int i;
	deque<int> q;
	
	q.clear();
	FOR(i,P) D[i]=99999;
	D[0]=0;
	q.push_back(0);
	
	ZERO(T);
	T[0]=1+nmat[0];
	
	while(!q.empty()) {
		int key = q.front();
		q.pop_front();
		
		FOR(i,nmat[key]) {
			int tar = mat[key][i];
			if(D[tar]>D[key]+1) {
				D[tar] = D[key]+1;
				q.push_back(tar);
			}
			if(D[tar]==D[key]+1) {
				int t = newt(key,tar);
				if(T[tar]<t) T[tar]=t;
			}
		}
	}
	//FOR(i,P) _P("%d\n",T[i]);
}

void solve(int _loop) {
	int i,j,k,result,res,dir,ok,state,fstate,up,x,y,sp,dist1,dist2;
	int wid,hei,mv,mi;
	double br,tb1,tb2,start,end;
	
	ZERO(mat);
	ZERO(mat2);
	ZERO(nmat);
	GET2(&P,&W);
	
	FOR(i,W) {
		scanf("%d,%d", &X[i],&Y[i]);
		mat[X[i]][nmat[X[i]]++]=Y[i];
		mat[Y[i]][nmat[Y[i]]++]=X[i];
		mat2[X[i]][Y[i]]=1;
		mat2[Y[i]][X[i]]=1;
	}
	FOR(i,P) sort(&mat[i][0],&mat[i][nmat[i]]);
	
	//‹——£
	MINUS(DV);
	gett();
	
	int resd = D[1]-1;
	int mt = 0;
	FOR(i,P) if(D[i]==resd && mat2[i][1]==1 && T[i]>mt) mt=T[i];
	//FOR(i,P) _P("(%d:%d,%d) ",i,D[i],T[i]);
	//’Ê‚Á‚½“_‚ðˆø‚­
	mt-=resd+1;
	_PE("Case #%d: %d %d\n",_loop,resd,mt);
}

void init() {
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



