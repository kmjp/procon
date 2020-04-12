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

class CardboardBoxes {
	public:
	ll hoge(ll x,ll y) {
		return min(x/2,y-1);
	}
	
	long long count(long long S) {
		if(S%2) return 0;
		S/=2;
		ll ret=0;
		for(ll a=1;a*a<=S;a++) if(S%a==0) {
			ret+=hoge(a,S/a);
			if(a!=S/a) ret+=hoge(S/a,a);
		}
		
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 47LL; long long Arg1 = 0LL; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { long long Arg0 = 470LL; long long Arg1 = 6LL; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2_() { long long Arg0 = 4700LL; long long Arg1 = 106LL; verify_case(2, Arg1, count(Arg0)); }
	void test_case_2() { long long Arg0 = 128LL; long long Arg1 = 106LL; verify_case(2, Arg1, count(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CardboardBoxes ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

