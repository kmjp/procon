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

class NamingConvention {
	public:
	string toCamelCase(string variableName) {
		int i;
		string s;
		FOR(i,variableName.size()) {
			if(variableName[i]=='_') {
				s+=variableName[i+1]+'A'-'a';
				i++;
			}
			else {
				s+=variableName[i];
			}
		}
		return s;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "sum_of_two_numbers"; string Arg1 = "sumOfTwoNumbers"; verify_case(0, Arg1, toCamelCase(Arg0)); }
	void test_case_1() { string Arg0 = "variable"; string Arg1 = "variable"; verify_case(1, Arg1, toCamelCase(Arg0)); }
	void test_case_2() { string Arg0 = "t_o_p_c_o_d_e_r"; string Arg1 = "tOPCODER"; verify_case(2, Arg1, toCamelCase(Arg0)); }
	void test_case_3() { string Arg0 = "the_variable_name_can_be_very_long_like_this"; string Arg1 = "theVariableNameCanBeVeryLongLikeThis"; verify_case(3, Arg1, toCamelCase(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  NamingConvention ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
