#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


class WolfCardGame {
	public:
	
	vector <int> createAnswer(int N, int K) {
		int i,j;
		for(j=2;j<=6;j++) if(N%j!=0) {
			vector<int> V;
			FOR(i,K) V.push_back(j*(i+1));
			return V;
		}
		
		vector<int> V;
		V.push_back(1);
		FOR(i,K-1) V.push_back(7*(i+1));
		return V;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 20; int Arg1 = 4; int Arr2[] = {1, 2, 3, 4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, createAnswer(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 40; int Arg1 = 1; int Arr2[] = {39 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, createAnswer(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 97; int Arg1 = 6; int Arr2[] = {7, 68, 9, 10, 62, 58 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, createAnswer(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 12; int Arr2[] = {33, 69, 42, 45, 96, 15, 57, 12, 93, 9, 54, 99 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, createAnswer(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  WolfCardGame ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
