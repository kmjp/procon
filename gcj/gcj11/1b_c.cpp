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


int N,M;
vector< vector<int> > P;
int U[2001],V[2001];
int VM[2001][2001];
int COL[2001];
int done[2001];
int mc;

void split(int l,int u,int v) {
	vector<int> V[2];
	int i,s;
	
	s=0;
	FOR(i,P[l].size()) {
		if(P[l][i]==u || P[l][i]==v) {
			V[0].push_back(P[l][i]);
			V[1].push_back(P[l][i]);
			s=1-s;
		}
		else {
			V[s].push_back(P[l][i]);
		}
	}
	P[l]=V[0];
	P.push_back(V[1]);
}

void setcol(int F,int v1,int v2) {
	int sv,t;
	int c1,c2,c,pv1,pv2;
	
	
	//_P("%d :",F);
	FOR(sv,P[F].size()) {
		//_P("%d ",P[F][sv]);
		if(P[F][sv]==v1) pv1=sv;
		if(P[F][sv]==v2) pv2=sv;
	}
	//_P("\n");
	if((pv2+1)%P[F].size()==pv1) {
		t=pv2;
		pv2=pv1;
		pv1=t;
		v1=P[F][pv1];
		v2=P[F][pv2];
	}
	c1=COL[v1];
	c2=COL[v2];
	//_P("(P[%d]=%d(col:%d)-P[%d]=%d(col:%d)\n",pv1,v1,COL[v1],pv2,v2,COL[v2]);
	
	c=0;
	FOR(t,P[F].size()-2) {
		//1周目はc1,c2以外から使う
		while(c == COL[P[F][(pv2+2+t)%P[F].size()]] ||
		      c == COL[P[F][(pv2+0+t)%P[F].size()]] ||
		      c == c1 || c==c2) {
			c = (c+1)%mc;
			if(c==0) c1=c2=-1;
			
		}
		int v = P[F][(pv2+1+t)%P[F].size()];
		
		if(COL[v]!=-1) _P("NG %d\n",v);
		//_P("OK %d %d %d\n",t,v,c);
		COL[v]=c;
		c = (c+1)%mc;
		if(c==0) c1=c2=-1;
	}
	
}

void dfs(int F) {
	int i,v1,v2,nf;
	
	done[F]=1;
	//_P("%d\n",F);
	
	//隣接するやつを探す
	FOR(i,P[F].size()) {
		v1 = P[F][i];
		v2 = P[F][(i+1)%P[F].size()];
		if(VM[v1][v2]==-1) continue;
		nf = VM[v1][v2] % 10000;
		if(nf==F) nf=VM[v1][v2] / 10000;
		if(done[nf]) continue;
		setcol(nf,v1,v2);
		dfs(nf);
	}
	
}

void solve(int _loop) {
	int i,j,k,result,res,dir,ok,state,fstate,up,x,y,sp,dist1,dist2;
	int wid,hei,mv,mi;
	double br,tb1,tb2,start,end;
	
	
	GET2(&N,&M);
	FOR(i,M) {
		U[i] = GETi()-1;
	}
	FOR(i,M) {
		V[i] = GETi()-1;
	}
	
	P.clear();
	P.resize(1);
	
	FOR(i,N) {
		P[0].push_back(i);
		COL[i]=-1;
	}
	
	FOR(i,M) {
		FOR(j,P.size()) {
			int nv=0;
			FOR(k,P[j].size()) {
				if(P[j][k]==U[i]) nv++;
				if(P[j][k]==V[i]) nv++;
			}
			
			if(nv==2) {
				split(j,U[i],V[i]);
				break;
			}
		}
		
	}
	
	mc = 9999;
	MINUS(VM);
	MINUS(COL);
	FOR(i,P.size()) {
		if(P[i].size() < mc) mc =P[i].size();
		FOR(j,P[i].size()) {
			for(k=j+1;k<P[i].size();k++) {
				int u=P[i][j], v=P[i][k];
				if(((u-v+N)%N)!=1 && ((u-v+N)%N)!=N-1) {
					if(VM[u][v]==-1) VM[u][v]=i;
					else VM[u][v]+=i*10000;
					if(VM[v][u]==-1) VM[v][u]=i;
					else VM[v][u]+=i*10000;
				}
			}
		}
	}
	
	ZERO(done);
	FOR(i,P.size()) {
		if(P[i].size()==mc) {
			FOR(j,P[i].size()){
				COL[P[i][j]]=j;
				//_P("OK %d %d\n",P[i][j],j);
			}
			done[i]=1;
			dfs(i);
			break;
		}
	}
	
	_PE("Case #%d: %d\n",_loop,mc);
	FOR(i,N) {
		_PE("%d ",COL[i]+1);
	}
	_PE("\n");
	
	//check;
	FOR(i,P.size()) {
		/* smallのみの全色利用チェック
		int m;
		m=0;
		FOR(j,P[i].size()) m |= 1<<COL[P[i][j]];
		if(m!=(1<<mc)-1) {_PE("***%d %d\n",i,m);}
		*/
		FOR(j,P[i].size()) if(COL[P[i][j]]==COL[P[i][(j+1)%P[i].size()]]) {_PE("****%d %d %d %d\n",i,j,P[i][j],(j+1)%P[i].size());}
		
	}
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



