#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

char dp[40][40][40][950];

class ABC {
	public:
	string createString(int N, int K) {
		int i,a,b,x;
		ZERO(dp);
		dp[0][0][0][0]='A';
		
		FOR(i,N) {
			FOR(a,N+1) for(b=0;b<=N-a;b++) {
				FOR(x,948) if(dp[i][a][b][x]) {
					dp[i+1][a+1][b][x]='A';
					dp[i+1][a][b+1][x+a]='B';
					dp[i+1][a][b][x+a+b]='C';
				}
			}
		}
		
		FOR(a,N+1) for(b=0;b<=N-a;b++) if(dp[N][a][b][K]) {
			string s;
			while(N) {
				s+=dp[N][a][b][K];
				if(dp[N][a][b][K]=='A') a--;
				else if(dp[N][a][b][K]=='B') b--, K-=a;
				else K-=a+b;
				N--;
			}
			reverse(s.begin(),s.end());
			return s;
		}
		return "";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; string Arg2 = "ABC"; verify_case(0, Arg2, createString(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 0; string Arg2 = "CBA"; verify_case(1, Arg2, createString(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 10; string Arg2 = ""; verify_case(2, Arg2, createString(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 15; int Arg1 = 36; string Arg2 = "CABBACCBAABCBBB"; verify_case(3, Arg2, createString(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ABC ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
