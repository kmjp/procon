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

class GoodString {
	public:
	string isGood(string s) {
		int numa=0;
		FORR(r,s) {
			if(r=='a') numa++;
			else {
				numa--;
				if(numa<0) return "Bad";
			}
		}
		if(numa==0) return "Good";
		return "Bad";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ab"; string Arg1 = "Good"; verify_case(0, Arg1, isGood(Arg0)); }
	void test_case_1() { string Arg0 = "aab"; string Arg1 = "Bad"; verify_case(1, Arg1, isGood(Arg0)); }
	void test_case_2() { string Arg0 = "aabb"; string Arg1 = "Good"; verify_case(2, Arg1, isGood(Arg0)); }
	void test_case_3() { string Arg0 = "ababab"; string Arg1 = "Good"; verify_case(3, Arg1, isGood(Arg0)); }
	void test_case_4() { string Arg0 = "abaababababbaabbaaaabaababaabbabaaabbbbbbbb"; string Arg1 = "Bad"; verify_case(4, Arg1, isGood(Arg0)); }
	void test_case_5() { string Arg0 = "aaaaaaaabbbaaabaaabbabababababaabbbbaabbabbbbbbabb"; string Arg1 = "Good"; verify_case(5, Arg1, isGood(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  GoodString ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
