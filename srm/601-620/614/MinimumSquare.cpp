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

class MinimumSquare {
	int N;
	public:
	long long minArea(vector <int> x, vector <int> y, int K) {
		int i,j,k;
		ll ma=1LL<<62;
		N=x.size();
		
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
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; long long Arg3 = 81LL; verify_case(0, Arg3, minArea(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {-4, 3, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3 , -1, -2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; long long Arg3 = 16LL; verify_case(1, Arg3, minArea(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0, 0, 1, 1, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 0, 1, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; long long Arg3 = 9LL; verify_case(2, Arg3, minArea(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1000000000, 1000000000, 1000000000, -1000000000, -1000000000, -1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000000000, 0, -1000000000, 1000000000, 0, -1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; long long Arg3 = 4000000008000000004LL; verify_case(3, Arg3, minArea(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {-47881, 28623, 1769, -38328, -16737, 16653, -23181, 37360, 41429, 26282, 254, 728, 8299, -41080, -29498, 17488, -23937, -11, 33319, 25232}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-46462, 48985, -43820, -19587, -33593, -28337, 13667, -48131, -5568, -2332, -41918, -31370, -3695, 42599, -37788, -40096, 39049, 25045, -2122, 3874}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; long long Arg3 = 1695545329LL; verify_case(4, Arg3, minArea(Arg0, Arg1, Arg2)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MinimumSquare ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

