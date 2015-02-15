// –¢‰ñ“š

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


class SweetFruits {
	public:
	int N,nb;
	int M=1000000007;
	s64 NumTree(int nodes){
		return nodes;
	}
	
	int NT(int swn,int bn,int tbn) {
		int i;
		s64 res=0;
		
		s64 nt = NumTree(swn);
		res = nt;
		FOR(i,bn) { res = (res*swn)%M;}
		FOR(i,tbn) { res = (res*bn)%M;}
		
		return res%M;
		
	}
	
	int countTrees(vector <int> sweetness, int maxSweetness) {
		sort(sweetness.begin(),sweetness.end());
		N=sweetness.size();
		nb=0;
		int i;
		FOR(i,N) if(sweetness[i]==-1) nb++;
		if(nb==0) {
			s64 s=0;
			FOR(i,N) s+=sweetness[i];
			if(s>maxSweetness) return 0;
			return NumTree(N)%M;
		}
		
		_P("%d %d\n",N,nb);
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, -1, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 3; verify_case(0, Arg2, countTrees(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 2, -1, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 7; verify_case(1, Arg2, countTrees(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-1, -1, 2, 5, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 20; verify_case(2, Arg2, countTrees(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2, 6, 8, 4, 1, 10, -1, -1, -1, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; int Arg2 = 17024000; verify_case(3, Arg2, countTrees(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1078451, -1, 21580110, 8284711, -1, 4202301, 3427559, 8261270, -1, 16176713,
22915672, 24495540, 19236, 5477666, 12280316, 3305896, 17917887, 564911, 22190488, 21843923,
23389728, 14641920, 9590140, 12909561, 20405638, 100184, 23336457, 12780498, 18859535, 23180993,
10278898, 5753075, 21250919, 17563422, 10934412, 22557980, 24895749, 7593671, 10834579, 5606562}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 245243285; int Arg2 = 47225123; verify_case(4, Arg2, countTrees(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  SweetFruits ___test;
  ___test.run_test(-1);
}
// END CUT HERE
