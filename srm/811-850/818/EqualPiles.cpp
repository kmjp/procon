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

class EqualPiles {
	public:
	int equalize(int N, int M, int T) {
		int i;
		map<int,int> C;
		FOR(i,N) C[-(1+(1LL*i*i%M))]++;
		int ma=0;
		int over=0;
		FORR(a,C) {
			ma=max(ma,a.second+over);
			over=min(T,a.second+over);
		}
		return ma;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 12345678; int Arg2 = 0; int Arg3 = 1; verify_case(0, Arg3, equalize(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 1; int Arg2 = 0; int Arg3 = 10; verify_case(1, Arg3, equalize(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 12345678; int Arg2 = 3; int Arg3 = 4; verify_case(2, Arg3, equalize(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 4; int Arg3 = 6; verify_case(3, Arg3, equalize(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 100000; int Arg1 = 7; int Arg2 = 0; int Arg3 = 28572; verify_case(4, Arg3, equalize(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 100000; int Arg1 = 7; int Arg2 = 1; int Arg3 = 28573; verify_case(5, Arg3, equalize(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 100000; int Arg1 = 7; int Arg2 = 98765; int Arg3 = 100000; verify_case(6, Arg3, equalize(Arg0, Arg1, Arg2)); }
	void test_case_7() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 5; int Arg3 = 5; verify_case(7, Arg3, equalize(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EqualPiles ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

