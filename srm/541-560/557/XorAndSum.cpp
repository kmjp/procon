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
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG
#ifdef DEBUG
#define DBG(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define DV(...) cerr << __VA_ARGS__ << endl
#else
#define DBG(...)
#define DV(...)
#endif

typedef signed long long s64;
typedef unsigned long long u64;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------


class XorAndSum {
	public:
	long long maxSum(vector<long long> number) {
		long long hv[50];
		int N = number.size();
		int i,j,dd,mx,rank;
		s64 res,v,mv,mb;
		
		rank=N;
		FOR(i,N) {
			hv[i]=0;
			sort(&number[i],&number[N]);
			reverse(&number[i],&number[N]);
			if(number[i]==0){
				rank=i;
				break;
			}
			v=1;
			while(v*2<=number[i]) v*=2;
			hv[i]=v;
			for(j=i+1;j<N;j++) if(number[j]&v) number[j]^=number[i];
		}
		
		// minimize
		for(i=rank-1;i>=0;i--) {
			FOR(j,i) if(number[j] & hv[i]) number[j] ^= number[i];
		}
		// maxmize
		for(i=1;i<rank;i++) number[0] ^= number[i];
		for(i=1;i<N;i++) number[i] ^= number[0];
		
		res = 0;
		FOR(i,N) res+=number[i];
		
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long Arr0[] = {1,0}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; verify_case(0, Arg1, maxSum(Arg0)); }
	void test_case_1() { long Arr0[] = {1,2,3}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 8LL; verify_case(1, Arg1, maxSum(Arg0)); }
	void test_case_2() { long Arr0[] = {0,0,0,0,0,0,0,0,0,0}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(2, Arg1, maxSum(Arg0)); }
	void test_case_3() { long Arr0[] = {2,3,5,7,11,13,17,19}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 233LL; verify_case(3, Arg1, maxSum(Arg0)); }
	void test_case_4() { long long Arr0[] = {123456789012345, 0, 0, 0, 0, 0, 0, 0, 0, 0}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1234567890123450LL; verify_case(4, Arg1, maxSum(Arg0)); }
	void test_case_5() { long Arr0[] = {627,674,281,272,289,877,62,122,603,189,615}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 10742LL; verify_case(5, Arg1, maxSum(Arg0)); }
	void test_case_6() { long Arr0[] = {557}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 557LL; verify_case(6, Arg1, maxSum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  XorAndSum ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
