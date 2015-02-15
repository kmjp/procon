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

class SetMultiples {
	public:
	long long smallestSubset(long long A, long long B, long long C, long long D) {
		A=max(A,B/2+1);
		C=max(C,D/2+1);
		
		ll ret=D-C+1;
		while(A<=B) {
			if(D/A<2) {
				ret += B-A+1;
				break;
			}
			ll m=(C+(A-1))/A;
			
			if(m*A>D) {
				// out
				ll y=min(B+1,(C+(m-2))/(m-1));
				ret+=y-A;
				A=y;
			}
			else {
				A=min(B+1,D/m+1);
			}
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 1LL; long long Arg2 = 2LL; long long Arg3 = 2LL; long long Arg4 = 1LL; verify_case(0, Arg4, smallestSubset(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { long long Arg0 = 1LL; long long Arg1 = 2LL; long long Arg2 = 3LL; long long Arg3 = 4LL; long long Arg4 = 2LL; verify_case(1, Arg4, smallestSubset(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { long long Arg0 = 2LL; long long Arg1 = 3LL; long long Arg2 = 5LL; long long Arg3 = 7LL; long long Arg4 = 3LL; verify_case(2, Arg4, smallestSubset(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { long long Arg0 = 1LL; long long Arg1 = 10LL; long long Arg2 = 100LL; long long Arg3 = 1000LL; long long Arg4 = 500LL; verify_case(3, Arg4, smallestSubset(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { long long Arg0 = 1000000000LL; long long Arg1 = 2000000000LL; long long Arg2 = 9000000000LL; long long Arg3 = 10000000000LL; long long Arg4 = 1254365078LL; verify_case(4, Arg4, smallestSubset(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SetMultiples ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

