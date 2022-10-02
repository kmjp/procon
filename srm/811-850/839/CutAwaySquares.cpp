#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

class CutAwaySquares {
	public:
	long long countCuts(long long A, long long B) {
		ll num=0;
		while(1) {
			if(A%B==0) {
				num+=A/B-1;
				break;
			}
			num+=A/B;
			A=A%B;
			swap(A,B);
		}
		return num;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 47LL; long long Arg1 = 47LL; long long Arg2 = 0LL; verify_case(0, Arg2, countCuts(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 5LL; long long Arg1 = 10LL; long long Arg2 = 1LL; verify_case(1, Arg2, countCuts(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 20LL; long long Arg1 = 2LL; long long Arg2 = 9LL; verify_case(2, Arg2, countCuts(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 42LL; long long Arg1 = 22LL; long long Arg2 = 11LL; verify_case(3, Arg2, countCuts(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 20000000000000LL; long long Arg1 = 2000000000000LL; long long Arg2 = 9LL; verify_case(4, Arg2, countCuts(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CutAwaySquares ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

