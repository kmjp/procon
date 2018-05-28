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

int dp[1010][2];
ll mo=1000000007;
class WordAndPhraseDiv1 {
	public:
	int findNumberOfPhrases(string w) {
		
		ZERO(dp);
		int i;
		dp[0][1]=1;
		FOR(i,w.size()) {
			if(w[i]>='a' && w[i]<='z') {
				dp[i+1][0]=(dp[i][0]+dp[i][1])%mo;
			}
			else if(w[i]>='0' && w[i]<='9') {
				dp[i+1][0]=dp[i][0];
			}
			else {
				// same
				dp[i+1][0]=(dp[i][0]+dp[i][1])%mo;
				// conv
				dp[i+1][1]=dp[i][0];
			}
		}
		return dp[w.size()][0];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "tco_topcoder_com"; int Arg1 = 4; verify_case(0, Arg1, findNumberOfPhrases(Arg0)); }
	void test_case_1() { string Arg0 = "tcotopcodercom"; int Arg1 = 1; verify_case(1, Arg1, findNumberOfPhrases(Arg0)); }
	void test_case_2() { string Arg0 = "_tco18_admin_id_is_secret"; int Arg1 = 16; verify_case(2, Arg1, findNumberOfPhrases(Arg0)); }
	void test_case_3() { string Arg0 = "____"; int Arg1 = 3; verify_case(3, Arg1, findNumberOfPhrases(Arg0)); }
	void test_case_4() { string Arg0 = "a0_a1_a2_a3_a4_a5_a6_a7_a8_a9_a0_a1_a2_a3_a4_a5_a6_a7_a8_a9_a0_a1_a2_a3_a4_a5_a6_a7_a8_a9_a0"; int Arg1 = 73741817; verify_case(4, Arg1, findNumberOfPhrases(Arg0)); }
	void test_case_5() { string Arg0 = "d0_0b"; int Arg1 = 1; verify_case(5, Arg1, findNumberOfPhrases(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  WordAndPhraseDiv1 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

