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

class TopXorerEasy {
	public:
	int maximalRating(int A, int B, int C) {
		vector <int> X={A,B,C};
		int N=X.size();
		int ret=0;
		int i,j;
		for(i=29;i>=0;i--) {
			int id=-1;
			FOR(j,N) {
				if(X[j]&(1<<i)) {
					if(id==-1 || X[id]<X[j]) id=j;
				}
			}
			if(id>=0) {
				ret |= 1<<i;
				X[id]^=1<<i;
				FOR(j,N) {
					if(X[j]&(1<<i)) {
						X[j]=(1<<i)-1;
					}
				}
			}
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 0; int Arg3 = 3; verify_case(0, Arg3, maximalRating(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 4; int Arg3 = 7; verify_case(1, Arg3, maximalRating(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 5; int Arg3 = 7; verify_case(2, Arg3, maximalRating(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 100; int Arg2 = 10000; int Arg3 = 10101; verify_case(3, Arg3, maximalRating(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1000000000; int Arg1 = 1000000000; int Arg2 = 1000000000; int Arg3 = 1073741823; verify_case(4, Arg3, maximalRating(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; verify_case(5, Arg3, maximalRating(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TopXorerEasy ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

