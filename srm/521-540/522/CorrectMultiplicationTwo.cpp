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
#include <numeric>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef signed long long ll;
typedef unsigned long long ull;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(x) x.begin(),x.end()
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

class CorrectMultiplicationTwo {
	public:
	int getMinimum(int a, int b, int c) {
		int mi=a+b+c;
		
		for(int a2=1;a2<=1000000;a2++) {
			for(int b2=c/a2-2;b2<=c/a2+2;b2++) {
				if(b2<1) continue;
				int c2=a2*b2;
				mi=min(mi,abs(a-a2)+abs(b-b2)+abs(c-c2));
			}
		}
		
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 19; int Arg1 = 28; int Arg2 = 522; int Arg3 = 2; verify_case(0, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 30; int Arg2 = 500; int Arg3 = 11; verify_case(1, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 111; int Arg1 = 111; int Arg2 = 12321; int Arg3 = 0; verify_case(2, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1000; int Arg1 = 100; int Arg2 = 10; int Arg3 = 1089; verify_case(3, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 399; int Arg1 = 522; int Arg2 = 199999; int Arg3 = 24; verify_case(4, Arg3, getMinimum(Arg0, Arg1, Arg2)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CorrectMultiplicationTwo ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

