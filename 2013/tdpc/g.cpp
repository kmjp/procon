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
#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
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

int L;
string S;
ll K;
ll sst[1000002];
vector<int> P[27];

ll dodo(int cur,ll A,string SS) {
	int c,l;
ret:
	if(cur>=L) return 0;
	FOR(c,26) {
		l = lower_bound(P[c].begin(),P[c].end(),cur) - P[c].begin();
		if(l<P[c].size()) {
			char cc = c + 'a';
			ll t = 1+sst[P[c][l]+1];
			if(A==1) {
				cout << SS << cc << endl;
				exit(0);
			}
			
			if(t>=A) {
				cur = P[c][l]+1;
				A--;
				SS += cc;
				goto ret;
				//return dodo(P[c][l]+1,A-1,SS + cc);
			}
			A -= t;
		}
	}
}

void solve() {
	int f,r,i,j,k,l, x,y,z;
	
	cin>>S>>K;
	L=S.size();
	FOR(i,L) P[S[i]-'a'].push_back(i);
	
	for(int cur=L-1;cur>=0;cur--) {
		int c,l;
		sst[cur]=0;
		FOR(c,26) {
			l = lower_bound(P[c].begin(),P[c].end(),cur) - P[c].begin();
			if(l<P[c].size()) {
				sst[cur] += 1+sst[P[c][l]+1];
				if(sst[cur]>1LL<<60) {
					sst[cur] = 1LL<<60;
					break;
				}
			}
		}
	}
	dodo(0,K,"");
	
	
	return _P("Eel\n");
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}


