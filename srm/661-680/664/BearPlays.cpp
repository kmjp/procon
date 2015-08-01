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

ll mo;
ll modpow(ll a, ll n) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

class BearPlays {
	public:
	int pileSize(int A, int B, int K) {
		mo=A+B;
		C=A*modpow(2,K)%mo;
		return min(C,T-C);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 7; int Arg2 = 2; int Arg3 = 5; verify_case(0, Arg3, pileSize(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 3; int Arg3 = 0; verify_case(1, Arg3, pileSize(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 6; int Arg2 = 1; int Arg3 = 4; verify_case(2, Arg3, pileSize(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 8; int Arg2 = 2000000000; int Arg3 = 2; verify_case(3, Arg3, pileSize(Arg0, Arg1, Arg2)); }
	//void test_case_4() { int Arg0 = 900000000; int Arg1 = 350000000; int Arg2 = 3; int Arg3 = 300000000; verify_case(4, Arg3, pileSize(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 797264985; int Arg1 = 7918469; int Arg2 = 500000000; int Arg3 = 300000000; verify_case(4, Arg3, pileSize(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BearPlays ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
