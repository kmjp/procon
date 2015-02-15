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

class FoxAndGCDLCM {
	public:
	long long get(long long G, long long L) {
		if(L%G) return -1;
		ll AB=L/G;
		ll ret=1LL<<50;
		for(ll a=1;a*a<=AB;a++) {
			if((AB%a)==0 && __gcd(a,AB/a)==1) ret=min(ret,G*(a+AB/a));
		}
		return ret;
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 2LL; long long Arg1 = 20LL; long long Arg2 = 14LL; verify_case(0, Arg2, get(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 5LL; long long Arg1 = 8LL; long long Arg2 = -1LL; verify_case(1, Arg2, get(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 1000LL; long long Arg1 = 100LL; long long Arg2 = -1LL; verify_case(2, Arg2, get(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 100LL; long long Arg1 = 1000LL; long long Arg2 = 700LL; verify_case(3, Arg2, get(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 10LL; long long Arg1 = 950863963000LL; long long Arg2 = 6298430LL; verify_case(4, Arg2, get(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FoxAndGCDLCM ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

