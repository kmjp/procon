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

int N;
double X[40],Y[40],R[40];
char line[1000];
double dist[40][40],minr[40][40];
double vecx[40][40],vecy[40][40];
int Map[40];

int getcenter(double rad,int n1,int n2,double* x1,double* y1,double* x2,double* y2) {
	double d,e,r1,r2,xt,yt,h;
	int i,j;
	
	
	if(rad < minr[n1][n2]+0.0000001) return 0;
	if(minr[n1][n2]<rad+0.0000001 && minr[n1][n2]>rad-0.0000001){
		d=rad-R[n1];
		*x1 = X[n1] + d*vecx[n1][n2];
		*y1 = Y[n1] + d*vecy[n1][n2];
		return 1;
	}
	d=dist[n1][n2];
	r1=rad-R[n1];
	r2=rad-R[n2];

	e=(d*d+r1*r1-r2*r2)/(2*d);
	h=r1*r1-e*e;
	
	if(h<0.0) return 0;
	h=sqrt(h);
	xt=X[n1] + e*vecx[n1][n2];
	yt=Y[n1] + e*vecy[n1][n2];
	*x1=xt - h*vecy[n1][n2];
	*y1=yt + h*vecx[n1][n2];
	*x2=xt + h*vecy[n1][n2];
	*y2=yt - h*vecx[n1][n2];
	//if(n1==1 && n2==2) _E("%f %f %f %f %f   [%f %f][%f %f] \n",d,e,h,r1,r2,*x1,*y1,*x2,*y2);
	return 2;
	
}

int cover1(double rad, int* cMap) {
	int num,i,ok;
	int n1,n2,k;
	double d,e,r1,r2,xt,yt,h;
	double x1,x2,y1,y2,x,y;
	
	num=0;
	FOR(i,N) {
		if(Map[i]==0) num++;
	}
	if(num==0 || num==1) return 1;
	
	FOR(n1,N-1) {
		for(n2=n1+1;n2<N;n2++) {
			if(Map[n1] || Map[n2]) continue;
			
			num = getcenter(rad,n1,n2,&x1,&y1,&x2,&y2);
			//_E("okok %d %d %d  %f %d %d %d %d\n",n1,n2,num,rad,Map[0],Map[1],Map[2],Map[3]);
			if(num>=1) {
				ok=1;
				FOR(k,N) {
					if(k==n1 || k==n2 || Map[k]) continue;
					//if(k==0 & n1==1 && n2==2) _E("test1 %f %f %f %f %f %f\n",X[k],Y[k],R[k],x1,y1,rad);
					if(sqr(X[k]-x1)+sqr(Y[k]-y1) > sqr(rad-R[k])-EPS) {
						ok=0;
						break;
					}
				}
				if(ok){
					//_E("num2 okok %d %d %d  %f %f %f\n",n1,n2,num,rad,x1,y1);
					return 1;
				}
			}
			if(num>=2) {
				ok=1;
				FOR(k,N) {
					if(k==n1 || k==n2 || Map[k]) continue;
					//if(k==0 & n1==1 && n2==2) _E("test2 %f %f %f %f %f %f\n",X[k],Y[k],R[k],x2,y2,rad);
					if((X[k]-x2)*(X[k]-x2)+(Y[k]-y2)*(Y[k]-y2) > (rad-R[k])*(rad-R[k])-EPS) {
						ok=0;
						break;
					}
				}
				if(ok){
					//_E("num2 okok %d %d %d  %f %f %f\n",n1,n2,num,rad,x2,y2);
					return 1;
				}
			}
			
		}
	}
	return 0;
	
}

int cover2(double rad,int n1, int n2) {
	int num,i,j,ok;
	double d,e,r1,r2,xt,yt,h;
	double x1,x2,y1,y2,x,y;
	
	num = getcenter(rad,n1,n2,&x1,&y1,&x2,&y2);
	if(num>=1) {
		ZERO(Map);
		FOR(i,N) {
			if(i==n1 || i==n2) Map[i]=1;
			else {
				if((X[i]-x1)*(X[i]-x1)+(Y[i]-y1)*(Y[i]-y1) < (rad-R[i])*(rad-R[i])+EPS)
					Map[i]=1;
			}
		}
		//_E("cv21 %d %d %f %f %f %d %d %d %d %d %d %d %d \n",n1,n2,rad,x1,y1,Map[0],Map[1],Map[2],Map[3],Map[4],Map[5],Map[6],Map[7]);
		ok=cover1(rad,Map);
		if(ok) return 1;
	} 
	if(num>=2) {
		ZERO(Map);
		FOR(i,N) {
			if(i==n1 || i==n2) Map[i]=1;
			else {
				if((X[i]-x2)*(X[i]-x2)+(Y[i]-y2)*(Y[i]-y2) < (rad-R[i])*(rad-R[i])+EPS)
					Map[i]=1;
			}
		}
		//_E("cv22 %d %d %f %f %f %d %d %d %d %d %d %d %d \n",n1,n2,rad,x2,y2,Map[0],Map[1],Map[2],Map[3],Map[4],Map[5],Map[6],Map[7]);
		ok=cover1(rad,Map);
		if(ok) return 1;
	}
	
	return 0;
}

int cover(double rad) {
	int i,j,ok;
	//¬‚³‚·‚¬‚ÍƒAƒEƒg
	FOR(i,N) {
		if(rad < R[i]) return 0;
	}
	
	//1ŒÂ‚Æ39ŒÂ
	FOR(i,N) {
		ZERO(Map);
		Map[i]=1;
		ok=cover1(rad,Map);
		if(ok){
			//_E("cover1 ok! %f %d\n",rad,i);
			return 1;
		}
	}
	//2ŒÂ‚Æ‚»‚Ì‘¼
	FOR(i,N-1) {
		for(j=i+1;j<N;j++) {
			ok = cover2(rad,i,j);
			if(ok){
			//	_E("cover2 ok! %f %d %d\n",rad,i,j);
				return 1;
			}
		}
	}
	//_E("cover1&2 failed! %f %d\n",rad,i);
	return 0;
}

void solve(int _loop) {
	int i,j,k,result,dir,ok;
	double br,tb1,tb2,start,end;
	
	GET1(&N);
	start=0.0;
	FOR(i,N) {
		X[i]=GETi();
		Y[i]=GETi();
		R[i]=GETi();
		if(R[i]>start) start=R[i];
	}
	FOR(i,N) {
		FOR(j,N) {
			dist[i][j] = sqrt((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]));
			minr[i][j] = (dist[i][j]+R[i]+R[j])/2.0;
			if(i!=j) {
				vecx[i][j]=(X[j]-X[i])/dist[i][j];
				vecy[i][j]=(Y[j]-Y[i])/dist[i][j];
			}
		}
	}
	
	end=9999.0;
	while(end-start > 0.0000005) {
		br = (start+end)/2.0;
		ok=cover(br);
		if(ok) {
			end = br;
		}
		else start = br;
		//_E("biun %f %f %d\n",start,end,ok);
	}
	
	
	_PE("Case #%d: %.7f\n",_loop,br);
	
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



