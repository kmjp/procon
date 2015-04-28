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

class ProblemSetsEasy {
	public:
	
	bool ok(int tar,int E, int EM, int M, int MH, int H) {
		if(tar>E) EM -= tar-E;
		if(EM<0) return false;
		if(tar>EM+M) MH -= tar-(EM+M);
		if(MH<0) return false;
		if(MH+H<tar) return false;
		return true;
	}
	
	int maxSets(int E, int EM, int M, int MH, int H) {
		for(int tar=200000;tar>=1;tar--) {
			if(ok(tar,E,EM,M,MH,H)) return tar;
		}
		return 0;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 2; int Arg4 = 2; int Arg5 = 3; verify_case(0, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 100; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; verify_case(1, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 657; int Arg1 = 657; int Arg2 = 657; int Arg3 = 657; int Arg4 = 657; int Arg5 = 1095; verify_case(2, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 3; int Arg3 = 4; int Arg4 = 5; int Arg5 = 3; verify_case(3, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 100000; int Arg1 = 100000; int Arg2 = 100000; int Arg3 = 100000; int Arg4 = 100000; int Arg5 = 166666; verify_case(4, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ProblemSetsEasy ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
