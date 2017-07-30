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

ll dp[2020][4];
ll mo=1000000007;

class ConsecutivePalindromes {
	public:
	int countStrings(string S) {
		int N=S.size();
		int i,x,y;
		
		ZERO(dp);
		dp[0][0]=1;
		
		FOR(i,N) {
			// not take
			(dp[i+1][0]+=dp[i][0]+dp[i][1]+dp[i][2])%=mo;
			(dp[i+1][3]+=dp[i][3])%=mo;
			
			// take
			(dp[i+1][1]+=dp[i][0])%=mo;
			if(i && S[i]==S[i-1]) {
				(dp[i+1][3]+=dp[i][1])%=mo;
			}
			else {
				(dp[i+1][2]+=dp[i][1])%=mo;
			}
			if(i>=2 && S[i]==S[i-2]) {
				(dp[i+1][3]+=dp[i][2])%=mo;
			}
			else if(i && S[i]==S[i-1]) {
				(dp[i+1][3]+=dp[i][2])%=mo;
			}
			else {
				(dp[i+1][2]+=dp[i][2])%=mo;
			}
			(dp[i+1][3]+=dp[i][3])%=mo;
			
		}
		
		return dp[N][3];
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AAA"; int Arg1 = 3; verify_case(0, Arg1, countStrings(Arg0)); }
	void test_case_1() { string Arg0 = "ABCDEF"; int Arg1 = 0; verify_case(1, Arg1, countStrings(Arg0)); }
	void test_case_2() { string Arg0 = "BBAA"; int Arg1 = 7; verify_case(2, Arg1, countStrings(Arg0)); }
	void test_case_3() { string Arg0 = "ABCBA"; int Arg1 = 4; verify_case(3, Arg1, countStrings(Arg0)); }
	void test_case_4() { string Arg0 = "TOPPAPPOT"; int Arg1 = 240; verify_case(4, Arg1, countStrings(Arg0)); }
	void test_case_5() { string Arg0 = "AYUEOPPOLAKIKIKIUYOPZOOLPPPPKMOPOLIURKMQOAPLFKTURIWOOWWWPLOLWWWOPSLAA"; int Arg1 = 216072426; verify_case(5, Arg1, countStrings(Arg0)); }
	void test_case_6() { string Arg0 = "Z"; int Arg1 = 0; verify_case(6, Arg1, countStrings(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ConsecutivePalindromes ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

