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
#define _D(fmt, ...) printf("%10s %3d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
#define _DE(fmt, ...) fprintf(stderr, "%10s %3d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
#else
#define DBG(...)
#define DV(...)
#define _D(fmt, ...)
#define _DE(fmt, ...)
#endif

typedef signed long long ll;
typedef unsigned long long ull;

#define _PE(...) { printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__); }
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
ll GETi() { ll i;scanf("%lld",&i); return i;}
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------
int C[10];

struct Q {
	string st[9];
	string qst;
	int res[9];
	int hit[9],blow[9],sum[9];
};

Q qs[100];
string test="997508460";
int unused=0;
set<string> tested;

void comp(string& a1,string& a2,int& hit, int& blow) {
	int i,num[2][10];
	
	ZERO(num);
	hit=blow=0;
	FOR(i,9) {
		if(a1[i]==a2[i]) hit++;
		else { num[0][a1[i]-'0']++; num[1][a2[i]-'0']++;}
	}
	FOR(i,10) blow += min(num[0][i],num[1][i]);
}

int makeq(Q& q, string s1,string s2,string s3,string s4,string s5,string s6,string s7,string s8,string s9) {
	int i,x,y;
	q.st[0]=s1;	q.st[1]=s2;	q.st[2]=s3;
	q.st[3]=s4;	q.st[4]=s5;	q.st[5]=s6;
	q.st[6]=s7;	q.st[7]=s8;	q.st[8]=s9;
	FOR(x,9) tested.insert(q.st[x]);
	ZERO(q.res);
	_P("? %s %s %s %s %s %s %s %s %s\n",s1.c_str(),s2.c_str(),s3.c_str(),s4.c_str(),s5.c_str(),s6.c_str(),s7.c_str(),s8.c_str(),s9.c_str());
	fflush(stdout);
	FOR(i,9) x=GETi(),y=GETi(),q.res[i]=x*100+y;
	/*
	FOR(i,9) {
		int h,b;
		comp(q.st[i],test,h,b);
		q.res[i]=h*100+b;
	}
	*/
	sort(q.res,q.res+9);
	FOR(i,9) q.hit[i]=q.res[i]/100, q.blow[i]=q.res[i]%100, q.sum[i]=q.hit[i]+q.blow[i];
	return q.hit[8];
}

int ok(Q& q, string cor) {
	int i,h,b;
	int res[10];
	FOR(i,9) {
		comp(cor,q.st[i],h,b);
		res[i]=h*100+b;
	}
	sort(res,res+9);
	FOR(i,9) if(res[i] != q.res[i]) return 0;
	return 1;
}

void step0() {
	char result[10];
	char tmp[10][10];
	ZERO(result);
	int i,j;
	Q q;
	
	for(i=1;i<=8;i++) {
		ZERO(tmp);
		sprintf(tmp[0],"%d%d%d%d%d%d%d%d%d",i,0,0,0,0,0,0,0,0);
		sprintf(tmp[1],"%d%d%d%d%d%d%d%d%d",i,i,0,0,0,0,0,0,0);
		sprintf(tmp[2],"%d%d%d%d%d%d%d%d%d",i,i,i,0,0,0,0,0,0);
		sprintf(tmp[3],"%d%d%d%d%d%d%d%d%d",i,i,i,i,0,0,0,0,0);
		sprintf(tmp[4],"%d%d%d%d%d%d%d%d%d",i,i,i,i,i,0,0,0,0);
		sprintf(tmp[5],"%d%d%d%d%d%d%d%d%d",i,i,i,i,i,i,0,0,0);
		sprintf(tmp[6],"%d%d%d%d%d%d%d%d%d",i,i,i,i,i,i,i,0,0);
		sprintf(tmp[7],"%d%d%d%d%d%d%d%d%d",i,i,i,i,i,i,i,i,0);
		sprintf(tmp[8],"%d%d%d%d%d%d%d%d%d",i,i,i,i,i,i,i,i,i);
		makeq(q,tmp[0],tmp[1],tmp[2],tmp[3],tmp[4],tmp[5],tmp[6],tmp[7],tmp[8]);
		
		int preh=0;
		FOR(j,9) {
			if(preh != q.hit[j]) result[j]='0'+i;
			preh=q.hit[j];
		}
	}
	FOR(i,9) if(result[i]==0) result[i]='9';
	
	_P("! %s\n",result);
	fflush(stdout);
	exit(0);
}
int bitcount(int n) {
	int i=0;
	while(n>0) {i += n%2; n>>=1;}
	return i;
}

