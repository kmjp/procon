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

class BallsInBoxes {
	public:
	
	long long maxTurns(long long N, long long K) {
		ll cand = N-K+1;
		ll step = max(0LL, cand/K-1);
		cand -= step*K;
		
		for(int i=0;i<=60;i++) if(1LL<<i >= cand) return step+i;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 10LL; long long Arg1 = 10LL; long long Arg2 = 0LL; verify_case(0, Arg2, maxTurns(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 100LL; long long Arg1 = 1LL; long long Arg2 = 99LL; verify_case(1, Arg2, maxTurns(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 1000LL; long long Arg1 = 999LL; long long Arg2 = 1LL; verify_case(2, Arg2, maxTurns(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 10LL; long long Arg1 = 5LL; long long Arg2 = 3LL; verify_case(3, Arg2, maxTurns(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 6598161561689498LL; long long Arg1 = 16549496165LL; long long Arg2 = 3LL; verify_case(3, Arg2, maxTurns(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BallsInBoxes ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
