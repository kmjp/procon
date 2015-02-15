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
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------


ll mask[61],mask2[61];

ll gause(int R) {
	int rank=0,i,x;
	ll mb;
	
	while(R>0) {
		sort(mask2,mask2+R);
		if(mask2[R-1]==0) break;
		if(mask2[R-1]==1) return -1;
		//_P("%d %d\n",R,rank);
		rank++;
		mb=1LL<<63;
		while((mask2[R-1] & mb)==0) mb>>=1;
		
		FOR(i,R-1) if(mask2[i]&mb) mask2[i] ^= mask2[R-1];
		R--;
	}
	return rank;
	
}

class XorCards {
	int N;
	public:
	long long numberOfWays(vector<long long> number, long long limit) {
		int i,j,bi;
		ll mask[60];
		N=number.size();
		sort(number.begin(),number.end());
		ll ret=0;
		
		ZERO(mask);
		FOR(i,N) FOR(bi,60) if(number[i] & (1LL<<bi)) mask[59-bi] |= 1LL<<(i+1);
		FOR(bi,60) if(limit & (1LL<<bi)) mask[59-bi] |= 1;
		
		FOR(bi,60) {
			if(mask[bi]&1) {
				FOR(i,60) mask2[i]=mask[i];
				mask2[bi]^=1;
				i = gause(bi+1);
				if(i>=0) ret += 1LL<<(N-i);
			}
		}
		FOR(i,60) mask2[i]=mask[i];
		i = gause(60);
		if(i>=0) ret += 1LL<<(N-i);
		
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arr0[] = {1,2}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; long long Arg2 = 3LL; verify_case(0, Arg2, numberOfWays(Arg0, Arg1)); }
	void test_case_1() { long long Arr0[] = {5,5}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 3LL; long long Arg2 = 2LL; verify_case(1, Arg2, numberOfWays(Arg0, Arg1)); }
	void test_case_2() { long long Arr0[] = {1,2,3,4,5,6,7}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 5LL; long long Arg2 = 96LL; verify_case(2, Arg2, numberOfWays(Arg0, Arg1)); }
	void test_case_3() { long long Arr0[] = {123, 456, 789, 147, 258, 369, 159, 357}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 500LL; long long Arg2 = 125LL; verify_case(3, Arg2, numberOfWays(Arg0, Arg1)); }
	void test_case_4() { long long Arr0[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1000000000000000LL; long long Arg2 = 4294967296LL; verify_case(4, Arg2, numberOfWays(Arg0, Arg1)); }
	void test_case_5() { long long Arr0[] = {1000000000000000LL, 999999999999999LL}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 65535LL; long long Arg2 = 2LL; verify_case(5, Arg2, numberOfWays(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  XorCards ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
