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

class DoubleOrOneEasy {
	public:
	int minimalSteps(int a, int b, int newA, int newB) {
		int mi=1<<30,i;
		
		for(int k=0;k<=30;k++) {
			if((ll)(b-a)<<k==(newB-newA)) {
				int x=newA, t=0;
				FOR(i,k) {
					if(x%2) x--, t++;
					x/=2, t++;
				}
				if(x>=a) mi=min(mi,t+x-a);
			}
		}
		
		
		if(mi>=1<<30) return -1;
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 100; int Arg1 = 1000; int Arg2 = 101; int Arg3 = 1001; int Arg4 = 1; verify_case(0, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 1000; int Arg2 = 202; int Arg3 = 2002; int Arg4 = 2; verify_case(1, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 1; int Arg4 = -1; verify_case(2, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 111111111; int Arg2 = 8; int Arg3 = 888888888; int Arg4 = 3; verify_case(3, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 111111111; int Arg2 = 9; int Arg3 = 999999999; int Arg4 = -1; verify_case(4, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DoubleOrOneEasy ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
