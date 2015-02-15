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

class SparseFactorialDiv2 {
	public:
	ll func(ll val,ll div) {
		int rem[1000],nr=0;
		ll ret=0;
		ZERO(rem);
		
		for(ll k=0;k*k<=val;k++) {
			ll lo=k*k;
			retry:
			ll hi=min((k+1)*(k+1),val);
			
			ll tr=(k*k)%div;
			if(rem[tr]) {
				if((k+1)*(k+1)<=val) {
					k++;
					goto retry;
				}
			}
			else rem[tr]++,nr++;
			
			while(lo%div) ret-=rem[lo%div],lo--;
			while(hi%div) ret+=rem[hi%div],hi--;
			ret += (hi-lo)/div*nr;
		}
		return ret;
	}
	
	long long getCount(long long lo, long long hi, long long divisor) {
		return func(hi,divisor)-func(lo-1,divisor);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 4LL; long long Arg1 = 8LL; long long Arg2 = 3LL; long long Arg3 = 3LL; verify_case(0, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_1() { long long Arg0 = 9LL; long long Arg1 = 11LL; long long Arg2 = 7LL; long long Arg3 = 1LL; verify_case(1, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_2() { long long Arg0 = 1LL; long long Arg1 = 1000000000000LL; long long Arg2 = 2LL; long long Arg3 = 999999999999LL; verify_case(2, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_3() { long long Arg0 = 16LL; long long Arg1 = 26LL; long long Arg2 = 11LL; long long Arg3 = 4LL; verify_case(3, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_4() { long long Arg0 = 10000LL; long long Arg1 = 20000LL; long long Arg2 = 997LL; long long Arg3 = 1211LL; verify_case(4, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_52() { long long Arg0 = 123456789LL; long long Arg1 = 987654321LL; long long Arg2 = 71LL; long long Arg3 = 438184668LL; verify_case(5, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_5() { long long Arg0 = 298893793182LL; long long Arg1 = 784617505894LL; long long Arg2 = 967LL; long long Arg3 = 438184668LL; verify_case(5, Arg3, getCount(Arg0, Arg1, Arg2)); }
// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SparseFactorialDiv2 ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

