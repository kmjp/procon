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

class Decipherability {
	public:
	string check(string s, int K) {
		int L=s.size();
		int x,y;
		FOR(y,L) FOR(x,y) if(s[x]==s[y] && L!=K && y-x<=K) return "Uncertain";
		return "Certain";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "snuke"; int Arg1 = 2; string Arg2 = "Certain"; verify_case(0, Arg2, check(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "aba"; int Arg1 = 1; string Arg2 = "Certain"; verify_case(1, Arg2, check(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "aba"; int Arg1 = 2; string Arg2 = "Uncertain"; verify_case(2, Arg2, check(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "abcdabcd"; int Arg1 = 3; string Arg2 = "Certain"; verify_case(3, Arg2, check(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "koukyoukoukokukikou"; int Arg1 = 2; string Arg2 = "Uncertain"; verify_case(4, Arg2, check(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "wolfsothe"; int Arg1 = 8; string Arg2 = "Uncertain"; verify_case(5, Arg2, check(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "aa"; int Arg1 = 2; string Arg2 = "Certain"; verify_case(6, Arg2, check(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Decipherability ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
