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

ll dp[2020][2020][2];
ll mo=1000000007;

class WolfHockeyTeamEasy {
	public:
	int count(int N, int K) {
		ZERO(dp);
		dp[2*N][1][1]=2*N;
		int i,l,o;
		for(i=2*N-1;i>=1;i--) {
			FOR(o,2) FOR(l,2*N) if(dp[i+1][l][o]) {
				int did=2*N-i;
				int blank=N-(did+l)/2;
				if (o==1) { // 1 row is empty
					// fill existing column
					if(l && i>K) (dp[i][l-1][0] += dp[i+1][l][1])%=mo;
					// start new column
					if(blank) {
						// same row
						(dp[i][l+1][1] += dp[i+1][l][1]*blank)%=mo;
						// new row
						if(i>K) (dp[i][l+1][0] += dp[i+1][l][1]*blank)%=mo;
						
					}
				}
				else { // both row has entries
					// fill existing column
					if(l) (dp[i][l-1][0] += dp[i+1][l][0])%=mo;
					// start new column
					if(blank) (dp[i][l+1][0] += dp[i+1][l][0]*blank)%=mo;
				}
			}
		}
		return dp[1][0][0];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 0; int Arg2 = 12; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 5; int Arg2 = 1104; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 120; int Arg2 = 803057135; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 234; int Arg1 = 467; int Arg2 = 0; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 810; int Arg1 = 893; int Arg2 = 281618909; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  WolfHockeyTeamEasy ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
