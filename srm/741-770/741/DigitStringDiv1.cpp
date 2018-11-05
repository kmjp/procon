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

ll dp[50][3];

class DigitStringDiv1 {
	public:
	long long count(string S, int X) {
		string T=to_string(X);
		ZERO(dp);
		dp[0][1]=1;
		int i;
		
		FORR(c,S) {
			
			for(i=48;i>=0;i--) {
				if(i==0 && c=='0') continue;
				if(i>=T.size()) {
					dp[i+1][2]+=dp[i][0]+dp[i][1]+dp[i][2];
				}
				else {
					dp[i+1][0]+=dp[i][0];
					dp[i+1][2]+=dp[i][2];
					if(T[i]==c) dp[i+1][1]+=dp[i][1];
					if(T[i]<c) dp[i+1][2]+=dp[i][1];
					if(T[i]>c) dp[i+1][0]+=dp[i][1];
				}
			}
		}
		
		ll ret=0;
		for(i=T.size();i<=49;i++) ret+=dp[i][2];
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "0"; int Arg1 = 1; long long Arg2 = 0LL; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "101"; int Arg1 = 9; long long Arg2 = 3LL; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "471"; int Arg1 = 47; long long Arg2 = 2LL; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "2222"; int Arg1 = 97; long long Arg2 = 5LL; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DigitStringDiv1 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

