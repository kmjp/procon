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

class Drbalance {
	public:
	int lesscng(string s, int k) {
		int cnt=0;
		while(1) {
			int neg=0;
			int cur=0;
			FORR(r,s) {
				if(r=='+') cur++;
				else cur--;
				if(cur<0) neg++;
			}
			if(neg<=k) return cnt;
			cnt++;
			FORR(r,s) if(r=='-') {
				r='+';
				break;
			}
		}
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "---"; int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, lesscng(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "+-+-"; int Arg1 = 0; int Arg2 = 0; verify_case(1, Arg2, lesscng(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "-+-+---"; int Arg1 = 2; int Arg2 = 1; verify_case(2, Arg2, lesscng(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "-------++"; int Arg1 = 3; int Arg2 = 3; verify_case(3, Arg2, lesscng(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "-+--+--+--++++----+"; int Arg1 = 3; int Arg2 = 2; verify_case(4, Arg2, lesscng(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Drbalance ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
