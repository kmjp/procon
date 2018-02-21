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

double fact[51];

class ExpectedMinimumPowerDiv2 {
	public:
	double findExp(int n, int x) {
		
		int i;
		fact[0]=1;
		for(i=1;i<=50;i++) fact[i]=fact[i-1]*i;
		
		double ret=0;
		for(int i=1;i<=n;i++) {
			int cand=n-i;
			if(cand<x-1) continue;
			ret += pow(2,i) * (fact[cand]/(fact[cand-(x-1)]*fact[x-1]));
		}
		
		return ret/(fact[n]/(fact[x]*fact[n-x]));
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 4; double Arg2 = 2.0; verify_case(0, Arg2, findExp(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; double Arg2 = 2.6666666666666665; verify_case(1, Arg2, findExp(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 1; double Arg2 = 4.666666666666667; verify_case(2, Arg2, findExp(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 4; double Arg2 = 8.076190476190476; verify_case(3, Arg2, findExp(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 50; int Arg1 = 25; double Arg2 = 9.906688596554163; verify_case(4, Arg2, findExp(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 50; int Arg1 = 1; double Arg2 = 4.503599627370492E13; verify_case(5, Arg2, findExp(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ExpectedMinimumPowerDiv2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

