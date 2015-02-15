#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef signed long long ll;
typedef unsigned long long ull;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(x) x.begin(),x.end()
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

class MinimumSquareEasy {
	public:
	long long minArea(vector <int> x, vector <int> y) {
		int i,j,k;
		ll ma=1LL<<62;
		int N=x.size();
		int K=N-2;
		
		vector<ll> XX;
		FOR(i,N) XX.push_back(x[i]+1);
		FOR(i,N) XX.push_back(x[i]-1);
		
		sort(XX.begin(),XX.end());
		FOR(i,XX.size()) for(j=i+1;j<XX.size();j++) {
			ll L=XX[i];
			ll R=XX[j];
			vector<ll> YY;
			FOR(k,N) {
				if(L<x[k] && x[k]<R) YY.push_back(y[k]);
			}
			sort(YY.begin(),YY.end());
			for(k=0;k+K-1<YY.size();k++) {
				ll he=max(R-L,YY[k+K-1]-YY[k]+2);
				ma=min(ma,he*he);
			}
		}
		return ma;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 4LL; verify_case(0, Arg2, minArea(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-1, -1, 0, 2, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-2, -1, 0, -1, -2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 9LL; verify_case(1, Arg2, minArea(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1000000000, -1000000000, 1000000000, -1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000000000, 1000000000, -1000000000, -1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 4000000008000000004LL; verify_case(2, Arg2, minArea(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {93, 34, 12, -11, -7, -21, 51, -22, 59, 74, -19, 29, -56, -95, -96, 9, 44, -37, -54, -21}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {64, 12, -43, 20, 55, 74, -20, -54, 24, 20, -18, 77, 86, 22, 47, -24, -33, -57, 5, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 22801LL; verify_case(3, Arg2, minArea(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MinimumSquareEasy ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

