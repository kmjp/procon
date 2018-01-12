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

int dp[303][303][303];

class ManageSubsequences {
	public:
	
	int minAdded(string S, string A, string B) {
		int LS=S.size();
		int LA=A.size();
		int LB=B.size();
		int s,a,b;
		FOR(s,LS+1) FOR(a,LA+1) FOR(b,LB+1) dp[s][a][b]=1010;
		dp[0][0][0]=0;
		
		int mi=1010;
		
		FOR(s,LS+1) FOR(a,LA+1) FOR(b,LB) if(dp[s][a][b]<1010) {
			if(a==LA && s==LS) {
				mi=min(mi,dp[s][a][b]);
				continue;
			}
			
			// take s
			if(s<LS) {
				int aa=a+(a<LA && S[s]==A[a]);
				int bb=b+(S[s]==B[b]);
				dp[s+1][aa][bb]=min(dp[s+1][aa][bb],dp[s][a][b]);
			}
			// take a
			if(a<LA) {
				int ss=s+(s<LS && S[s]==A[a]);
				int bb=b+(A[a]==B[b]);
				dp[ss][a+1][bb]=min(dp[ss][a+1][bb],dp[s][a][b]+1);
			}
		}
			
		
		if(mi==1010) mi=-1;
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABXBCA"; string Arg1 = "ABCD"; string Arg2 = "XD"; int Arg3 = 2; verify_case(0, Arg3, minAdded(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "BXC"; string Arg1 = "BOCZ"; string Arg2 = "DSFHDS"; int Arg3 = 2; verify_case(1, Arg3, minAdded(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "BXC"; string Arg1 = "BOCZ"; string Arg2 = "BZ"; int Arg3 = -1; verify_case(2, Arg3, minAdded(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "ABC"; string Arg1 = "CDE"; string Arg2 = "ABCE"; int Arg3 = 3; verify_case(3, Arg3, minAdded(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "BANANA"; string Arg1 = "APPLE"; string Arg2 = "ANNA"; int Arg3 = -1; verify_case(4, Arg3, minAdded(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "BANANA"; string Arg1 = "ANANAS"; string Arg2 = "BS"; int Arg3 = 6; verify_case(5, Arg3, minAdded(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arg0 = "BANANA"; string Arg1 = "ANANAS"; string Arg2 = "BNNS"; int Arg3 = 3; verify_case(6, Arg3, minAdded(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ManageSubsequences ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

