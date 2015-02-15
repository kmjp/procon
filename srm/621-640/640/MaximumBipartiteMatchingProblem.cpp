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

class MaximumBipartiteMatchingProblem {
	public:
	ll N1,N2,A,D;
	ll val(ll v) {
		if(v<D) return -1;
		if(A-v<D) return -1;
		return N1*v + (A-v)*(N2-v);
	}
	
	long long solve(int n1, int n2, int ans, int d) {
		N1=n1,N2=n2,A=ans,D=d;
		
		if(N1<N2) swap(N1,N2);
		if(N2==A) return N1*N2;
		if(A<2*D) return -1;
		ll ret=-1;
		ret=max(ret,val(0));
		ret=max(ret,val(D));
		ret=max(ret,val(A-D));
		ret=max(ret,val(N1));
		ret=max(ret,val(N2));
		ret=max(ret,val((A+N2-N1)/2));
		ret=max(ret,val((A+N2-N1)/2+1));
		
		
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 2; int Arg3 = 1; long long Arg4 = 5LL; verify_case(0, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 1; int Arg3 = 1; long long Arg4 = -1LL; verify_case(1, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 10; int Arg2 = 5; int Arg3 = 2; long long Arg4 = 50LL; verify_case(2, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 100000000; int Arg1 = 87654321; int Arg2 = 12345678; int Arg3 = 54321; long long Arg4 = 1233229491567444LL; verify_case(3, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 1000000000; int Arg1 = 1000000000; int Arg2 = 1000000000; int Arg3 = 1000000000; long long Arg4 = 1000000000000000000LL; verify_case(4, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MaximumBipartiteMatchingProblem ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
