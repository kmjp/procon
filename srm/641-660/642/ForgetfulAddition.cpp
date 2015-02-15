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

class ForgetfulAddition {
	public:
	int minNumber(string e) {
		int i;
		int mi=1000000000;
		for(i=1;i<=e.size()-1;i++) mi=min(mi,atoi(e.substr(0,i).c_str())+atoi(e.substr(i).c_str()));
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "22"; int Arg1 = 4; verify_case(0, Arg1, minNumber(Arg0)); }
	void test_case_1() { string Arg0 = "123"; int Arg1 = 15; verify_case(1, Arg1, minNumber(Arg0)); }
	void test_case_2() { string Arg0 = "1289"; int Arg1 = 101; verify_case(2, Arg1, minNumber(Arg0)); }
	void test_case_3() { string Arg0 = "31415926"; int Arg1 = 9067; verify_case(3, Arg1, minNumber(Arg0)); }
	void test_case_4() { string Arg0 = "98765"; int Arg1 = 863; verify_case(4, Arg1, minNumber(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ForgetfulAddition ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
