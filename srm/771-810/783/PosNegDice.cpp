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

class PosNegDice {
	public:
	vector <int> evaluateRoll(int T, vector <int> positiveDice, vector <int> negativeDice) {
		int C[7]={};
		FORR(p,positiveDice) C[p]++;
		FORR(p,negativeDice) C[p]--;
		
		int X=0,Y=0;
		int i;
		for(i=1;i<=6;i++) {
			if(C[i]>0 && i<=T) X=1;
			if(C[i]<0) Y-=C[i];
		}
		return {X,Y};
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 1; int Arr1[] = {1, 6, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 0 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, evaluateRoll(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 0 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, evaluateRoll(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arr1[] = {5, 6, 6, 5, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 0 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, evaluateRoll(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arr1[] = {3, 6, 3, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 3, 1, 3, 6, 3, 5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 4 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, evaluateRoll(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 4; int Arr1[] = {4, 5, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 3 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, evaluateRoll(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PosNegDice ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

