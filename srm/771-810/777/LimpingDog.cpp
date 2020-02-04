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

class LimpingDog {
	public:
	int countSteps(int time) {
		
		int i=0,j;
		int step=0;
		while(1) {
			FOR(j,47) {
				if(step%4==2) i+=2;
				else i++;
				step++;
				if(i==time) return step;
				else if(i>time) return step-1;
			}
			i+=42;
			if(i>=time) return step;
		}
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; verify_case(0, Arg1, countSteps(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; verify_case(1, Arg1, countSteps(Arg0)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 5; verify_case(2, Arg1, countSteps(Arg0)); }
	void test_case_3() { int Arg0 = 80; int Arg1 = 47; verify_case(3, Arg1, countSteps(Arg0)); }
	void test_case_4() { int Arg0 = 104; int Arg1 = 50; verify_case(4, Arg1, countSteps(Arg0)); }
	void test_case_5() { int Arg0 = 806000; int Arg1 = 376000; verify_case(5, Arg1, countSteps(Arg0)); }
	void test_case_6() { int Arg0 = 54321; int Arg1 = 25346; verify_case(6, Arg1, countSteps(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LimpingDog ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

