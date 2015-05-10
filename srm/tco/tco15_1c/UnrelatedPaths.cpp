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

class UnrelatedPaths {
	public:
	int maxUnrelatedPaths(vector <int> parent) {
		int i,N=parent.size()+1;
		int hc[52]={};
		
		for(i=N-1;i>=1;i--) hc[parent[i-1]] = 1;
		int ret=0;
		FOR(i,N) ret += 1-hc[i];
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 1, 1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, maxUnrelatedPaths(Arg0)); }
	void test_case_1() { int Arr0[] = {0, 0, 1, 1, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, maxUnrelatedPaths(Arg0)); }
	void test_case_2() { int Arr0[] = {0, 1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, maxUnrelatedPaths(Arg0)); }
	void test_case_3() { int Arr0[] = {0,1,1,2,2,2,4,6,5,0,10,5,12,12,10,4,16,12,5,3,20,12,11,21,9,5,1,20,15,24,6,8,15}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; verify_case(3, Arg1, maxUnrelatedPaths(Arg0)); }
	void test_case_4() { int Arr0[] = {0,1,1,1,1,0,2,5,1,6,7,10,5,10,8,5,16,14,8,14,4,14,15,21,0,24,11,1,9,18,13,20,6,28,19,28,14,11,38,26,25,10,23,43}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(4, Arg1, maxUnrelatedPaths(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  UnrelatedPaths ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
