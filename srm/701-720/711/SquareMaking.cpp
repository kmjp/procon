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

class SquareMaking {
	public:
	int getMinimalPrice(int a, int b, int c, int d) {
		int mi=1<<30;
		for(int i=1;i<=1000000;i++) {
			mi=min(mi,abs(i-a)+abs(i-b)+abs(i-c)+abs(i-d));
		}
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 6; int Arg2 = 5; int Arg3 = 5; int Arg4 = 1; verify_case(0, Arg4, getMinimalPrice(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 1; int Arg2 = 5; int Arg3 = 4; int Arg4 = 4; verify_case(1, Arg4, getMinimalPrice(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 2017; int Arg1 = 2017; int Arg2 = 2017; int Arg3 = 2017; int Arg4 = 0; verify_case(2, Arg4, getMinimalPrice(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 705451; int Arg1 = 751563; int Arg2 = 608515; int Arg3 = 994713; int Arg4 = 432310; verify_case(3, Arg4, getMinimalPrice(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SquareMaking ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

