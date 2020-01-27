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

double F[1010101];
double G[1010101];

class StringRings {
	public:
	double expectedRings(int A, int B) {
		int i;
		for(i=1;i<=A;i++) F[i]=((F[i-1]+1)+(F[i-1])*2*(i-1))/(2*i-1);
		for(i=1;i<=B;i++) G[i]=((G[i-1]+1)+(G[i-1])*(2*A+i-1))/(2*A+i);
		return F[A]+G[B];
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 1; double Arg2 = 1.0; verify_case(0, Arg2, expectedRings(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 0; double Arg2 = 1.0; verify_case(1, Arg2, expectedRings(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 2; double Arg2 = 1.5833333333333333; verify_case(2, Arg2, expectedRings(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 0; double Arg2 = 0.0; verify_case(3, Arg2, expectedRings(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 2; int Arg1 = 3; double Arg2 = 1.8428571428571427; verify_case(4, Arg2, expectedRings(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  StringRings ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

