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

typedef signed long long s64;
typedef unsigned long long u64;

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

int mo=555555555;
int Com[3001][3001];

class XorBoard {
	s64 res;
	int rc,cc;
	int hh,ww;
	public:
	
	s64 Co(int n,int m) {
		return Com[n][m];
		
	}
	
	s64 Ha(int n,int m) {
		return Co(n+m-1,m);
	}
	
	
	void add(int y,int x) {
		int ty,tx;
		s64 cy,cx,r;
		
		if(y>rc || x>cc) return;
		if((rc-y)%2==1) return;
		if((cc-x)%2==1) return;
		ty = (rc-y)/2;
		tx = (cc-x)/2;
		r = 1;
		r *= Co(hh,y);
		r %= mo;
		r *= Co(ww,x);
		r %= mo;
		r *= Ha(hh,ty);
		r %= mo;
		r *= Ha(ww,tx);
		r %= mo;
		res += r;
		res %= mo;
	}
	
	int count(int H, int W, int Rcount, int Ccount, int S) {
		int tr,tc;
		int y,x,n,m;
		hh=H; ww=W;
		ZERO(Com);
		Com[0][0]=1;
		
		FOR(n,3000) {
			if(n==0) continue;
			FOR(m,n+1) {
				if(m==0) Com[n][m]=1;
				else Com[n][m]=(Com[n-1][m-1]+Com[n-1][m])%mo;
			}
		}
		
		
		rc=Rcount;
		cc=Ccount;
		tr = min(H,Rcount);
		tc = min(W,Ccount);
		res = 0;
		FOR(y,tr+1) {
			int num = S - W*y;
			if(2*y==H) {
				if(num!=0) continue;
				FOR(x,tc+1) {
					if (x >= 0 && x <= W)add(y,x);
				}
			}
			else {
				if(num % (H-2*y) == 0) {
					x = num / (H-2*y);
					if (x >= 0 && x <= W) add(y,x);
				}
			}
		}
		return (int)res;
	
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 2; int Arg4 = 4; int Arg5 = 4; verify_case(0, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 0; int Arg3 = 0; int Arg4 = 1; int Arg5 = 0; verify_case(1, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 20; int Arg2 = 50; int Arg3 = 40; int Arg4 = 200; int Arg5 = 333759825; verify_case(2, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 1200; int Arg1 = 1000; int Arg2 = 800; int Arg3 = 600; int Arg4 = 4000; int Arg5 = 96859710; verify_case(3, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }
//	void test_case_4() { int Arg0 = 555; int Arg1 = 555; int Arg2 = 555; int Arg3 = 555; int Arg4 = 5550; int Arg5 = 549361755; verify_case(4, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 1554; int Arg1 = 1554; int Arg2 = 1555; int Arg3 = 1555; int Arg4 = 1207458; int Arg5 = 394435170; verify_case(4, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }
// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  XorBoard ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
