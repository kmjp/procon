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

#undef _P
#define _P(...) printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
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
int P[5005];
pair<int,int> PP[5005];
int dpdp[2][5002];

void solve() {
	int f,r,i,j,k,l, x,y;
	
	cin>>N;
	FOR(i,N) cin>>P[i];
	FOR(i,N) P[i]=abs(P[i]);
	FOR(i,N) PP[i]=make_pair(-P[i],i);
	sort(PP,PP+N);
	l=50000000;
	r=0;
	FOR(i,N+1) dpdp[0][i]=1<<30;
	dpdp[0][0]=0;
	
	FOR(i,N) {
		int cur=i%2,tar=(i+1)%2;
		int mi=0,pl=0;
		j=PP[i].second;
		FOR(x,N+1) dpdp[tar][x]=1<<30;
		
		FOR(x,j) if(P[x]<P[j]) mi++;
		for(x=j+1;x<N;x++) if(P[x]<P[j]) pl++;
		if(PP[i].first==l) {
			FOR(x,N+1) {
				dpdp[tar][x] = min(dpdp[tar][x], dpdp[cur][x]+x+mi);
				dpdp[tar][x+1] = min(dpdp[tar][x+1], dpdp[cur][x]+pl);
			}
		}
		else {
			
			FOR(x,N+1) {
				dpdp[tar][0] = min(dpdp[tar][0], dpdp[cur][x]+mi);
				dpdp[tar][1] = min(dpdp[tar][1], dpdp[cur][x]+pl);
			}
			l=PP[i].first;
		}
	}
	
	x=1<<30;
	FOR(y,N+1) x=min(x,dpdp[N%2][y]);
	cout << x << endl;
	
	return;
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}
