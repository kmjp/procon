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

class CorruptedMessage {
	public:
	string reconstructMessage(string s, int k) {
		int L=s.size();
		for(char x='a';x<='z';x++) {
			if(count(s.begin(),s.end(),x)+k==L) {
				ITR(r,s) *r=x;
				return s;
			}
		}
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "hello"; int Arg1 = 3; string Arg2 = "lllll"; verify_case(0, Arg2, reconstructMessage(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "abc"; int Arg1 = 3; string Arg2 = "ddd"; verify_case(1, Arg2, reconstructMessage(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "wwwwwwwwwwwwwwwwww"; int Arg1 = 0; string Arg2 = "wwwwwwwwwwwwwwwwww"; verify_case(2, Arg2, reconstructMessage(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ababba"; int Arg1 = 3; string Arg2 = "aaaaaa"; verify_case(3, Arg2, reconstructMessage(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "zoztxtoxytyt"; int Arg1 = 10; string Arg2 = "oooooooooooo"; verify_case(4, Arg2, reconstructMessage(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "jlmnmiunaxzywed"; int Arg1 = 13; string Arg2 = "mmmmmmmmmmmmmmm"; verify_case(5, Arg2, reconstructMessage(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CorruptedMessage ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
