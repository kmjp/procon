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

class UnclearNotes {
	public:
	string isMatch(string S, string T) {
		FORR(c,S) {
			if(c=='o') c='0';
			if(c=='l') c='1';
			if(c=='m') c='n';
			
		}
		FORR(c,T) {
			if(c=='o') c='0';
			if(c=='l') c='1';
			if(c=='m') c='n';
			
		}
		if(S==T) return "Possible";
		return "Impossible";
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "topc0der"; string Arg1 = "topcoder"; string Arg2 = "Possible"; verify_case(0, Arg2, isMatch(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "topcoder"; string Arg1 = "codertop"; string Arg2 = "Impossible"; verify_case(1, Arg2, isMatch(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "o0ol1lnmn"; string Arg1 = "oo0ll1nnm"; string Arg2 = "Possible"; verify_case(2, Arg2, isMatch(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "c01unn"; string Arg1 = "column"; string Arg2 = "Possible"; verify_case(3, Arg2, isMatch(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "0"; string Arg1 = "l"; string Arg2 = "Impossible"; verify_case(4, Arg2, isMatch(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "81vdiu0n50mxlxopqn8olxbqromvkral21nbi"; string Arg1 = "llv0i00p50nx1xs1qn1o13bqaomv0r152lmgi"; string Arg2 = "Impossible"; verify_case(5, Arg2, isMatch(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "nl91gn9lnnqpyo09ml1h140onnomoonr0ow24qfw0muf"; string Arg1 = "nl9lgn91nmqpy009ml1hl4o0nm0mo0nro0w24qfwonuf"; string Arg2 = "Possible"; verify_case(6, Arg2, isMatch(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  UnclearNotes ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

