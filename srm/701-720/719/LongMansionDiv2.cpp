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

class LongMansionDiv2 {
	public:
	long long minimalTime(int M, vector <int> t) {
		ll tot=0,mi=1LL<<60;
		FORR(a,t) {
			tot+=a;
			mi=min(mi,(ll)a);
		}
		return tot+(M-1)*mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {1, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 6LL; verify_case(0, Arg2, minimalTime(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {3, 2, 4, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 17LL; verify_case(1, Arg2, minimalTime(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arr1[] = {3, 2, 5, 4, 2, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 32LL; verify_case(2, Arg2, minimalTime(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1000000000; int Arr1[] = {1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1000000000000LL; verify_case(3, Arg2, minimalTime(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1LL; verify_case(4, Arg2, minimalTime(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LongMansionDiv2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

