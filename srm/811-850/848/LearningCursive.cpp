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

class LearningCursive {
	public:
	vector <int> count(int N, int L, int D, string A, string B) {
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 12; int Arg1 = 1; int Arg2 = 1; string Arg3 = "b"; string Arg4 = "e"; int Arr5[] = {0, 3 }; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(0, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 1; string Arg3 = "ab"; string Arg4 = "ed"; int Arr5[] = {0, 10, 69, 57 }; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(1, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 2; string Arg3 = "ab"; string Arg4 = "ed"; int Arr5[] = {1769, 4904, 2372, 135 }; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(2, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 12; int Arg1 = 7; int Arg2 = 5; string Arg3 = "cabbaga"; string Arg4 = "cabbage"; int Arr5[] = {0, 0, 0, 0, 0, 0, 0, 0 }; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(3, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 2; int Arg1 = 10; int Arg2 = 3; string Arg3 = "a"; string Arg4 = "bbbbbbbbbb"; int Arr5[] = {183105, 39139485, 383960593 }; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(4, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LearningCursive ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

