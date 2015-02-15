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

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
int GETi() { int i;scanf("%d",&i); return i;}

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int T,N;
double P;
double Q[100001];
int X[100001],t[100001];
pair<int,pair<int,double> > E[1000001];
double TM[100001],TMm[100001];

void solve() {
	int f,r,i,j,k,l,x,y,tx,ty;
	
	cin>>T>>N>>P;
	FOR(i,N) cin>>E[i].second.second>>E[i].second.first>>E[i].first;
	sort(E,E+N);
	
	// TMå„ÇÃñáêî
	TM[1]=1-P;
	FOR(i,N) TM[1]+=P*E[i].second.second*E[i].second.first;
	j=0;
	for(i=2;i<=T;i++) {
		TM[i]=TM[i-1];
		while(j<N && E[j].first < i) {
			TM[i]-=P*E[j].second.second*E[j].second.first;
			TM[i]+=P*E[j].second.second;
			j++;
		}
	}
	
	TMm[0]=TM[0]=1;
	for(i=1;i<=T;i++) TMm[i]=TMm[i-1]*TM[i];
	
	double res=0;
	FOR(i,T) res += TMm[i];
	
	
	if(res>1e8) {
		int nu=0;
		while(res>1e8) res/=10.0,nu++;
		_P("%d",(int)res);
		FOR(i,nu) _P("0");
		_P("\n");
	}
	else {
		_P("%.8lf\n",res);
	}
	
	
}


int main(int argc,char** argv){
	
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}
