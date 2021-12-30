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

class NailingABanner {
	public:
	long long coordinate(long long N) {
		if(N==1) return 0;
		if(N==2) return 1LL<<60;
		N-=2;
		ll a=1LL<<59;
		ll num=1;
		while(1) {
			
			if(N<=num) {
				return (2*N-1)*a;
			}
			else {
				N-=num;
				num*=2;
				a/=2;
			}
		}
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 0LL; verify_case(0, Arg1, coordinate(Arg0)); }
	void test_case_1() { long long Arg0 = 3LL; long long Arg1 = 576460752303423488LL; verify_case(1, Arg1, coordinate(Arg0)); }
	void test_case_2() { long long Arg0 = 4LL; long long Arg1 = 288230376151711744LL; verify_case(2, Arg1, coordinate(Arg0)); }
	void test_case_3() { long long Arg0 = 24LL; long long Arg1 = 468374361246531584LL; verify_case(3, Arg1, coordinate(Arg0)); }
	void test_case_4() { long long Arg0 = 65537LL; long long Arg1 = 1152903912420802560LL; verify_case(4, Arg1, coordinate(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  NailingABanner ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

