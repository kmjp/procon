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

class ProblemSets {
	public:
	bool ok(ll tar,ll E, ll EM, ll M, ll MH, ll H) {
		if(tar>E) EM -= tar-E;
		if(EM<0) return false;
		if(tar>EM+M) MH -= tar-(EM+M);
		if(MH<0) return false;
		if(MH+H<tar) return false;
		return true;
	}
	long long maxSets(long long E, long long EM, long long M, long long MH, long long H) {
		ll tar=0;
		int i;
		for(i=60;i>=0;i--) if(ok(tar+(1LL<<i),E,EM,M,MH,H)) tar += 1LL<<i;
		return tar;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 2LL; long long Arg1 = 2LL; long long Arg2 = 1LL; long long Arg3 = 2LL; long long Arg4 = 2LL; long long Arg5 = 3LL; verify_case(0, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { long long Arg0 = 100LL; long long Arg1 = 100LL; long long Arg2 = 100LL; long long Arg3 = 0LL; long long Arg4 = 0LL; long long Arg5 = 0LL; verify_case(1, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { long long Arg0 = 657LL; long long Arg1 = 657LL; long long Arg2 = 657LL; long long Arg3 = 657LL; long long Arg4 = 657LL; long long Arg5 = 1095LL; verify_case(2, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { long long Arg0 = 1LL; long long Arg1 = 2LL; long long Arg2 = 3LL; long long Arg3 = 4LL; long long Arg4 = 5LL; long long Arg5 = 3LL; verify_case(3, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { long long Arg0 = 1000000000000000000LL; long long Arg1 = 1000000000000000000LL; long long Arg2 = 1000000000000000000LL; long long Arg3 = 1000000000000000000LL; long long Arg4 = 1000000000000000000LL; long long Arg5 = 1666666666666666666LL; verify_case(4, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ProblemSets ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
