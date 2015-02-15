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

class NumbersChallenge {
	public:
	int MinNumber(vector <int> S) {
		set<int> SS;
		int N=S.size(),i,mask;
		FOR(mask,1<<N) {
			int tot=0;
			FOR(i,N) if(mask&(1<<i)) tot+=S[i];
			SS.insert(tot);
		}
		for(i=1;;i++) if(SS.find(i)==SS.end()) return i;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, MinNumber(Arg0)); }
	void test_case_1() { int Arr0[] = {2, 1, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(1, Arg1, MinNumber(Arg0)); }
	void test_case_2() { int Arr0[] = {2, 1, 2, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(2, Arg1, MinNumber(Arg0)); }
	void test_case_3() { int Arr0[] = {94512, 2, 87654, 81316, 6, 5, 6, 37151, 6, 139, 1, 36, 307, 1, 377, 101, 8, 37, 58, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1092; verify_case(3, Arg1, MinNumber(Arg0)); }
	void test_case_4() { int Arr0[] = {883, 66392, 3531, 28257, 1, 14131, 57, 1, 25, 88474, 4, 1, 110, 6, 1769, 220, 442, 7064, 7, 13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 56523; verify_case(4, Arg1, MinNumber(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE 
int main(int argc,char** argv) {
  NumbersChallenge ___test;
  if(argc==1)  ___test.run_test(-1);
  else  ___test.run_test(atoi(argv[1]));
}
