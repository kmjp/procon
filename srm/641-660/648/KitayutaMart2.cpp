#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class KitayutaMart2 {
	public:
	int numBought(int K, int T) {
		return __builtin_popcount(T/K);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 1; verify_case(0, Arg2, numBought(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 300; int Arg2 = 2; verify_case(1, Arg2, numBought(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 150; int Arg1 = 1050; int Arg2 = 3; verify_case(2, Arg2, numBought(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 160; int Arg1 = 163680; int Arg2 = 10; verify_case(3, Arg2, numBought(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  KitayutaMart2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
