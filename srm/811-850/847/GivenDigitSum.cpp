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

class GivenDigitSum {
	public:
	long long construct(int D, int S) {
		string T=string(D,'0');
		S--;
		T[0]++;
		
		for(int i=D-1;i>=0;i--) if(i!=1) {
			while(S&&T[i]!='9') S--,T[i]++;
		}
		if(S) return -1;
		if(D==1) return -1;
		return atoll(T.c_str());
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 7; long long Arg2 = -1LL; verify_case(0, Arg2, construct(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 11; long long Arg2 = 209LL; verify_case(1, Arg2, construct(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 18; int Arg1 = 1; long long Arg2 = 100000000000000000LL; verify_case(2, Arg2, construct(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 11; int Arg1 = 11; long long Arg2 = 10000000019LL; verify_case(3, Arg2, construct(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 3; int Arg1 = 99; long long Arg2 = -1LL; verify_case(4, Arg2, construct(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 2; int Arg1 = 7; long long Arg2 = 70LL; verify_case(5, Arg2, construct(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  GivenDigitSum ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

