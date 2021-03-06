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

class QuadraticLaw {
	public:
	long long getTime(long long d) {
		ll c=0;
		for(int i=30;i>=0;i--) if((c+(1<<i))*(c+(1<<i)+1)<=d) c|=1<<i;
		return c;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 0LL; verify_case(0, Arg1, getTime(Arg0)); }
	void test_case_1() { long long Arg0 = 2LL; long long Arg1 = 1LL; verify_case(1, Arg1, getTime(Arg0)); }
	void test_case_2() { long long Arg0 = 5LL; long long Arg1 = 1LL; verify_case(2, Arg1, getTime(Arg0)); }
	void test_case_3() { long long Arg0 = 6LL; long long Arg1 = 2LL; verify_case(3, Arg1, getTime(Arg0)); }
	void test_case_4() { long long Arg0 = 7LL; long long Arg1 = 2LL; verify_case(4, Arg1, getTime(Arg0)); }
	void test_case_5() { long long Arg0 = 1482LL; long long Arg1 = 38LL; verify_case(5, Arg1, getTime(Arg0)); }
	void test_case_6() { long long Arg0 = 1000000000000000000LL; long long Arg1 = 999999999LL; verify_case(6, Arg1, getTime(Arg0)); }
	void test_case_7() { long long Arg0 = 31958809614643170LL; long long Arg1 = 178770270LL; verify_case(7, Arg1, getTime(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  QuadraticLaw ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
