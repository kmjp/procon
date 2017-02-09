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

ll mo=1000000007;
ll douts[3030][3030];

class PalindromicSubseq2 {
	public:
	int solve(string S) {
		int N=S.size();
		int i,d,j;
		
		ZERO(douts);
		
		FOR(i,N+2) douts[0][i]=douts[i][N+1]=1;
		for(d=N;d>=1;d--) {
			for(i=1;i+d-1<=N;i++) {
				int j=i+d-1;
				ll ret=douts[i-1][j] + douts[i][j+1] - douts[i-1][j+1] + mo;
				if(S[i-1]==S[j-1]) ret += douts[i-1][j+1];
				douts[i][j]=(ret+mo)%mo;
			}
		}
		
		ll ret=0;
		FOR(i,N) ret ^= 1LL*(i+1)*douts[i][i+2]%mo;
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "axbcba"; int Arg1 = 31; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { string Arg0 = "eeeee"; int Arg1 = 14; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { string Arg0 = "tcoct"; int Arg1 = 4; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { string Arg0 = "zyzyzzzzxzyz"; int Arg1 = 221; verify_case(3, Arg1, solve(Arg0)); }
	void test_case_4() { string Arg0 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; int Arg1 = 1044407608; verify_case(4, Arg1, solve(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PalindromicSubseq2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

