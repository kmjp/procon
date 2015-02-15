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

class PyramidSequences {
	public:
	long long distinctPairs(int N_, int M_) {
		ll N=N_, M=M_;
		ll G=__gcd(N-1,M-1);
		ll ret = (G-1) * ((N-1)/G) * ((M-1)/G) + ((1+(N-1)/G)*(1+(M-1)/G)+1)/2;
		
		return ret;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 4; long long Arg2 = 6LL; verify_case(0, Arg2, distinctPairs(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 5; long long Arg2 = 5LL; verify_case(1, Arg2, distinctPairs(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 43; int Arg1 = 76; long long Arg2 = 895LL; verify_case(2, Arg2, distinctPairs(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 1000000000; long long Arg2 = 1000000000LL; verify_case(3, Arg2, distinctPairs(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 100000; int Arg1 = 95555; long long Arg2 = 4777750000LL; verify_case(4, Arg2, distinctPairs(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PyramidSequences ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

