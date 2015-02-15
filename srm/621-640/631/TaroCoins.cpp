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

class TaroCoins {
	public:
	
	map<pair<ll,int>,ll> M;
	ll dpdp(ll N,int bit) {
		
		if(N==0) return 1;
		if(N<0 || bit<0 || N>4LL<<bit) return 0;
		if(M.count(make_pair(N,bit))) return M[make_pair(N,bit)];
		return M[make_pair(N,bit)]=dpdp(N,bit-1)+dpdp(N-(1LL<<bit),bit-1)+dpdp(N-(2LL<<bit),bit-1);
	}
	
	long long getNumber(long long N) {
		M.clear();
		return dpdp(N,59);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 1LL; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { long long Arg0 = 6LL; long long Arg1 = 3LL; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { long long Arg0 = 47LL; long long Arg1 = 2LL; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { long long Arg0 = 256LL; long long Arg1 = 9LL; verify_case(3, Arg1, getNumber(Arg0)); }
	void test_case_4() { long long Arg0 = 8489289LL; long long Arg1 = 6853LL; verify_case(4, Arg1, getNumber(Arg0)); }
	void test_case_5() { long long Arg0 = 1000000000LL; long long Arg1 = 73411LL; verify_case(5, Arg1, getNumber(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TaroCoins ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
