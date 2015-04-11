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

class Similars {
	public:
	
	int mask(int v) {
		int mask=0;
		while(v) mask |= 1<<(v%10), v/=10;
		return mask;
	}
	
	int maxsim(int L, int R) {
		int num[1024]={};
		int ma=0,x,y;
		for(;L<=R;L++) num[mask(L)]++;
		FOR(x,1024) FOR(y,1024) {
			if(x==y && num[x]>1) ma=max(ma,__builtin_popcount(x));
			if(x!=y && num[x]>=1 && num[y]>=1 ) ma=max(ma,__builtin_popcount(x&y));
		}
		return ma;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 1; verify_case(0, Arg2, maxsim(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 99; int Arg2 = 2; verify_case(1, Arg2, maxsim(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 99; int Arg1 = 100; int Arg2 = 0; verify_case(2, Arg2, maxsim(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1000; int Arg1 = 1010; int Arg2 = 2; verify_case(3, Arg2, maxsim(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 444; int Arg1 = 454; int Arg2 = 2; verify_case(4, Arg2, maxsim(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Similars ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
