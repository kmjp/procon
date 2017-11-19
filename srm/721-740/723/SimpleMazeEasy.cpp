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

class SimpleMazeEasy {
	public:
	int findSum(long long N) {
		ll mo=1000000007;
		ll ret=0;
		ll r6=((mo+1)/2)*((mo+1)/3)%mo;
		
		N%=mo;
		ret=(3*N)%mo*(3*N+1)%mo*(3*N+mo-1)%mo*r6%mo;
		ret+=4*(N)*(N+1)%mo*(N+mo-1)%mo*r6%mo;
		ret+=4*(N)*(7*N*N%mo+mo-1)%mo*r6%mo;
		
		
		
		return ret%mo*2*(N%mo)%mo*(N%mo)%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; int Arg1 = 16; verify_case(0, Arg1, findSum(Arg0)); }
	void test_case_1() { long long Arg0 = 3LL; int Arg1 = 4680; verify_case(1, Arg1, findSum(Arg0)); }
	void test_case_2() { long long Arg0 = 5LL; int Arg1 = 61000; verify_case(2, Arg1, findSum(Arg0)); }
	void test_case_3() { long long Arg0 = 12345LL; int Arg1 = 598011702; verify_case(3, Arg1, findSum(Arg0)); }
	void test_case_4() { long long Arg0 = 1000000000000LL; int Arg1 = 763641672; verify_case(4, Arg1, findSum(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SimpleMazeEasy ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

