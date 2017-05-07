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

class NAddOdd {
	public:
	int num(ll V,ll K) {
		int ret=0;
		while(V>K) {
			if(V&1) V=(V+K)/2, ret+=2;
			else V/=2, ret++;
		}
		return ret;
	}
	
	ll hoge(ll X,ll K) {
		if(X<=K) return 0;
		
		ll neven = X/2-K/2;
		ll nodd = X-K-neven;
		ll ret = neven + 2*nodd + 2*hoge(X/2,K);
		
		for(ll v=X/2+1; v<=(X+K)/2;v++) ret += num(v,K);
		return ret;
	}
	
	long long solve(long long L, long long R, int K) {
		return hoge(R,K)-hoge(L-1,K);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 5LL; long long Arg1 = 5LL; int Arg2 = 1; long long Arg3 = 5LL; verify_case(0, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_1() { long long Arg0 = 1LL; long long Arg1 = 99999LL; int Arg2 = 99999; long long Arg3 = 0LL; verify_case(1, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_2() { long long Arg0 = 16LL; long long Arg1 = 17LL; int Arg2 = 3; long long Arg3 = 9LL; verify_case(2, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_3() { long long Arg0 = 3LL; long long Arg1 = 7LL; int Arg2 = 5; long long Arg3 = 4LL; verify_case(3, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_4() { long long Arg0 = 1645805087361625LL; long long Arg1 = 9060129311830846LL; int Arg2 = 74935; long long Arg3 = 421014795656548226LL; verify_case(4, Arg3, solve(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  NAddOdd ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

