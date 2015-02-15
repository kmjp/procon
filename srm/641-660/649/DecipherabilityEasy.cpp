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

class DecipherabilityEasy {
	public:
	string check(string s, string t) {
		int x=0,y;
		FOR(y,s.size()) if(s.substr(0,y)+s.substr(y+1)==t) return "Possible";
		return "Impossible";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "sunuke"; string Arg1 = "snuke"; string Arg2 = "Possible"; verify_case(0, Arg2, check(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "snuke"; string Arg1 = "skue"; string Arg2 = "Impossible"; verify_case(1, Arg2, check(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "snuke"; string Arg1 = "snuke"; string Arg2 = "Impossible"; verify_case(2, Arg2, check(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "snukent"; string Arg1 = "snuke"; string Arg2 = "Impossible"; verify_case(3, Arg2, check(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "aaaaa"; string Arg1 = "aaaa"; string Arg2 = "Possible"; verify_case(4, Arg2, check(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "aaaaa"; string Arg1 = "aaa"; string Arg2 = "Impossible"; verify_case(5, Arg2, check(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "topcoder"; string Arg1 = "tpcoder"; string Arg2 = "Possible"; verify_case(6, Arg2, check(Arg0, Arg1)); }
	void test_case_7() { string Arg0 = "singleroundmatch"; string Arg1 = "singeroundmatc"; string Arg2 = "Impossible"; verify_case(7, Arg2, check(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DecipherabilityEasy ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
