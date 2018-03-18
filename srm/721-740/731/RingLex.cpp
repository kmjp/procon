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

class RingLex {
	public:
	string getmin(string s) {
		vector<int> P={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
		
		string R="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
		int N=s.size();
		int i,j;
		FORR(p,P) if(p<N) {
			FOR(i,N) {
				string T;
				FOR(j,N) T+=s[(i+j*p)%N];
				R=min(R,T);
			}
		}
		return R;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "cba"; string Arg1 = "abc"; verify_case(0, Arg1, getmin(Arg0)); }
	void test_case_1() { string Arg0 = "acb"; string Arg1 = "abc"; verify_case(1, Arg1, getmin(Arg0)); }
	void test_case_2() { string Arg0 = "abacaba"; string Arg1 = "aaaabcb"; verify_case(2, Arg1, getmin(Arg0)); }
	void test_case_3() { string Arg0 = "aaabb"; string Arg1 = "aabab"; verify_case(3, Arg1, getmin(Arg0)); }
	void test_case_4() { string Arg0 = "azzzabbb"; string Arg1 = "abazabaz"; verify_case(4, Arg1, getmin(Arg0)); }
	void test_case_5() { string Arg0 = "abbaac"; string Arg1 = "aaaaaa"; verify_case(5, Arg1, getmin(Arg0)); }
	void test_case_6() { string Arg0 = "fsdifyhsoe"; string Arg1 = "dehifsfsoy"; verify_case(6, Arg1, getmin(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RingLex ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

