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
#include <unistd.h>

typedef signed long long ll;
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

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

ll B,L,N;
struct tree {
	int ci
	int cl;
	int di;
	int dl;
	int numr;
	vector<int> ID;
};

int NT=0;
tree T[10001];
vector<int> PT;

string S;
int cur,cll=0;
tree* parse() {
	string SS;
	int i;
	vector<int> vt;
	tree* pt=&T[NT++];
	
	vt.push_back(NT++);
	pt->di=cll;
	pt->ci=cur;
	pt->cl=pt->dl=0;
	while(cur<S.size()) {
		if(S[cur]=='(') {
			cur++;
			string TS=parse();
			int rep=0;
			while(cur<S.size() && S[cur]>='0' && S[cur]<='9') {
				rep=rep*10+S[cur]-'0';
				cur++;
			}
			FOR(i,rep) SS+=TS;
		}
		else if(S[cur]==')') {
			cur++;
			return vt;
		}
		else {
			pt->cl++;
			pt->dl++;
		}
	}
	return vt;
}

void solve() {
	int f,r,i,j,k,l,x,y,tx,ty,aa[5];
	
	cin>>B>>L>>N>>S;
	
	cur=0;
	T=parse();
	
	if(B<0) B+=N.size();
	cout << N.substr(B,L) << endl;
	
	return;
}


int main(int argc,char** argv){
	
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}
