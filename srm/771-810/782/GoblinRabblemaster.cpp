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

class GoblinRabblemaster {
	public:
	long long totalDamage(int T) {
		ll ret=0;
		int A=0,B=0;
		int i;
		for(i=1;i<=T;i++) {
			A++;
			B+=A;
			ret+=1LL*(A-1)*(A+B)+B;
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; long long Arg1 = 1LL; verify_case(0, Arg1, totalDamage(Arg0)); }
	void test_case_1() { int Arg0 = 3; long long Arg1 = 33LL; verify_case(1, Arg1, totalDamage(Arg0)); }
	void test_case_2() { int Arg0 = 6; long long Arg1 = 336LL; verify_case(2, Arg1, totalDamage(Arg0)); }
	void test_case_3() { int Arg0 = 470; long long Arg1 = 6177551220LL; verify_case(3, Arg1, totalDamage(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  GoblinRabblemaster ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

