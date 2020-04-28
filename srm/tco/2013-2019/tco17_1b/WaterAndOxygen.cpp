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

class WaterAndOxygen {
	public:
	double maxDays(int remainH20, int remainO2, int costH2O, int costO2) {
		
		double L=0,R=1e10;
		int i;
		FOR(i,100) {
			double M=(L+R)/2;
			double needw=costH2O*M;
			if(needw>remainH20) {
				R=M;
				continue;
			}
			if(costO2*M>remainO2+(remainH20-needw)*0.5) {
				R=M;
			}
			else L=M;
		}
		return L;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 64; int Arg1 = 70; int Arg2 = 3; int Arg3 = 7; double Arg4 = 12.0; verify_case(0, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 99; int Arg1 = 102; int Arg2 = 1; int Arg3 = 1; double Arg4 = 99.0; verify_case(1, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 101; int Arg1 = 99; int Arg2 = 1; int Arg3 = 1; double Arg4 = 99.66666666666667; verify_case(2, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 123456789; int Arg1 = 987654321; int Arg2 = 123; int Arg3 = 456; double Arg4 = 1003713.731707317; verify_case(3, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 987654321; int Arg1 = 123456789; int Arg2 = 456; int Arg3 = 123; double Arg4 = 1758643.7307692308; verify_case(4, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 13; int Arg3 = 27; double Arg4 = 0.0; verify_case(5, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  WaterAndOxygen ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

