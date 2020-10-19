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

class TableTennisGame {
	public:
	vector <int> finalScore(int A, int B) {
		if(A<B) swap(A,B);
		if(A+B>=20) {
			if(A!=B) return {};
			return {(A+B)/2+1,(A+B)/2-1};
		}
		else {
			if(A+B<11) return {};
			if(A%2&&B%2) return {};
			if(B>A||A>B+2) return {};
			return {11,A+B-11};
		}
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 8; int Arg1 = 6; int Arr2[] = {11, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, finalScore(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 8; int Arr2[] = {11, 4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, finalScore(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 13; int Arg1 = 13; int Arr2[] = {14, 12 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, finalScore(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 3; int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, finalScore(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 2; int Arg1 = 100; int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, finalScore(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TableTennisGame ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

