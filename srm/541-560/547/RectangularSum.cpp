#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

//-------------------------------------------------------

class RectangularSum {
	public:
	ll H,W;
	
	int okok(ll h,ll w,ll S) {
		ll mins = h*w*(w-1)/2 + W*w*h*(h-1)/2;
		ll st1=h*w;
		if((S-mins)%st1) return 0;
		ll momo=(S-mins)/st1;
		ll right=momo%W;
		ll down=momo/W;
		return (right<=W-w && down<=H-h);
	}
	long long minimalArea(int height, int width, long long S) {
		ll mi=1LL<<50;
		H=height;
		W=width;
		
		ll h,w;
		for(w=1;w<=W;w++) {
			for(h=1;h<=H;h++) {
				if(w*h>mi) break;
				ll mins = h*w*(w-1)/2 + W*w*h*(h-1)/2;
				if(mins>S) break;
				if(okok(h,w,S)) mi=h*w;
			}
		}
		
		if(mi==1LL<<50) return -1;
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 3; long long Arg2 = 8LL; long long Arg3 = 4LL; verify_case(0, Arg3, minimalArea(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; long long Arg2 = 10LL; long long Arg3 = -1LL; verify_case(1, Arg3, minimalArea(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; long long Arg2 = 36LL; long long Arg3 = 9LL; verify_case(2, Arg3, minimalArea(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 25; int Arg1 = 25; long long Arg2 = 16000LL; long long Arg3 = 32LL; verify_case(3, Arg3, minimalArea(Arg0, Arg1, Arg2)); }
	void test_case_42() { int Arg0 = 1000000; int Arg1 = 1000000; long long Arg2 = 1000000000000LL; long long Arg3 = 2LL; verify_case(4, Arg3, minimalArea(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 2; int Arg1 = 3; long long Arg2 = 4LL; long long Arg3 = 1LL; verify_case(4, Arg3, minimalArea(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RectangularSum ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
