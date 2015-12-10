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

class LengthUnitCalculator {
	public:
	double calc(int amount, string fromUnit, string toUnit) {
		double a=amount;
		if(fromUnit=="mi") a*=1760*3*12;
		if(fromUnit=="yd") a*=3*12;
		if(fromUnit=="ft") a*=12;
		if(toUnit=="mi") a/=1760*3*12;
		if(toUnit=="yd") a/=3*12;
		if(toUnit=="ft") a/=12;
		return a;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; string Arg1 = "mi"; string Arg2 = "ft"; double Arg3 = 5280.0; verify_case(0, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; string Arg1 = "ft"; string Arg2 = "mi"; double Arg3 = 1.893939393939394E-4; verify_case(1, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 123; string Arg1 = "ft"; string Arg2 = "yd"; double Arg3 = 41.0; verify_case(2, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1000; string Arg1 = "mi"; string Arg2 = "in"; double Arg3 = 6.336E7; verify_case(3, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1; string Arg1 = "in"; string Arg2 = "mi"; double Arg3 = 1.5782828282828283E-5; verify_case(4, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 47; string Arg1 = "mi"; string Arg2 = "mi"; double Arg3 = 47.0; verify_case(5, Arg3, calc(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LengthUnitCalculator ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
