#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

class BannerWithNails {
	public:
	long long number(long long X) {
		if(X==0) return 1;
		if(X==1LL<<60) return 2;
		ll cur=3;
		ll step=1;
		ll a=1LL<<59;
		while(1) {
			if((X&(a-1))==0) {
				return cur+(X/a-1)/2;
			}
			cur+=step;
			step*=2;
			a/=2;
		}
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 0LL; long long Arg1 = 1LL; verify_case(0, Arg1, number(Arg0)); }
	void test_case_1() { long long Arg0 = 576460752303423488LL; long long Arg1 = 3LL; verify_case(1, Arg1, number(Arg0)); }
	void test_case_2() { long long Arg0 = 468374361246531584LL; long long Arg1 = 24LL; verify_case(2, Arg1, number(Arg0)); }
	void test_case_3() { long long Arg0 = 1152921504606846975LL; long long Arg1 = 1152921504606846977LL; verify_case(3, Arg1, number(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BannerWithNails ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

