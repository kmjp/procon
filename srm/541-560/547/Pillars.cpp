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


class Pillars {
	public:
	public:
	double len[100001];
	double getExpectedLength(int w, int x, int y) {
		int i,z;
		double tl;
		s64 tn,W,I;
		
		W=w;
		len[0]=sqrt(W*W);
		FOR(i,100000) {
			if(i>0) {
				I=i;
				len[i]=len[i-1] + sqrt(W*W+I*I);
			}
		}
		
		if(x>y) {
			z=x;
			x=y;
			y=z;
		}
		tn=0;tl=0;
		for(i=1;i<=x;i++) {
			tl += len[y-i];
			tn += y-i+1;
			
			tl += len[i-1];
			tl -= len[0];
			tn += i-1;
		}
		return tl/tn;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr.precision(15); cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	//void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; double Arg3 = 1.0; verify_case(0, Arg3, getExpectedLength(Arg0, Arg1, Arg2)); }
	void test_case_0() { int Arg0 = 1000; int Arg1 = 100000; int Arg2 = 100000; double Arg3 = 33381.38304701605; verify_case(0, Arg3, getExpectedLength(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 1; double Arg3 = 2.387132965131785; verify_case(1, Arg3, getExpectedLength(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 15; double Arg3 = 6.737191281760445; verify_case(2, Arg3, getExpectedLength(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 15; int Arg2 = 23; double Arg3 = 12.988608956320535; verify_case(3, Arg3, getExpectedLength(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  Pillars ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
