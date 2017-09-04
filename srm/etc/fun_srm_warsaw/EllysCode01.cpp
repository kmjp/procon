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

class EllysCode01 {
	public:
	
	ll F(ll v) {
		if((v&(v-1))==0) return v/2;
		ll a=1;
		while(a*2<=v) a*=2;
		return a/2+(v-a-F(v-a));
	}
	
	long long getOnes(long long L, long long R) {
		return F(R+1)-F(L);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 5LL; long long Arg1 = 15LL; long long Arg2 = 5LL; verify_case(0, Arg2, getOnes(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 101LL; long long Arg1 = 185LL; long long Arg2 = 42LL; verify_case(1, Arg2, getOnes(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 0LL; long long Arg1 = 0LL; long long Arg2 = 0LL; verify_case(2, Arg2, getOnes(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 1LL; long long Arg1 = 1LL; long long Arg2 = 1LL; verify_case(3, Arg2, getOnes(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 1337LL; long long Arg1 = 1337LL; long long Arg2 = 0LL; verify_case(4, Arg2, getOnes(Arg0, Arg1)); }
	void test_case_5() { long long Arg0 = 12345LL; long long Arg1 = 67890LL; long long Arg2 = 27772LL; verify_case(5, Arg2, getOnes(Arg0, Arg1)); }
	void test_case_6() { long long Arg0 = 5192834871235435LL; long long Arg1 = 954971273487212547LL; long long Arg2 = 474889219307988557LL; verify_case(6, Arg2, getOnes(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysCode01 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

