#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class MojiDeletes {
	public:
	long long maximumXor(int N, int Q, int Base, int Add, int QBase, int QAdd) {
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 10; int Arg3 = 3; int Arg4 = 2; int Arg5 = 2; long long Arg6 = 37292LL; verify_case(0, Arg6, maximumXor(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 47; int Arg1 = 42; int Arg2 = 7654321; int Arg3 = 1234567; int Arg4 = 23; int Arg5 = 10; long long Arg6 = 41156782009LL; verify_case(1, Arg6, maximumXor(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 500000; int Arg1 = 500000; int Arg2 = 2; int Arg3 = 1; int Arg4 = 2; int Arg5 = 1; long long Arg6 = 534618713588573LL; verify_case(2, Arg6, maximumXor(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MojiDeletes ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