void stepok(Q& q) {
	Q qq;
	int loop,i,j,mask=0;
	char tmp[10][10];
	int okb[10],nok=0;
	
	nok=0;
	ZERO(tmp);
	FOR(i,9) {
		FOR(j,9) tmp[i][j]=unused+'0';
		if(strchr(q.st[i].c_str(),unused+'0')) continue;
		if(ok(q,q.st[i])) okb[nok++]=i;
	}
	
	FOR(loop,3) {
		FOR(i,9) tmp[i][0]=unused+'0';
		if(loop*3<nok) strcpy(tmp[0],q.st[okb[loop*3]].c_str());
		if(loop*3+1<nok) strcpy(tmp[1],q.st[okb[loop*3+1]].c_str());
		if(loop*3+1<nok) strcpy(tmp[2],q.st[okb[loop*3+1]].c_str());
		if(loop*3+1<nok) strcpy(tmp[3],q.st[okb[loop*3+1]].c_str());
		if(loop*3+2<nok) strcpy(tmp[4],q.st[okb[loop*3+2]].c_str());
		if(loop*3+2<nok) strcpy(tmp[5],q.st[okb[loop*3+2]].c_str());
		if(loop*3+2<nok) strcpy(tmp[6],q.st[okb[loop*3+2]].c_str());
		if(loop*3+2<nok) strcpy(tmp[7],q.st[okb[loop*3+2]].c_str());
		if(loop*3+2<nok) strcpy(tmp[8],q.st[okb[loop*3+2]].c_str());
		FOR(i,9) {
			if(strchr(tmp[i],unused+'0')){
				repeat:
				FOR(j,9) tmp[i][j]='0'+((mask & (1<<j))?unused:0);
				mask++;
				if(tested.find(tmp[i])!=tested.end()) goto repeat;
			}
			else {
				tmp[i][i]=unused+'0';
			}
		}
		
		makeq(qq,tmp[0],tmp[1],tmp[2],tmp[3],tmp[4],tmp[5],tmp[6],tmp[7],tmp[8]);
		if(qq.hit[4]==8) _P("! %s\n",q.st[okb[loop*3+2]].c_str()), exit(0);
		if(qq.hit[6]==8) _P("! %s\n",q.st[okb[loop*3+1]].c_str()), exit(0);
		if(qq.hit[8]==8) _P("! %s\n",q.st[okb[loop*3]].c_str()),  exit(0);
	}
}


void solve() {
	int x,y,i,j,TM,nc,res[10];
	
	makeq(qs[0],"000000000","123456789","234567891","345678912","456789123","567891234","678912345","789123456","891234567");
	C[0]=qs[0].sum[0];
	for(x=1;x<=8;x++) if(qs[0].sum[x] != qs[0].sum[(x+1)%9] && qs[0].sum[x] != qs[0].sum[(x+2)%9]) C[0]=qs[0].sum[x];
	if(C[0]==9) {
		_P("! 000000000\n");
		fflush(stdout);
		return;
	}
	if(C[0]==0) {
		step0();
		return;
	}
	
	ZERO(res);
	makeq(qs[1],"111111111","222222220","222222202","222222022","033333333","303333333","330333333","333033333","333303333");
	FOR(i,9) res[qs[1].sum[i]]++;
	FOR(i,10) if(res[i]>=5) C[3]=i-1,res[i]-=5;
	FOR(i,10) if(res[i]>=3) C[2]=i-1,res[i]-=3;
	FOR(i,10) if(res[i]>=1) C[1]=i,res[i]-=1;
	
	ZERO(res);
	makeq(qs[2],"444444444","555555550","555555505","555555055","066666666","606666666","660666666","666066666","666606666");
	FOR(i,9) res[qs[2].sum[i]]++;
	FOR(i,10) if(res[i]>=5) C[6]=i-1,res[i]-=5;
	FOR(i,10) if(res[i]>=3) C[5]=i-1,res[i]-=3;
	FOR(i,10) if(res[i]>=1) C[4]=i,res[i]-=1;
	
	ZERO(res);
	makeq(qs[3],"777777777","888888880","888888808","888888088","099999999","909999999","990999999","999099999","999909999");
	FOR(i,9) res[qs[3].sum[i]]++;
	FOR(i,10) if(res[i]>=5) C[9]=i-1,res[i]-=5;
	FOR(i,10) if(res[i]>=3) C[8]=i-1,res[i]-=3;
	FOR(i,10) if(res[i]>=1) C[7]=i,res[i]-=1;
	char ress[10];
	ZERO(ress);
	x=0;
	FOR(i,10) {
		y=C[i];
		if(y==0) unused=i;
		while(y--) ress[x++] = '0'+i;
	}
	if(qs[0].hit[8]==9) stepok(qs[0]);
	if(qs[1].hit[8]==9) stepok(qs[1]);
	if(qs[2].hit[8]==9) stepok(qs[2]);
	if(qs[3].hit[8]==9) stepok(qs[3]);
	string ss = string(ress);
	string cand[10];
	int num=0;
	int numq=4;
	int ng;
	do {
		ng = 0;
		FOR(i,numq) if(!ok(qs[i],ss)) ng=1;
		if(ng) continue;
		cand[num++]=ss;
		if(num>=9) {
			makeq(qs[numq],cand[0],cand[1],cand[2],cand[3],cand[4],cand[5],cand[6],cand[7],cand[8]);
			if(qs[numq].hit[8]==9) {
				stepok(qs[numq]);
				return;
			}
			numq++;
			num=0;
		}
		
	} while(next_permutation(ss.begin(),ss.end()));
	
	for(i=num;i<9;i++) {
		char tmp[10];
		strcpy(tmp,"000000000");
		tmp[i]=unused+'0';
		cand[i]=string(tmp);
	}
	
	makeq(qs[numq],cand[0],cand[1],cand[2],cand[3],cand[4],cand[5],cand[6],cand[7],cand[8]);
	if(qs[numq].hit[8]==9) stepok(qs[numq]);
	
	return;
}

int main(int argc,char** argv){
	struct timeval start,end,ts;
	//if(argc>1) freopen(argv[1], "r", stdin);
	if(argc>1) test=argv[1];
	int i,j;
	char tmp[10];
	gettimeofday(&start,NULL);	solve();	gettimeofday(&end,NULL);
	ll span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	//_E("**Total time: %lld ms\n",span/1000);
	return 0;
}


