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

class NonDeterministicSubstring {
	public:
	long long ways(string A, string B) {
		set<string> S;
		int LA=A.size();
		int LB=B.size();
		int x,y;
		for(x=0;x+LB<=LA;x++) {
			int ok=1;
			FOR(y,LB) if(A[x+y]!=B[y] && B[y]!='?') ok=0;
			if(ok) S.insert(A.substr(x,LB));
		}
		return S.size();
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "00010001"; string Arg1 = "??"; long long Arg2 = 3LL; verify_case(0, Arg2, ways(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "00000000"; string Arg1 = "??0??0"; long long Arg2 = 1LL; verify_case(1, Arg2, ways(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "001010101100010111010"; string Arg1 = "???"; long long Arg2 = 8LL; verify_case(2, Arg2, ways(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "00101"; string Arg1 = "??????"; long long Arg2 = 0LL; verify_case(3, Arg2, ways(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "1101010101111010101011111111110001010101"; string Arg1 = "???????????????????????????????????"; long long Arg2 = 6LL; verify_case(4, Arg2, ways(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  NonDeterministicSubstring ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
