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

int N,D;
vector< pair<int,int> > nums,nume;
int L[100000];
int R[100000];
ll nc[16][100000];

template<class V, int ME> class BIT {
public:
	V bit[ME];
	
	BIT(){clear();};
	void clear() {ZERO(bit);};
	
	V total(int entry) {
		V s=0;
		entry++;
		while(entry>0) {
			s+=bit[entry-1];
			entry -= entry & -entry;
		}
		s %= 314159265;
		return s;
	}
	void update(int entry, V val) {
		entry++;
		while(entry <= ME) {
			bit[entry-1] += val;
			bit[entry-1] %= 314159265;
			entry += entry & -entry;
		}
	}
};

BIT<ll,1<<17> bt;


void solve() {
	int x,y,i,j,p,rr,d,res;
	ll ret;
	
	nums.clear();
	nume.clear();
	N=GETi();
	D=GETi();
	
	FOR(i,N) {
		x=GETi();
		y=GETi();
		nums.push_back(make_pair(x,i));
		nume.push_back(make_pair(y,i));
	}
	
	ZERO(nc);
	sort(nums.begin(),nums.end());
	sort(nume.begin(),nume.end());
	FOR(i,nums.size()) {
		nc[1][i]++;
		L[nums[i].second]=i;
		R[nume[i].second]=nums.size()-1-i;
	}
	
	for(d=2;d<=D;d++) {
		ret = 0;
		bt.clear();
		FOR(i,nums.size()) {
			int id = nums[i].second;
			nc[d][id] = bt.total(R[id]);
			bt.update(R[id],nc[d-1][id]);
			ret+=nc[d][id];
		}
		ret %= 314159265;
	}
	
	_P("%lld\n",ret);
	return;
}

int main(int argc,char** argv){
	long long span;
	struct timeval start,end,ts;
	
	if(argc>1) {
		freopen(argv[1], "r", stdin);
	}
	
	gettimeofday(&start,NULL);
	solve();
	gettimeofday(&end,NULL);
	
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	//_E("**Total time: %lld ms\n",span/1000);
	
	return 0;
	
}

