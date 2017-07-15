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

ll dp[101][101];
ll mo=1000000007;

class InterleavingParenthesisDiv2 {
	public:
	int countWays(string s1, string s2) {
		int a=s1.size(),b=s2.size();
		vector<int> X,Y;
		X.push_back(0);
		Y.push_back(0);
		FORR(c,s1) X.push_back(X.back()+(c=='('));
		FORR(c,s2) Y.push_back(Y.back()+(c=='('));
		if((X.back()+Y.back())*2!=a+b) return 0;
		
		ZERO(dp);
		dp[0][0]=1;
		int i,j;
		FOR(i,a+1) FOR(j,b+1) {
			int num=(X[i]+Y[j])-((i+j)-(X[i]+Y[j]));
			if(i!=a) {
				if(s1[i]=='(' || num>0) (dp[i+1][j] += dp[i][j])%=mo;
			}
			if(j!=b) {
				if(s2[j]=='(' || num>0) (dp[i][j+1] += dp[i][j])%=mo;
			}
		}
		return dp[a][b];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "(()"; string Arg1 = "())"; int Arg2 = 19; verify_case(0, Arg2, countWays(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = ")"; string Arg1 = "("; int Arg2 = 1; verify_case(1, Arg2, countWays(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "((((("; string Arg1 = ")))))"; int Arg2 = 42; verify_case(2, Arg2, countWays(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "()(()"; string Arg1 = "))((())"; int Arg2 = 10; verify_case(3, Arg2, countWays(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "()()()()()()()()()()()()()()()"; string Arg1 = "()()()()()()()()"; int Arg2 = 493841617; verify_case(4, Arg2, countWays(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "())())))"; string Arg1 = "))(((("; int Arg2 = 0; verify_case(5, Arg2, countWays(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  InterleavingParenthesisDiv2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

