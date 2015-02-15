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

typedef signed long long ll;
typedef unsigned long long ull;

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

vector<ll> list;
int C[102][102];
vector<string> str[201];

int parp(char* str) {
	int i,l;
	l=strlen(str);
	if(l==1) return (str[0]=='1' ||str[0]=='4' || str[0]=='9');
	FOR(i,l) if(str[i]!=str[l-1-i]) return 0;
	return 1;
}

void enums(int keta) {
	char s[300];
	int i,x,y,z,l;
	ZERO(s);
	FOR(i,keta) s[i]='0';
	
	if(keta%2==1) {
		// top=2
		s[0]=s[keta-1]='2';
		str[keta*2-1].push_back(s);
		s[(keta-1)/2]='1';
		str[keta*2-1].push_back(s);
		
		// top=1 mid=2
		s[0]=s[keta-1]='1';
		s[(keta-1)/2]='2';
		str[keta*2-1].push_back(s);
		for(i=1;i<keta/2;i++) {
			s[i]=s[keta-1-i]='1';
			str[keta*2-1].push_back(s);
			s[i]=s[keta-1-i]='0';
		}
		
		FOR(l,2) {
			s[(keta-1)/2]='0'+l;
			
			str[keta*2-1].push_back(s);
			for(x=1;x<keta/2;x++) {
				s[x]=s[keta-1-x]='1';
				str[keta*2-1].push_back(s);
				for(y=x+1;y<keta/2;y++) {
					s[y]=s[keta-1-y]='1';
					str[keta*2-1].push_back(s);
					for(z=y+1;z<keta/2;z++) {
						s[z]=s[keta-1-z]='1';
						str[keta*2-1].push_back(s);
						s[z]=s[keta-1-z]='0';
					}
					s[y]=s[keta-1-y]='0';
				}
				s[x]=s[keta-1-x]='0';
			}
		}
	}
	else {
		// top=2 mid=0
		s[0]=s[keta-1]='2';
		str[keta*2-1].push_back(s);
		
		// top=1 mid=2
		s[0]=s[keta-1]='1';
		str[keta*2-1].push_back(s);
		for(x=1;x<keta/2;x++) {
			s[x]=s[keta-1-x]='1';
			str[keta*2-1].push_back(s);
			for(y=x+1;y<keta/2;y++) {
				s[y]=s[keta-1-y]='1';
				str[keta*2-1].push_back(s);
				for(z=y+1;z<keta/2;z++) {
					s[z]=s[keta-1-z]='1';
					str[keta*2-1].push_back(s);
					s[z]=s[keta-1-z]='0';
				}
				s[y]=s[keta-1-y]='0';
			}
			s[x]=s[keta-1-x]='0';
		}
	}
	
	// square
	s[keta*2-1]=0;
	FOR(i,str[keta*2-1].size()) {
		FOR(x,keta*2-1) s[x]='0';
		FOR(x,keta) {
			if(str[keta*2-1][i][x]!='0') FOR(y,keta) s[(keta*2-2)-(x+y)]+=(str[keta*2-1][i][keta-1-x]-'0')*(str[keta*2-1][i][keta-1-y]-'0');
		}
		str[keta*2-1][i]=s;
	}
	
	sort(str[keta*2-1].begin(),str[keta*2-1].end());
}

int enumk(int keta) {
	int num;
	if(keta==1) return 3;
	if(keta%2==1) {
		num = 2; // top=2,mid=0,1
		// top=1,mid=0,1,left=0,1,2,3
		num += 2*(C[(keta-3)/2][0]+C[(keta-3)/2][1]+C[(keta-3)/2][2]+C[(keta-3)/2][3]);
		// top=1,mid=2,left=0,1
		num += (C[(keta-3)/2][0]+C[(keta-3)/2][1]);
	}
	else {
		num = 1; // top=2, mid=0
		// top=1,left=0,1,2,3
		num += C[(keta-2)/2][0]+C[(keta-2)/2][1]+C[(keta-2)/2][2]+C[(keta-2)/2][3];
	}
	return num;
	
}

int num(char *st, int inc) {
	int l=strlen(st);
	int n=0,i;
	
	FOR(i,l) n+=str[i].size();
	FOR(i,str[l].size()) {
		if((inc && str[l][i]>st) || (!inc && str[l][i]>=st)) break;
		n++;
	}
	return n;
}


ll A,B;

void solve(int _loop) {
	char A[200];
	char B[200];
	
	GETs(A);
	GETs(B);
	_PE("Case #%d: %d\n",_loop,num(B,1)-num(A,0));
}

void init() {
	ll i;
	int x,y;
	ZERO(C);
	FOR(x,101) C[x][0]=C[x][x]=1;
	for(x=1;x<=100;x++) for(y=1;y<x;y++) C[x][y]=C[x-1][y-1]+C[x-1][y];
	
	str[1].push_back("1");
	str[1].push_back("4");
	str[1].push_back("9");
	
	for(x=2;x<=51;x++) {
		enums(x);
		//FOR(y,str[x*2-1].size()) _P(" %d %d %s\n",x*2-1,y,str[x*2-1][y].c_str());
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



