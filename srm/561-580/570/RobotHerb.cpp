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

#define DEBUG
#ifdef DEBUG
#define DBG(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define DV(...) cerr << __VA_ARGS__ << endl
#else
#define DBG(...)
#define DV(...)
#endif

typedef signed long long ll;
typedef unsigned long long ull;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------


class RobotHerb {
	public:
	long long getdist(int T, vector <int> a) {
		int i;
		ll rot=0,cr=0;
		ll x=0,y=0,tx,ty;
		
		FOR(i,a.size()) rot += a[i];
		FOR(i,a.size()) {
			if(cr==0) y+=a[i];
			if(cr==1) x+=a[i];
			if(cr==2) y-=a[i];
			if(cr==3) x-=a[i];
			cr+=a[i];
			cr%=4;
		}

		tx=x;ty=y;
		if(cr==0) {
			tx=x*T;
			ty=y*T;
		}
		else if(cr==1 || cr==3) {
			if(T%4==0) tx=ty=0;
			else if(T%2==0) {
				tx=x+y;
				ty=y-x;
			}
		}
		else if(cr==2) {
			if(T%2==0) tx=ty=0;
		}
		return abs(tx)+abs(ty);
	}
};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
