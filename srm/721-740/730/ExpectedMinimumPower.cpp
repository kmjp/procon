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

ll mo=1000000007;
ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

class ExpectedMinimumPower {
	public:
	int findExp(int n, int x) {
		ll ret=modpow(2,n);
		
		ll c=1;
		for(int i=0;i<x;i++) {
			ret=(ret+mo-c)%mo;
			c=c*n--%mo*modpow(i+1)%mo;
		}
		return ret*2%mo;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 2; verify_case(0, Arg2, findExp(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 8; verify_case(1, Arg2, findExp(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 14; verify_case(2, Arg2, findExp(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 4; int Arg2 = 1696; verify_case(3, Arg2, findExp(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000000000; int Arg1 = 1000000; int Arg2 = 799728241; verify_case(4, Arg2, findExp(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ExpectedMinimumPower ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

