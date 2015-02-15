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

class CatchTheBeatEasy {
	public:
	string ableToCatchAll(vector <int> x, vector <int> y) {
		int c=0,t=0,i;
		pair<int,int> P[51];
		
		FOR(i,x.size()) P[i]=make_pair(y[i],x[i]);
		sort(P,P+x.size());
		
		FOR(i,x.size()) {
			if(P[i].first-c<abs(P[i].second-t)) return "Not able to catch";
			c=P[i].first;
			t=P[i].second;
		}
		return "Able to catch";
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1, 1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Able to catch"; verify_case(0, Arg2, ableToCatchAll(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Not able to catch"; verify_case(1, Arg2, ableToCatchAll(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-1, 1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Not able to catch"; verify_case(2, Arg2, ableToCatchAll(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0, -1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9, 1, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Able to catch"; verify_case(3, Arg2, ableToCatchAll(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {70,-108,52,-70,84,-29,66,-33}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {141,299,402,280,28,363,427,232}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Not able to catch"; verify_case(4, Arg2, ableToCatchAll(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {-175,-28,-207,-29,-43,-183,-175,-112,-183,-31,-25,-66,-114,-116,-66}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {320,107,379,72,126,445,318,255,445,62,52,184,247,245,185}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Able to catch"; verify_case(5, Arg2, ableToCatchAll(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Able to catch"; verify_case(6, Arg2, ableToCatchAll(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE 
int main(int argc,char** argv) {
  CatchTheBeatEasy ___test;
  if(argc==1)  ___test.run_test(-1);
  else  ___test.run_test(atoi(argv[1]));
}
