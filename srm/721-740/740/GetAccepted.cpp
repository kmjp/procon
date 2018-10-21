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

class GetAccepted {
	public:
	string answer(string question) {
		string T="Do you want to get accepted?";
		int num=(question.size()-T.size())/4;
		if(num%2) return "False.";
		return "True.";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "Do you want to get accepted?"; string Arg1 = "True."; verify_case(0, Arg1, answer(Arg0)); }
	void test_case_1() { string Arg0 = "Do you not want to get accepted?"; string Arg1 = "False."; verify_case(1, Arg1, answer(Arg0)); }
	void test_case_2() { string Arg0 = "Do you want to not get accepted?"; string Arg1 = "False."; verify_case(2, Arg1, answer(Arg0)); }
	void test_case_3() { string Arg0 = "Do you want to get not not accepted?"; string Arg1 = "True."; verify_case(3, Arg1, answer(Arg0)); }
	void test_case_4() { string Arg0 = "Do you not want to not get not not not accepted?"; string Arg1 = "False."; verify_case(4, Arg1, answer(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  GetAccepted ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

