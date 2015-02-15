#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

class IncrementingSequence {
	public:
	string canItBeDone(int k, vector <int> A) {
		int num[51];
		int i,L=A.size(),x;
		ZERO(num);
		FOR(i,L) num[A[i]]++;
		for(i=1;i<=L;i++) {
			for(x=1;x<=i;x++) {
				if(num[x] && (i-x)%k==0) {
					num[x]--;
					break;
				}
			}
			if(x>i) return "IMPOSSIBLE";
		}
		return "POSSIBLE";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {1,2,4,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "POSSIBLE"; verify_case(0, Arg2, canItBeDone(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "IMPOSSIBLE"; verify_case(1, Arg2, canItBeDone(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arr1[] = {1,1,1,1,1,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "POSSIBLE"; verify_case(2, Arg2, canItBeDone(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; int Arr1[] = {5,3,3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "IMPOSSIBLE"; verify_case(3, Arg2, canItBeDone(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 9; int Arr1[] = {1,2,3,1,4,5,6,7,9,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "POSSIBLE"; verify_case(4, Arg2, canItBeDone(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 2; int Arr1[] = {1,1,1,1,1,1,2,2,2,2,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "POSSIBLE"; verify_case(5, Arg2, canItBeDone(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 1; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "POSSIBLE"; verify_case(6, Arg2, canItBeDone(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE 
int main(int argc,char** argv) {
  IncrementingSequence ___test;
  if(argc==1)  ___test.run_test(-1);
  else  ___test.run_test(atoi(argv[1]));
}
