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

class DividingCandy {
	public:
	long long divide(long long C, long long L, long long D) {
		ll ret=1LL<<60;
		
		int i;
		if(L) {
			for(i=1;i<=100000;i++) {
				ll lef=C-i*L;
				if(D&&i==1) continue;
				if(lef<D) continue;
				if(lef>=D*(i-1)) {
					ret=min(ret,lef-D*(i-1));
				}
				else {
					ret=min(ret,lef%D);
				}
			}
		}
		else {
			for(i=1;i<=100000;i++) if(D*i<=C) ret=min(ret,C-i*D);
		}
		
		
		if(ret==1LL<<60) ret=-1;
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 80LL; long long Arg1 = 10LL; long long Arg2 = 10LL; long long Arg3 = 0LL; verify_case(0, Arg3, divide(Arg0, Arg1, Arg2)); }
	void test_case_1() { long long Arg0 = 27LL; long long Arg1 = 20LL; long long Arg2 = 10LL; long long Arg3 = -1LL; verify_case(1, Arg3, divide(Arg0, Arg1, Arg2)); }
	void test_case_2() { long long Arg0 = 1234LL; long long Arg1 = 15LL; long long Arg2 = 55LL; long long Arg3 = 4LL; verify_case(2, Arg3, divide(Arg0, Arg1, Arg2)); }
	void test_case_3() { long long Arg0 = 1LL; long long Arg1 = 1LL; long long Arg2 = 0LL; long long Arg3 = 0LL; verify_case(3, Arg3, divide(Arg0, Arg1, Arg2)); }
	void test_case_4() { long long Arg0 = 9876543210LL; long long Arg1 = 0LL; long long Arg2 = 2LL; long long Arg3 = 9876343210LL; verify_case(4, Arg3, divide(Arg0, Arg1, Arg2)); }
	void test_case_5() { long long Arg0 = 1234567LL; long long Arg1 = 2323LL; long long Arg2 = 4747LL; long long Arg3 = 44LL; verify_case(5, Arg3, divide(Arg0, Arg1, Arg2)); }
	void test_case_6() { long long Arg0 = 200001LL; long long Arg1 = 1LL; long long Arg2 = 1LL; long long Arg3 = 2LL; verify_case(6, Arg3, divide(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DividingCandy ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

