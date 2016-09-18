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

int dp[51][51];
class RepeatStringEasy {
	public:
	
	int dodo(string S,string T) {
		int A=S.size(),B=T.size();
		int i,x,y,j,ret=0;
		ZERO(dp);
		FOR(i,A+1) FOR(j,B+1) {
			if(i<A && j<B) dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+(S[i]==T[j]));
			if(j<B) dp[i][j+1]=max(dp[i][j+1],dp[i][j]);
			if(i<A) dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			ret=max(ret,dp[i][j]);
		}
		
		return ret;
	}
	
	
	int maximalLength(string s) {
		int N=s.size();
		
		int ret=0;
		for(int i=0;i<=N;i++) ret=max(ret,dodo(s.substr(0,i),s.substr(i,N-i)));
		return ret*2;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "frankfurt"; int Arg1 = 4; verify_case(0, Arg1, maximalLength(Arg0)); }
	void test_case_1() { string Arg0 = "single"; int Arg1 = 0; verify_case(1, Arg1, maximalLength(Arg0)); }
	void test_case_2() { string Arg0 = "singing"; int Arg1 = 6; verify_case(2, Arg1, maximalLength(Arg0)); }
	void test_case_3() { string Arg0 = "aababbababbabbbbabbabb"; int Arg1 = 18; verify_case(3, Arg1, maximalLength(Arg0)); }
	void test_case_4() { string Arg0 = "x"; int Arg1 = 0; verify_case(4, Arg1, maximalLength(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RepeatStringEasy ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
