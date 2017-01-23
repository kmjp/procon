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

class ThreeIncreasing {
	public:
	int minEaten(int a, int b, int c) {
		int x,y,ret=1<<20;
		for(x=1;x<=a;x++) for(y=x+1;y<=min(b,c-1);y++) ret=min(ret,a-x+b-y);
		if(ret==1<<20) ret=-1;
		return ret;	
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 15; int Arg1 = 40; int Arg2 = 22; int Arg3 = 19; verify_case(0, Arg3, minEaten(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 6; int Arg2 = 6; int Arg3 = 2; verify_case(1, Arg3, minEaten(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 1; int Arg2 = 3000; int Arg3 = -1; verify_case(2, Arg3, minEaten(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 4; int Arg2 = 2; int Arg3 = -1; verify_case(3, Arg3, minEaten(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 6; int Arg3 = 3; verify_case(4, Arg3, minEaten(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 1; int Arg1 = 1234; int Arg2 = 3000; int Arg3 = 0; verify_case(5, Arg3, minEaten(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 2789; int Arg1 = 2400; int Arg2 = 1693; int Arg3 = 1806; verify_case(6, Arg3, minEaten(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ThreeIncreasing ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

