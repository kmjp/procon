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

class PlusCastle {
	public:
	int maximiseClosedFigures(int k) {
		ll ma=0;
		int i,j;
		for(i=2;i*i<=k;i++) {
			j=k/i;
			ll pat=(i-1)*(j-1);
			if(k%i>=2) pat+=(k%i)-1;
			ma=max(ma,pat);
		}
		return ma;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 9; int Arg1 = 4; verify_case(0, Arg1, maximiseClosedFigures(Arg0)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 2; verify_case(1, Arg1, maximiseClosedFigures(Arg0)); }
	void test_case_2() { int Arg0 = 898680485; int Arg1 = 898620529; verify_case(2, Arg1, maximiseClosedFigures(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PlusCastle ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

