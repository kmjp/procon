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

class PrimeWithSubstring {
	public:
	bool isprime(ll v) {
		for(ll i=2;i*i<=v;i++) if(v%i==0) return false;
		return (v!=1);
	}

	long long findPrime(int N) {
		int i;
		if(N==0) return 103;
		FOR(i,10) {
			ll v=1LL*N*10+i;
			if(isprime(v)) return v;
		}
		FOR(i,100) {
			ll v=1LL*N*100+i;
			if(isprime(v)) return v;
		}
		FOR(i,1000) {
			ll v=1LL*N*1000+i;
			if(isprime(v)) return v;
		}
		return 0;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 47; long long Arg1 = 47LL; verify_case(0, Arg1, findPrime(Arg0)); }
	void test_case_1() { int Arg0 = 42; long long Arg1 = 15427LL; verify_case(1, Arg1, findPrime(Arg0)); }
	void test_case_2() { int Arg0 = 0; long long Arg1 = 4021LL; verify_case(2, Arg1, findPrime(Arg0)); }
	void test_case_3() { int Arg0 = 123456789; long long Arg1 = 312345678971LL; verify_case(3, Arg1, findPrime(Arg0)); }
	void test_case_4() { int Arg0 = 111; long long Arg1 = 2111LL; verify_case(4, Arg1, findPrime(Arg0)); }
	void test_case_5() { int Arg0 = 1000000000; long long Arg1 = 100000000003LL; verify_case(5, Arg1, findPrime(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PrimeWithSubstring ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

