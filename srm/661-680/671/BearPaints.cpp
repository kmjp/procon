#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class BearPaints {
	public:
	long long maxArea(int W, int H, long long M) {
		ll ma=0;
		for(int w=1;w<=W;w++) ma=max(ma,1LL*w*min((ll)H,M/w));
		return ma;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 5; long long Arg2 = 14LL; long long Arg3 = 12LL; verify_case(0, Arg3, maxArea(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 4; long long Arg2 = 10LL; long long Arg3 = 9LL; verify_case(1, Arg3, maxArea(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1000000; int Arg1 = 12345; long long Arg2 = 1000000000000LL; long long Arg3 = 12345000000LL; verify_case(2, Arg3, maxArea(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1000000; int Arg1 = 1000000; long long Arg2 = 720000000007LL; long long Arg3 = 720000000000LL; verify_case(3, Arg3, maxArea(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1000000; int Arg1 = 1000000; long long Arg2 = 999999999999LL; long long Arg3 = 999999000000LL; verify_case(4, Arg3, maxArea(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BearPaints ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
