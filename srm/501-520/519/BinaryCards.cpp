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

class BinaryCards {
	public:
	long long largestNumber(long long A, long long B) {
		ll ar=1,br=1;
		if(B==0) return 0;
		
		while(ar*2<=A) ar*=2;
		while(br*2<=B) br*=2;
		
		if(br!=ar) return br*2-1;
		return br+largestNumber(A-br,B-br);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 6LL; long long Arg1 = 6LL; long long Arg2 = 6LL; verify_case(0, Arg2, largestNumber(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 6LL; long long Arg1 = 7LL; long long Arg2 = 7LL; verify_case(1, Arg2, largestNumber(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 6LL; long long Arg1 = 8LL; long long Arg2 = 15LL; verify_case(2, Arg2, largestNumber(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 1LL; long long Arg1 = 11LL; long long Arg2 = 15LL; verify_case(3, Arg2, largestNumber(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 35LL; long long Arg1 = 38LL; long long Arg2 = 39LL; verify_case(4, Arg2, largestNumber(Arg0, Arg1)); }
	void test_case_5() { long long Arg0 = 1125899906842630LL; long long Arg1 = 1125899906842632LL; long long Arg2 = 1125899906842639LL; verify_case(5, Arg2, largestNumber(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BinaryCards ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

