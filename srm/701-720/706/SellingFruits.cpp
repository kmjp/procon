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

class SellingFruits {
	public:
	int maxDays(int x, int f, int d, int p) {
		ll ret=0;
		int i;
		for(int i=31;i>=0;i--) if((d-max(0LL,(ret+(1LL<<i))-f)*p)/x>=ret + (1LL<<i)) ret += 1LL<<i;
		return (int)ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 100; int Arg3 = 10; int Arg4 = 11; verify_case(0, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 17; int Arg2 = 20; int Arg3 = 1; int Arg4 = 10; verify_case(1, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 97; int Arg2 = 98; int Arg3 = 1; int Arg4 = 97; verify_case(2, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 16; int Arg1 = 4; int Arg2 = 8; int Arg3 = 2; int Arg4 = 0; verify_case(3, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 17; int Arg1 = 1; int Arg2 = 2000000000; int Arg3 = 4; int Arg4 = 95238095; verify_case(4, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 1; int Arg1 = 1996245611; int Arg2 = 1999990159; int Arg3 = 123; int Arg4 = 1996275808; verify_case(5, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arg0 = 15000000; int Arg1 = 100; int Arg2 = 2000000000; int Arg3 = 1; int Arg4 = 133; verify_case(6, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_7() { int Arg0 = 1; int Arg1 = 1000000000; int Arg2 = 2000000000; int Arg3 = 1000000000; int Arg4 = 1000000000; verify_case(7, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SellingFruits ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

