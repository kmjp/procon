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

/*
222334444433222
222334444433222
222334444433222
333446666644333
333446666644333
444668888866444
444668888866444
444668888866444
444668888866444
444668888866444
444668888866444
333446666644333
333446666644333
222334444433222
222334444433222
222334444433222
*/

class HyperKnight {
	public:
	long long res[9];
	long long countCells(int a, int b, int numRows, int numColumns, int k) {
		ll NR=min(numRows,numColumns);
		ll NC=max(numRows,numColumns);
		ll ma=min(a,b);
		ll mb=max(a,b);
		ll x,y;
		ZERO(res);
		
		res[8]=(NR-(2*mb))*(NC-(2*mb));
		res[6]=(NR-(2*mb))*2*(mb-ma) + (NC-(2*mb))*2*(mb-ma);
		res[4]=(NR-(2*mb))*2*ma + (NC-(2*mb))*2*ma;
		res[4]+=(mb-ma)*(mb-ma)*4;
		res[3]=ma*(mb-ma)*8;
		res[2]=ma*ma*4;
		
		return res[k];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 8; int Arg3 = 8; int Arg4 = 4; long long Arg5 = 20LL; verify_case(0, Arg5, countCells(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 8; int Arg3 = 8; int Arg4 = 2; long long Arg5 = 16LL; verify_case(1, Arg5, countCells(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 7; int Arg3 = 11; int Arg4 = 0; long long Arg5 = 0LL; verify_case(2, Arg5, countCells(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 10; int Arg3 = 20; int Arg4 = 8; long long Arg5 = 56LL; verify_case(3, Arg5, countCells(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 4; int Arg2 = 100; int Arg3 = 10; int Arg4 = 6; long long Arg5 = 564LL; verify_case(4, Arg5, countCells(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 1000000000; int Arg3 = 1000000000; int Arg4 = 8; long long Arg5 = 999999988000000036LL; verify_case(5, Arg5, countCells(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  HyperKnight ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
